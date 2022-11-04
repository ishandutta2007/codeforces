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

const int N=100010;
int a[N];
int n,q,n2,n4,n6,n8;
main(){
	cin.tie(0);cin.sync_with_stdio(0);
	cin>>n;
	for(int i=0;i<n;++i){
		int aa;cin>>aa;
		++a[aa];
		if(a[aa]==2)++n2;
		if(a[aa]==4)++n4;
		if(a[aa]==6)++n6;
		if(a[aa]==8)++n8;
	}
	cin>>q;
	while(q--){	
		int num;
		char o;cin>>o>>num;
		if(o=='-')--a[num];
		else ++a[num];
		if(a[num]==1&&o=='-')--n2;
		if(a[num]==2&&o=='+')++n2;
		if(a[num]==3&&o=='-')--n4;
		if(a[num]==4&&o=='+')++n4;
		if(a[num]==5&&o=='-')--n6;
		if(a[num]==6&&o=='+')++n6;
		if(a[num]==7&&o=='-')--n8;
		if(a[num]==8&&o=='+')++n8;
		if((n4>1)||(n4&&n2>2)||(n6&&n2>=2)||(n8))cout<<"YES\n";
		else cout<<"NO\n";
	}
}