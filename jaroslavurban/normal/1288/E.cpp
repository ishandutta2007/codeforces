#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
//#define int ll
//#define endl '\n'

// use unique(x) - removec consecutive items, returns vec.begin() + number of items
// for vector: sort(all(vec)); vec.erase(unique(all(vec)), vec.end());
// use iota(all(vec), 0) for filling a vector with 0,1,2...
// use fill(all(vec), 1) for filling a vector with 1,1,1...
// use rotate(vec.begin(), vec.begin() + 1, vec.end()) to rotate a vector | middle arg becomes first
// print number in binary -> cout << bitset<20>(n);
// always index from 1 to n
template<class T>
struct fenwick{
	T n;
	vector<T>a;
	fenwick(T n):n(n),a(n){}
	fenwick(vector<T>a):a(a),n(a.size()){
		for(T i=0;i<n;++i)
			if(i+(i&-i)<n)
				a[i+(i&-i)]+=a[i];
	}
	T q(T i){
		T r=0;
		for(;i;i-=i&-i)r+=a[i];
		return r;
	}
	void q(T i,T d){
		for(;i<n;i+=i&-i)a[i]+=d;
	}
};


const int N=300010;
int a[N],prevr[N];
int n,m;
pair<int,int>r[N];
main(){
	cin.tie(0);cin.sync_with_stdio(0);
	cin>>n>>m;
	for(int i=0;i<m;++i)cin>>a[i];
	fenwick<int>fl(n+1);
	for(int i=0;i<m;++i)
		if(!fl.q(a[i])||(a[i]!=1&&fl.q(a[i])==fl.q(a[i]-1))){
			r[a[i]-1]={1,a[i]+fl.q(n)-fl.q(a[i])};
			fl.q(a[i],1);
		}
	fenwick<int>fr(m+1);
	for(int i=m-1;i>=0;--i){
		fr.q(m-i,1);
		if(prevr[a[i]])fr.q(prevr[a[i]],-1);
		r[a[i]-1].second=max(r[a[i]-1].second,fr.q(m-i)-(prevr[a[i]]?fr.q(prevr[a[i]]):0));
		prevr[a[i]]=m-i;
	}
	for(int i=0;i<n;++i)
		if(!r[i].first)
			r[i]={i+1,i+1+fl.q(n)-fl.q(i+1)};
	for(int i=0;i<n;++i)cout<<r[i].first<<" "<<r[i].second<<endl;
}