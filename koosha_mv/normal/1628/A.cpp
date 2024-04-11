#include <bits/stdc++.h>
using namespace std;
#define dbgv(v) cout<<#v<<" = "; f(i,0,v.size()) cout<<v[i]<<" "; cout<<endl
#define dbga(a,x,y) cout<<#a<<" = "; f(i,x,y) cout<<a[i]<<" "; cout<<endl
#define erorp(x) cout<<#x<<"={"<<(x.F)<<" , "<<x.S<<"}"<<endl
#define eror(x) cout<<#x<<'='<<(x)<<endl
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define f(i,a,b) for(int i=a;i<b;i++)
#define nb(x) __builtin_popcount(x)
#define all(v) v.begin(),v.end()
#define bit(n,k) (((n)>>(k))&1)
#define Add(x,y) x=(x+y)%mod
#define maxm(a,b) a=max(a,b)
#define minm(a,b) a=min(a,b)
#define lst(x) x[x.size()-1]
#define sz(x) int(x.size())
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first
#define int ll

const int N=1e6+99;

int n,t,a[N],mark[N],vis[N];

void Main(){
	vector<int> ans;
	cin>>n;
	f(i,0,n){
		cin>>a[i];
		mark[a[i]]++;
	}
	int p=0;
	while(p<n){
		int cnt=0,Mex=0;
		f(i,0,n+1) if(!mark[i]){
			Mex=i;
			break;
		}
		int t=1;
		while(t>0 || cnt<Mex){
			t--;
			mark[a[p]]--;
			if(a[p]<Mex && vis[a[p]]==0) cnt++;
			vis[a[p]]=1;
			p++;
		}
		fill(vis,vis+Mex+9,0);
		ans.pb(Mex);
	}
	fill(vis,vis+n+10,0);
	fill(mark,mark+n+10,0);
	cout<<ans.size()<<endl;
	for(auto x : ans) cout<<x<<" "; cout<<endl;
}

main(){
	cin>>t;
	while(t--){
		Main();
	}
}