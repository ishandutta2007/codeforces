#include <bits/stdc++.h>
using namespace std;
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl;
#define Get(x,y) scanf("%I64d%I64d",&x,&y);
#define is_bit(x,y) (x%(1<<(y+1))>=(1<<y))
#define eror(x) cout<<#x<<'='<<(x)<<endl;
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define Gett(x,y) scanf("%d%d",&x,&y);
#define f(i,a,b) for(int i=a;i<b;i++)
#define get(x) scanf("%I64d",&x);
#define All(x) x.begin(),x.end()
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

const int N=26,Max=50001;

int n,u,sum,res,a[N*2],mark[N*2];
int dp[N][N*Max];

void read(){
    cin>>n;
    f(i,0,2*n){ cin>>a[i]; sum+=a[i]; }
    sort(a,a+n+n);
    reverse(a,a+n+n);
}
void do_it(){
    f(i,0,N) f(j,0,Max*N) dp[i][j]=-1;
    dp[0][0]=0;
    f(i,0,n*2-2)
        f_(j,min(i+1,n-1),1)
            f(k,a[i],j*Max)
                if(dp[j][k]==-1 && -1<dp[j-1][k-a[i]])
                    dp[j][k]=i;
    
    sum-=a[n*2-2]+a[n*2-1];
    f_(i,sum/2,0)
        if(-1<dp[n-1][i]){
            u=i;
            break;
        }
    mark[n*2-1]=1;
    f_(i,n-1,1){
        mark[dp[i][u]]=1;
        u-=a[dp[i][u]];
    }
    
    vector<int> v[2];
    f(i,0,n*2)
        v[mark[i]].pb(a[i]);
    sort(v[0].begin(),v[0].end());
    sort(v[1].begin(),v[1].end());
    f(i,0,n) cout<<v[0][i]<<" "; cout<<'\n';
    f_(i,n-1,0) cout<<v[1][i]<<" ";
}

int main(){
    read();
    do_it();
}