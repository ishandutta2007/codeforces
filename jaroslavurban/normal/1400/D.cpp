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

const int N=3030;
int lft[N],rght[N],a[N];
main(){
	cin.tie(0);cin.sync_with_stdio(0);
	int tc;cin>>tc;
	while(tc--){
		int n;cin>>n;
		for(int i=0;i<n;++i)cin>>a[i];
		ll res=0;
		for(int i=0;i<n;++i){
			memset(lft,0,sizeof(lft));
			memset(rght,0,sizeof(rght));
			for(int j=i+2;j<n;++j)++rght[a[j]];
			ll pairs=0;
			for(int j=i+1;j<n-1;++j){
				if(a[j]==a[j+1]){
					pairs-=lft[a[j]]*rght[a[j]];
					pairs+=++lft[a[j]]*--rght[a[j]];
				}
				else{
					pairs+=rght[a[j]];
					pairs-=lft[a[j+1]];
					--rght[a[j+1]];
					++lft[a[j]];
				}
				if(a[j+1]==a[i])res+=pairs;
			}
		}
		cout<<res<<endl;
	}
}