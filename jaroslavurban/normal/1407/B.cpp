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

ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a%b); }
 
const int N=1010;
int a[N];
bool done[N];
main(){
	cin.tie(0);cin.sync_with_stdio(0);
	int tc;cin>>tc;
	while(tc--){
		int n;cin>>n;
		for(int i=0;i<n;++i)done[i]=0;
		for(int i=0;i<n;++i)cin>>a[i];
		int mx=0,mxi;
		for(int i=0;i<n;++i)
			if(a[i]>mx){
				mx=a[i];
				mxi=i;
			}
		done[mxi]=true;
		int gc=a[mxi];cout<<a[mxi]<<" ";
		for(int i=1;i<n;++i){
			int mx=0,mxi;
			for(int i=0;i<n;++i)
				if(!done[i])
					if(gcd(a[i],gc)>mx){
						mx=gcd(a[i],gc);
						mxi=i;
					}
			done[mxi]=true;
			gc=mx;
			cout<<a[mxi]<<" ";
		}
		cout<<endl;
	}
}