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

const int N=200010;
int a[N];
main(){
	cin.tie(0);cin.sync_with_stdio(0);
	int tc;cin>>tc;
	while(tc--){
		int n;cin>>n;
		int mx=1,idx;
		for(int i=0;i<n;++i){
			cin>>a[i];
			if(a[i]==1)idx=i;
		}
		int l=idx-1,r=idx+1;
		cout<<1;
		for(int i=0;i<n-1;++i){
			if(l<0||(r<n&&a[r]<a[l])){
				mx=max(mx,a[r]);++r;
			}
			else{
				mx=max(mx,a[l]);--l;
			}
			if(mx==i+2)cout<<1;
			else cout<<0;
		}
		cout<<endl;
	}
}