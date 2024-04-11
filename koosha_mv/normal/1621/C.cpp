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

const int N=1e6+99;

int n,t,a[N],ans[N],mark[N];

void Main(){
	cin>>n;
	f(i,1,n+1){
		vector<int> v;
		if(!mark[i]){
			vector<int> v;
			while(1){
				int x;
				cout<<"? "<<i<<endl;
				cin>>x;
				if(v.size() && x==v[0]){
					break;
				}
				v.pb(x);
			}
			f(i,0,v.size()){
				ans[v[i]]=v[(i+1)%sz(v)];
				mark[v[i]]=1;
			}
		}
	}
	f(i,1,n+1) mark[i]=0;
	cout<<"! ";
	f(i,1,n+1) cout<<ans[i]<<" ";
	cout<<endl;
}

main(){
	//t=1;
	cin>>t;
	while(t--){
		Main();
	}
}