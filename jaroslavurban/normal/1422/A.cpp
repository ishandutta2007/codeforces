#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

main(){
	cin.tie(0);cin.sync_with_stdio(0);
	int tt;cin>>tt;
	while(tt--){
		int a[3];cin>>a[0]>>a[1]>>a[2];
		sort(a,a+3);
		cout<<a[2]<<endl;
	}
}