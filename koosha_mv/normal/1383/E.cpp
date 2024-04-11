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

int n,c,l,r,sum,dp0[N],dp1[N],fen[N];
vector<int> v;
string s;

void update(int x,int val) { ++x; x=N-x;  while(x<N)  {  fen[x]=val;  x+=(x&-x);  } }
int query(int x) {  ++x;  x=N-x; int res=0;  while(x>0)  {  maxm(res,fen[x]);  x-=(x&-x);  } return res; } 

main(){
    v.pb(0);
    cin>>s;    
    n=s.size();
    l=0,r=n-1;
    while(l<n && s[l]=='0') l++;
    if(l==n) return cout<<n,0;
    while(s[r]=='0') r--;
    f(i,l,r+1){
        if(i>l && s[i]!=s[i-1]) v.pb(c),c=0;
        c++;
    }
    v.pb(c);
    f(i,1,v.size()){
        f(j,0,v[i]){
            if(i&1) Add(dp1[i],dp0[i-1]+1);
            else{
                int u=query(j+1);
                Add(dp0[i],1ll*(dp1[i-1]-dp1[u]+mod));
            }
        }
        if(i%2==0) update(v[i],i);
        Add(dp1[i],dp1[i-1]);
        Add(dp0[i],dp0[i-1]);
    }
    cout<<1ll*dp1[v.size()-1]*(l+1)%mod*(n-r)%mod;
}