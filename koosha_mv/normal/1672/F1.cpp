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

const int N=1e6+99;

int n,t,a[N],ans[N],cnt[N],nxt[N];

void Main(){
	cin>>n;
	f(i,1,n+1) cnt[i]=0;
	f(i,1,n+1){
		cin>>a[i];
		cnt[a[i]]++;
	}	
	vector<pair<int,int>> A;
	f(i,1,n+1){
		if(cnt[i]>0){
			A.pb({cnt[i],i});
		}
	}
	sort(all(A));
	f(i,0,int(A.size())-1){
		nxt[A[i].S]=A[i+1].S;
	}
	f(i,1,n+1){
		//eror(i);
		if(a[i]==A.back().S) continue ;
		ans[i]=nxt[a[i]];
	}
	vector<int> vec;
	int last=0;
	f(i,0,A.size()){
		f(j,0,A[i].F-last) vec.pb(A[i].S);
		last=A[i].F;
	}
	f(i,1,n+1){
		if(a[i]==A.back().S){
			ans[i]=vec.back();
			vec.pop_back();
		}
	}
	f(i,1,n+1) cout<<ans[i]<<" "; cout<<'\n';
}

int32_t main(){
	ios:: sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin>>t;
	while(t--){
		Main();
	}
}