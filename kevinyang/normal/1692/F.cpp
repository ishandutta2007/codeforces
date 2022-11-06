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
		vector<int>freq(11);
		for(int i = 1; i<=n; i++){
			int x;
			cin >> x;
			x%=10;
			freq[x]++;
		}
		bool f = false;
		for(int i = 0; i<10; i++){
			for(int j = 0; j<10; j++){
				for(int k = 0; k<10; k++){
					bool flag = true;
					if((i+j+k)%10!=3)flag = false;
					vector<int>cnt(10);
					cnt[i]++;
					cnt[j]++;
					cnt[k]++;
					for(int a = 0; a<10; a++){
						if(cnt[a]>freq[a])flag = false;
					}
					if(flag)f = true;
				}
			}
		}
		if(f)cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}