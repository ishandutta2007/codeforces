#include <bits/stdc++.h>
using namespace std;
#define dbgv(v) cout<<#v<<" = "; f(i,0,v.size()) cout<<v[i]<<" "; cout<<endl
#define dbga(a,x,y) cout<<#a<<" = "; f(i,x,y) cout<<a[i]<<" "; cout<<endl
#define erorp(x) cout<<#x<<"={"<<x.F<<" , "<<x.S<<"}"<<endl
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

int n,t,a[N],mark[N];

int32_t main(){
	ios:: sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin>>t;
	while(t--){
		vector<int> vec;
		int cnt=0;
		cin>>n;
		f(i,0,n){
			cin>>a[i];
		}
		f(i,0,a[n]+1) mark[i]=0;
		f(i,1,n){
			cnt+=(a[i-1]==a[i]);
			if(a[i-1]==a[i]) continue ;
			vec.pb(a[i]-a[i-1]);
		}
		while(vec.size()>1){
			sort(all(vec));
			//dbgv(vec);
			vector<int> T;
			if(cnt>0) T.pb(vec[0]),cnt--;
			f(i,1,vec.size()){
				if(vec[i]==vec[i-1]){
					cnt++;
					continue ;
				}
				T.pb(vec[i]-vec[i-1]);
			}
			vec=T;
		}
		if(vec.size()==0){
			cout<<0<<'\n';	
		}
		else{
			cout<<vec[0]<<'\n';
		}
	}
}
/*
1
6
2 4 8 16 32 64
*/