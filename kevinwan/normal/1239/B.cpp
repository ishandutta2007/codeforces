#include<bits/stdc++.h>
using namespace std;
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
mt19937_64 rngll(rng());
typedef long long ll;
typedef long double ld;
typedef pair<int,int>pii;
typedef pair<int,ll>pil;
typedef pair<ll,ll>pll;
typedef pair<double,double>pdd;
typedef pair<ld,ld>pld;
const int mn=3e5+10;
const ll mod=1e9+7;
int h[mn];
int main(){
    int n;
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin>>n;
    string s;
    cin>>s;
    s=" "+s;
    int ans=0,l,r;
    int lo=0,p=0;
    for(int i=1;i<=n;i++){
        h[i]=h[i-1]-1;
        if(s[i]=='(')h[i]+=2;
        if(h[i]<lo)lo=h[i],p=i;
    }
    if(h[n]){
        printf("0\n1 1");
        return 0;
    }
    string t=" ";
    for(int i=p+1;i<=n;i++)t.push_back(s[i]);
    for(int i=1;i<=p;i++)t.push_back(s[i]);
    s=t;
    for(int i=1;i<=n;i++){
        h[i]=h[i-1]-1;
        if(s[i]=='(')h[i]+=2;
        if(h[i]==0)ans++;
    }
    int ori=ans;
    l=r=1;
    int num1=0xc0c0c0c0,cl=-1;
    for(int i=1;i<=n;i++){
        if(h[i]==1&&s[i]=='('){
            num1=0,cl=i;
        }
        if(h[i]==1){
            num1++;
        }
        if(h[i]==0&&s[i]==')'){
            if(num1>ans)ans=num1,l=cl,r=i;
            num1=0xc0c0c0c0;
        }
    }
    num1=0xc0c0c0c0;
    for(int i=1;i<=n;i++){
        if(h[i]==2&&s[i]=='('){
            num1=0,cl=i;
        }
        if(h[i]==2)num1++;
        if(h[i]==1&&s[i]==')'){
            if(num1+ori>ans)ans=num1+ori,l=cl,r=i;
            num1=0xc0c0c0c0;
        }
    }
    l+=p,r+=p,l%=n,r%=n;
    if(l==0)l+=n;
    if(r==0)r+=n;
    printf("%d\n%d %d",ans,l,r);
}