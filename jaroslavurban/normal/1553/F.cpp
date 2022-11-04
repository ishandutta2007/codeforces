#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

// always index from 1 to n
// if I added vector init, it wouldn't be clear if prefix or not
// call update for each item after init to init
// update: add d to a[i] (and update the prefix sum)
// query: if i has first 1 at pos x, then it keeps the sum of the next 2^x numbers, so we add that sum and jump by 2^x
template<class T>
struct Fenwick{
	T n;vector<T>a;
	Fenwick(int n):n(n),a(n){}; 
	T query(int i){
		T r=0;
		for(;i;i-=i&-i)r+=a[i];
		return r;
	}
	T query(int l,int r){return query(r-1)-query(l-1);}
	void update(int i,T d){
		for(;i<n;i+=i&-i)a[i]+=d;
	}
};


void ProGamerMove(){
	int n,N=300100;cin>>n;
	Fenwick<ll>A(N),B(N);
	ll pref=0,sm=0;
	for(int i=0;i<n;++i){
		int a;cin>>a;
		ll res=sm+i*(ll)a-A.query(a);
		for(int j=1;j*a<N;++j){
			A.update(j*a,a);
			res-=B.query(j*a,min(N,(j+1)*a))*j*a;
		}
		B.update(a,1);
		cout<<res+pref<<" ";
		pref+=res;
		sm+=a;
	}
	cout<<endl;
}

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	int tc=1;
//	cin>>tc;
	while(tc--)ProGamerMove();
}