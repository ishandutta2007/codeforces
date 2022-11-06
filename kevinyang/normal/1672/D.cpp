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
		}
		for(int i = 1; i<=n; i++){
			cin >> b[i];
		}
		bool f = true;
		int cur = 1;
		vector<int>freq(n+1);
		vector<int>freq2(n+1);
		for(int i = 1; i<=n; i++){
			freq[a[i]]++;
		}
		for(int i = 1; i<=n; i++){
			while(cur<=n&&a[cur]!=b[i]){
				if(freq[a[cur]]>1){
					freq[a[cur]]--;
					freq2[a[cur]]++;
				}
				else{
					f = false;
					break;
				}
				cur++;
			}
			if(cur>n)break;
			if(!f)break;
			if(freq2[b[i]]>0){
				freq2[b[i]]--;
			}
			else{
				freq[a[cur]]--;
				cur++;
			}
		}
		cout << (f?"YES":"NO") << "\n";
	}
	return 0;
}