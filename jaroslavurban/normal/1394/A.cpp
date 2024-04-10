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

int n,d,m;
vector<ll>a,b;
int cnta,cntb;//smaller= bigger
main(){
	cin.tie(0);cin.sync_with_stdio(0);
	cin>>n>>d>>m;
	for(int i=0;i<n;++i){
		int aa;cin>>aa;
		if(aa<=m)a.push_back(aa);
		else b.push_back(aa);
	}
	cnta=a.size();
	cntb=b.size();
//	cerr<<cnta<<" "<<cntb<<endl;
	sort(a.begin(),a.end());
	reverse(a.begin(),a.end());
	sort(b.begin(),b.end());
	reverse(b.begin(),b.end());
	for(int i=1;i<cnta;++i)a[i]+=a[i-1];
	for(int i=1;i<cntb;++i)b[i]+=b[i-1];
	ll res=0;
	for(int i=0;i<=cnta;++i){
		int nbs=(n-i+d)/(d+1);
//		cerr<<i<<" "<<nbs<<endl;
		ll ap=0,bp=0;
		if(i-1>=0)ap=a[i-1];
		if(min(cntb-1,nbs-1)>=0)bp=b[min(cntb-1,nbs-1)];
		res=max(res,ap+bp);
	}
	cout<<res<<endl;
}