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

int n,t,a[N];
vector<pair<int,char> > vec[4];

main(){
	ios:: sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int x,y;
	cin>>n;
	cin>>x>>y;
	f(i,0,n){
		int u,v;
		char c;
		cin>>c>>u>>v;
		if(x==u) vec[0].pb({v,c});
		if(y==v) vec[1].pb({u,c});
		if(x+y==u+v) vec[2].pb({u,c});
		if(x-y==u-v) vec[2].pb({u,c});
	};
	f(i,0,4) sort(all(vec[i]));
	f(i,0,4){
		int pos;
		if(i==0) pos=upper_bound(all(vec[i]),mp(y,'A'))-vec[i].begin();
		else pos=upper_bound(all(vec[i]),mp(x,'A'))-vec[i].begin();
		if(pos<vec[i].size()){
			char c=vec[i][pos].S;
			if((i<2 && c!='B') || (2<=i && c!='R')){
				cout<<"YES";
				exit(0);
			}
		}
		pos--;
		if(pos>=0){
			char c=vec[i][pos].S;
			if((i<2 && c!='B') || (2<=i && c!='R')){
				cout<<"YES";
				exit(0);
			}
		}
	}
	cout<<"NO";
}