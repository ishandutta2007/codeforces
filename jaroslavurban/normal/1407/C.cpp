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
 
const int N=10010;
int a[N];
bool done[N];
int n;
main(){
	cin.tie(0);cin.sync_with_stdio(0);
	cin>>n;
	int mxi=0;
	for(int i=1;i<n;++i){
		int amx,mxa;
		cout<<"? "<<i+1<<" "<<mxi+1<<endl;
		cin>>amx;
		cout<<"? "<<mxi+1<<" "<<i+1<<endl;
		cin>>mxa;
		if(amx>mxa)a[i]=amx;
		else{
			a[mxi]=mxa;
			mxi=i;
		}
	}
	cout<<"! ";
	for(int i=0;i<n;++i)
		if(a[i])cout<<a[i]<<" ";
		else cout<<n<<" ";
	cout<<endl;
}