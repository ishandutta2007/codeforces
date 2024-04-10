#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
int n;

main(){
	cin.tie(0);cin.sync_with_stdio(0);
	int tt;cin>>tt;
	while(tt--){
		cin>>n;
		cout<<2<<endl;
		if(n==2){
			cout<<"1 2\n";
			continue;
		}if(n==3){
			cout<<"1 3\n2 2\n";
			continue;
		}
		cout<<n-2<<" "<<n<<endl;
		cout<<n-1<<" "<<n-1<<endl;
		for(int i=n-4;i>=0;--i)cout<<i+1<<" "<<i+3<<endl;
	}
}