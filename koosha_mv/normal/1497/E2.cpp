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

const int N=2e5+99,Max=1e7+9,K=22;

int t,n,k,d[Max],s[Max],a[N],prv[Max],dp[N][K];

void do_it(){
    s[1]=1;
    f(i,2,Max){
        if(d[i]==0)
            for(int j=i;j<Max;j+=i)
                d[j]=i;
        s[i]=s[i/d[i]];
        if(s[i]%d[i]==0) s[i]/=d[i];
        else s[i]*=d[i];
    }
}

int main(){
    do_it();
    cin>>t;
    while(t--){
        vector<int> v;
        v.pb(0);
        int res=0,ans=N;
        cin>>n>>k;
        f(i,1,n+1){
            cin>>a[i];
            a[i]=s[a[i]];
            if(prv[a[i]]) v.pb(prv[a[i]]);
            sort(v.begin(),v.end());
            reverse(v.begin(),v.end());
            if(k+1<v.size()) v.pop_back();
            f(j,0,k+1){
                dp[i][j]=i;
                f(ind,0,min(int(v.size()),j+1))
                    minm(dp[i][j],dp[v[ind]][j-ind]+1);
                //cout<<i<<" "<<j<<" : "<<dp[i][j]<<endl;
            }
            prv[a[i]]=i;
        }
        f(i,1,n+1)
            prv[a[i]]=0;
        f(i,0,k+1)
            minm(ans,dp[n][i]);
        cout<<ans<<endl;
    }
}