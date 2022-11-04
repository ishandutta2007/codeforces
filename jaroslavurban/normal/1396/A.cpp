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
ll a[N];
int n;
main(){
	cin.tie(0);cin.sync_with_stdio(0);
	int n;cin>>n;
	for(int i=0;i<n;++i)cin>>a[i];
	if(n==1){	
		cout<<"1 1 0"<<endl;
		cout<<"1 1 0"<<endl;
		cout<<"1 1 "<<-a[0]<<endl;
		return 0;
	}
	cout<<"1 "<<n-1<<endl;
	for(int i=0;i<n-1;++i)cout<<a[i]*(n-1)<<" ";cout<<endl;
	cout<<n<<" "<<n<<endl;
	cout<<n*a[n-1]-a[n-1]<<endl;
	cout<<"1 "<<n<<endl;
	for(int i=0;i<n;++i)cout<<-n*a[i]<<endl;
}