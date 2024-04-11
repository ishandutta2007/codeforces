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
 
int n,t,l,r,a[N],mark[N];
vector<int> v[N],v1,v2;
 
int main(){
	cin>>t;
	while(t--){
	    int ans=0,sz1,sz2;
	    cin>>n>>l>>r;
	    fill(mark,mark+n+1,0);
	    f(i,0,n){
	        cin>>a[i];
	        if(i<l)
	            v[a[i]].pb(i);
	        else{
	            if(v[a[i]].size()){
	                mark[i]=1;
	                mark[v[a[i]][v[a[i]].size()-1]]=1;
	                v[a[i]].pop_back();
	            }
	        }
	    }
	    f(i,1,n+1) v[i].clear();
	    f(i,0,n){
	        if(!mark[i]){
	            if(i<l) v1.pb(a[i]);
	            else v2.pb(a[i]);
	        }
	    }
	    sort(v1.begin(),v1.end());
	    sort(v2.begin(),v2.end());
	    sz1=v1.size();
	    sz2=v2.size();
	    //cout<<sz1<<" "<<sz2<<endl;
	    ans=(sz1+sz2)/2;
	    f(i,1,v1.size()){
	        if(sz1>sz2 && v1[i]==v1[i-1]){
	            sz1-=2;
	            i++;
	        }   
	    }
	    f(i,1,v2.size()){
	        if(sz2>sz1 && v2[i]==v2[i-1]){
	            sz2-=2;
	            i++;
	        }
	    }
	   // cout<<ans<<endl;
	    ans+=abs(sz1-sz2)/2;
	    cout<<ans<<endl;
	    v1.clear(),v2.clear();
	}
}