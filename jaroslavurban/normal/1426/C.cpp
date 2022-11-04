#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

main(){
	cin.tie(0);cin.sync_with_stdio(0);
	int tt;cin>>tt;
	while(tt--){
		int n;cin>>n;
		int bst=1e9;
		int sm;
		for(int i=0;i<n;++i)
			if((sm=(n+i)/(i+1)+i-1)>bst)break;
			else bst=sm;
		cout<<bst<<endl;
	}
}