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
 
main(){
	cin.tie(0);cin.sync_with_stdio(0);
	int tc;cin>>tc;
	while(tc--){
		int n;cin>>n;
		int ones=0;
		for(int i=0;i<n;++i){
			int a;cin>>a;ones+=a;
		}
		if(2*ones<=n){
			cout<<n/2<<endl;
			for(int i=0;i<n/2;++i)cout<<"0 ";cout<<endl;
		}
		else if(n%4==0){
			cout<<n/2<<endl;
			for(int i=0;i<n/2;++i)cout<<(2*ones>=n)<<" ";cout<<endl;
		}	
		else{
			cout<<n/2+1<<endl;
			for(int i=0;i<n/2+1;++i)cout<<"1 ";cout<<endl;
		}
	}
}