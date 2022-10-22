#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef pair<ll,ll>pll;
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
const int mn=1e6+10;
const ll inf=0x3f3f3f3f3f3f3f3f;
const ll p1=1e9+7,p2=1e9+9;
ll po1[mn],po2[mn];
ll h1[mn],h2[mn],rh1[mn],rh2[mn];
const ll m=rng();
int n;
bool pal(int l,int r){
    if(l<=0||r>n)return 0;
    ll a=(h1[r]-h1[l-1]*po1[r-l+1])%p1+p1;
    ll b=(h2[r]-h2[l-1]*po2[r-l+1])%p2+p2;
    ll c=(rh1[l]-rh1[r+1]*po1[r-l+1])%p1+p1;
    ll d=(rh2[l]-rh2[r+1]*po2[r-l+1])%p2+p2;
    return (a%p1==c%p1)&&(d%p2==b%p2);
}
int main(){
    int tc;
    po1[0]=po2[0]=1;
    for(int i=1;i<mn;i++)po1[i]=po1[i-1]*m%p1,po2[i]=po2[i-1]*m%p2;
    scanf("%d",&tc);
    while(tc--){
        string s;
        cin>>s;
        n=s.size();
        for(int i=0;i<=n+1;i++)h1[i]=h2[i]=rh1[i]=rh2[i]=0;
        s=" "+s;
        for(int i=1;i<=n;i++)h1[i]=(h1[i-1]*m+s[i])%p1,h2[i]=(h2[i-1]*m+s[i])%p2;
        for(int i=n;i;i--)rh1[i]=(rh1[i+1]*m+s[i])%p1,rh2[i]=(rh2[i+1]*m+s[i])%p2;
        int fr=0;
        for(int i=0;i<n;i++){
            if(s[1+i]==s[n-i])fr++;
            else break;
        }
        if(fr==n){
            printf("%s\n",s.c_str()+1);
            continue;
        }
        int bes=fr*2,pl=2,pr=1,ee=fr;
        for(int i=1;i<=n;i++){
            int cur=0;
            for(int j=1<<18;j;j>>=1){
                if(pal(i-cur-j,i+cur+j))cur+=j;
            }
            int l=i-cur,r=i+cur;
            int ex=min(min(l-1,n-r),fr);
            if(ex+1!=l&&n-ex!=r)continue;
            int len=r-l+1+2*ex;
            if(len>bes){
                pl=l,pr=r,ee=ex,bes=len;
            }
        }
        for(int i=1;i<n;i++){
            int cur=-1;
            for(int j=1<<18;j;j>>=1){
                if(pal(i-cur-j,i+1+cur+j))cur+=j;
            }
            int l=i-cur,r=i+1+cur;
            int ex=min(min(l-1,n-r),fr);
            if(ex+1!=l&&n-ex!=r)continue;
            int len=r-l+1+2*ex;
            if(len>bes){
                pl=l,pr=r,ee=ex,bes=len;
            }
        }
        for(int i=1;i<=ee;i++)printf("%c",s[i]);
        for(int i=pl;i<=pr;i++)printf("%c",s[i]);
        for(int i=n+1-ee;i<=n;i++)printf("%c",s[i]);
        printf("\n");
    }
}