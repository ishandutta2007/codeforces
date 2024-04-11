#include <bits/stdc++.h>
using namespace std;
#define erorp(x) cout<<#x<<"={"<<(x.F)<<" , "<<x.S<<"}"<<endl;
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl;
#define Get(x,y) scanf("%I64d%I64d",&x,&y);
#define is_bit(x,y) (x%(1<<(y+1))>=(1<<y))
#define eror(x) cout<<#x<<'='<<(x)<<endl;
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define Gett(x,y) scanf("%d%d",&x,&y);
#define f(i,a,b) for(int i=a;i<b;i++)
#define get(x) scanf("%I64d",&x);
#define gett(x) scanf("%d",&x);
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
#define Add(x,y) x=(x+y)%mod
#define lst(x) x[x.size()-1]
#define sz(x) int(x.size())
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first
 
const int N=1e6+99,mod=1e9+7;
 
int n,m,t,g[N],a[N],mark[N];
ll ans;
 
int main(){
    cin>>t;
    while(t--){
        int ans=0,res=1;
        cin>>n;
        fill(mark,mark+n,0);
        f(i,0,n) cin>>a[i];
        f(i,0,n){
            int x;
            cin>>x;
            g[x-1]=a[i]-1;
        }
        f(i,0,n){
            if(!mark[i]){
                ans++;
                int u=i;
                while(g[u]!=i){
                    mark[u]=1;
                    u=g[u];
                }
                mark[u]=1;
            }
        }
        f(i,0,ans) res=2ll*res%mod;
        cout<<res<<endl;
    }
 }