#include <bits/stdc++.h>
using namespace std;
#define erorp(x) cout<<#x<<"={"<<(x.F)<<" , "<<x.S<<"}"<<endl;
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl;
#define eror(x) cout<<#x<<'='<<(x)<<endl;
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define Gett(x,y) scanf("%d%d",&x,&y);
#define f(i,a,b) for(int i=a;i<b;i++)
#define is_bit(x,y) (0<(x&(1ll<<y)))
#define get(x) scanf("%I64d",&x);
#define All(x) x.begin(),x.end()
#define gett(x) scanf("%d",&x);a
#define Add(x,y) x=(x+y)%mod;
#define maxm(a,b) a=max(a,b)
#define minm(a,b) a=min(a,b)
#define lst(x) x[x.size()-1]
#define sz(x) int(x.size())
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first
 
const int N=1e5+9,Lg=62,S=2;

int T; 
ll s;
string n;

ll mv(string s){
    ll p=1,ans=0;
    f_(i,s.size()-1,0){
        ans+=p*(s[i]-'0');
        p*=10;
    }
    return ans;
}

int main(){
    cin>>T;
    while(T--){
        string ans="";
        int sum=1,p=-1;
        cin>>n>>s;
        f(i,0,sz(n)){
            sum+=(n[i]-'0');
            if(sum<=s && n[i]!='9')
                p=i;
        }
        if(sum<=s+1) ans=n;
        else{
            if(p==-1){
                ans+='1';
                f(i,0,n.size())
                    ans+='0';
            }
            else{
                f(i,0,n.size()){
                    if(i<p) ans+=n[i];
                    if(i==p) ans+=char(n[i]+1);
                    if(p<i) ans+='0';
                }
            }
        }
        cout<<mv(ans)-mv(n)<<endl;
        
    }
}