// Hydro submission #633d147597b22c5e562afefe@1664947318258
#include <bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin >> T;
	while(T--){
		int n, k;
		cin >> n >> k;
		vector<int> s(k);//k 
		for(int i = 0; i < k; i++){
			cin >> s[i];
		}
		// 
		if(k == 1){
			cout << "Yes" << "\n";
			continue;
		}
		vector<int> d(k - 1);
		//n - k + 1 ~ n 
		//n - k + 2 ~ n 
		for(int i = 0; i < k - 1; i++){
			d[i] = s[i + 1] - s[i];
		}
		// 
		if(!is_sorted(d.begin(), d.end())){
			cout << "No" << '\n';
			continue; 
		}
		//n - k + 1
		//d[0]a[n - k + 2] 
		//s[0]s[n - k + 1] 
		if((long long) (n - k + 1) * d[0] >= s[0]){
			cout << "Yes" << '\n';
		}else{
			cout << "No" << '\n';
		}
	} 
	return 0;
}