#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		int a,b;
		cin >> a >> b;
		if(a>b)swap(a,b);
		if(a==b){
			cout << "0 0\n";
		}
		else{
			int dif = b-a;
			cout << dif << " " << min(a%dif,dif-a%dif) << "\n";
		}
	}
	return 0;
}