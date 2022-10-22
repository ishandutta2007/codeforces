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

const int N=1e5+9;

int n,t,ans,a[N],cnt[N],mark[N];

int main(){
    cin>>t;
    while(t--){
        ans=0;
        cin>>n;
        f(i,0,n){
            cin>>a[i];
            cnt[a[i]]++;
            if((n+1)/2<cnt[a[i]]) ans=-1;
        }
        if(ans<0) cout<<ans<<'\n';
        else{
            f(i,0,n-1) if(a[i]==a[i+1]) ans++;
            f(i,0,n)
                mark[a[i]]+=(i==0 || a[i]==a[i-1])+(i==n-1 || a[i]==a[i+1]);
            f(i,0,n+1) maxm(ans,mark[a[i]]-2);
            cout<<ans<<'\n';
        }
        fill(cnt,cnt+n+1,0);
        fill(mark,mark+n+1,0);
    }
}