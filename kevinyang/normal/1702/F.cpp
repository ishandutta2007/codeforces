#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		vector<int>a(n+1);
		vector<int>b(n+1);
		for(int i = 1; i<=n; i++){
			cin >> a[i];
			while(a[i]%2==0){
				a[i]/=2;
			}
		}
		multiset<int>s;
		for(int i = 1; i<=n; i++){
			s.insert(a[i]);
		}
		for(int i = 1; i<=n; i++){
			cin >> b[i];
		}
		bool f = true;
		sort(b.begin(),b.end());
		for(int i = 1; i<=n; i++){
			while(b[i]){
				if(s.find(b[i])!=s.end()){
					s.erase(s.find(b[i]));
					break;
				}
				b[i]/=2;
			}
			if(b[i]==0)f = false;
		}
		if(f)cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}