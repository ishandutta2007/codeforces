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

const int N=1e5+99;

int n,L,t,b[N],c[N],mark[N];
double a[N];

bool check(double x,int s){
    double res1=0,res2=0;
    f(i,0,n){
        if(x<=a[i]) break;
        res1+=(min(x,a[i+1])-a[i])/(i+1);
    }
    f_(i,n-1,0){
        if(a[i]<=x) break;
        res2+=(a[i]-max(a[i-1],x))/(n-i);
    }
   // cout<<x<<" "<<res1<<" "<<res2<<endl;
   if(s) cout<<setprecision(8)<< fixed<<res1<<endl;
    if(res1<=res2) return 1;
    return 0;
}

int main(){
    cin>>t;
    while(t--){
        cin>>n>>L;
        f(i,1,n+1) cin>>a[i];
        a[++n]=L;
        n++;
        double l=0,r=L,mid;
        f(i,0,120){
            mid=(l+r)/2.0;
            if(check(mid,0)) l=mid;
            else r=mid;
        }
        check(l,1);
    }
}