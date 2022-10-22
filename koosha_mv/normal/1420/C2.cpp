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

const int N=1e6+99;

int n,q,t,a[N],mark1[N],mark2[N];
ll ans;

void calc1(int x){
    if(x<1 || n<x) return ;
    ans-=mark1[x]*a[x];
    ans+=mark2[x]*a[x];
    mark1[x]=mark2[x]=0;
  //  cout<<x<<" : "<<ans<<endl;
}
void calc2(int x){
    if(x<1 || n<x) return ;
    if(!mark1[x])
    mark1[x]=(a[x-1]<a[x]),ans+=mark1[x]*a[x];
    if(!mark2[x])
    mark2[x]=(a[x]<a[x+1]),ans-=mark2[x]*a[x];
}

int main(){
	cin>>t;
	while(t--){
	    fill(mark1,mark1+n+2,0);
	    fill(mark2,mark2+n+2,0);
	    ans=0;
	    cin>>n>>q;
	    f(i,1,n+1)
	        gett(a[i]);
	    a[n+1]=0;
	    f(i,1,n+1) calc2(i);
	    cout<<ans<<'\n';
	    f(i,0,q){
	        int l,r;
	        Gett(l,r);
	        f(i,0,3)
	            calc1(l-1+i);
	        f(i,0,3)
	            calc1(r-1+i);
	        swap(a[l],a[r]);
	     //   eror(ans);
	        f(i,0,3)
	            calc2(l-1+i);
	        f(i,0,3)
	            calc2(r-1+i);
	        cout<<ans<<'\n';
	    }
	}
}