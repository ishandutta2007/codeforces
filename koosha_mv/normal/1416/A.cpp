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

int n,t,a[N],last[N],res[N],ans[N];

int main(){
	cin>>t;
	while(t--){
	    cin>>n;
	    fill(res,res+n+2,0);
	    fill(last,last+n+2,0);
	    fill(ans,ans+n+2,N);
	    f(i,1,n+1){
	        gett(a[i]);
	        maxm(res[a[i]],i-last[a[i]]);
	        last[a[i]]=i;
	    }
	    f(i,1,n+1)
	        maxm(res[i],n+1-last[i]);
	   f(i,1,n+1){
	        minm(ans[res[i]],i);
	      //  cout<<res[i]<<" ";
	   }//cout<<endl;
	   f(i,1,n+1){
	       if(1<i) minm(ans[i],ans[i-1]);
	       cout<<(ans[i]==N ? -1 : ans[i] )<<" ";
	   }
	   cout<<'\n';
	}
}