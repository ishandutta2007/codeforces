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
 
const int N=20;
 
int n,mk,cnt[N],ok[1<<N],dp[1<<N];
ll res,a[N],sum[1<<N];
vector<int> v;

void add(int x){
    if(cnt[x]){
        res+=a[v[x]]*2;
        cnt[x]=0;
        add(x+1);
        return ;
    }
    cnt[x]=1;
    res-=a[v[x]]*2;
}
void find(){
    f(mask,0,(1<<n))
        f(i,0,n)
            if(mask&(1<<i))
                sum[mask]+=a[i];
    f(mask,1,(1<<n)){
        int t=__builtin_popcount(mask);
        if(((t+sum[mask])&1)==0) continue;
        fill(cnt,cnt+N,0);
        v.clear();
        res=sum[mask];
        f(i,0,n)
            if(mask&(1<<i))
                v.pb(i);
        f(i,1,(1<<(t-1))){
            add(0);
            if(abs(res)<t){
                ok[mask]=1;
                break;
            }
        }
    }
    
}
void solve(){
    f(mask,1,(1<<n)){
        int u=((1<<n)-1)^mask;
        mk=0;
        dp[mask]=N;
        f(i,0,n)
            if(mask&(1<<i)){
                minm(dp[mask],dp[mask^(1<<i)]+(a[i]!=0));
                v.pb(i);
            }
        f(j,1,(1<<(__builtin_popcount(mask)-1))){
            mk=(mk|u)+1;
            mk=mk&mask;
            if(ok[mk]) minm(dp[mask],dp[mask^mk]+__builtin_popcount(mk)-1);
        }
        if(ok[mask]) minm(dp[mask],__builtin_popcount(mask)-1);
    }
    cout<<dp[(1<<n)-1];
}
 
int main(){
    cin>>n;
    f(i,0,n) cin>>a[i];
    find();
    solve();
}