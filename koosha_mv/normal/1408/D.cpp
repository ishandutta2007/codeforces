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

const int N=2005;

int n,m,res=N*N,a[N],b[N],c[N],d[N],mx[N*N];

int main(){
    cin>>n>>m;
    f(i,0,n){ gett(a[i]); gett(b[i]); }
    f(i,0,m){ gett(c[i]); gett(d[i]); }
    f(i,0,n)
        f(j,0,m){
            if(a[i]<=c[j])
                maxm(mx[max(c[j]-a[i],0)],max(d[j]-b[i]+1,0));
        }
    f_(i,N*N-3,0){
        maxm(mx[i],mx[i+1]);
        minm(res,i+mx[i]);
    }
    cout<<res<<endl;
}