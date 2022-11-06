#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		int n,l,r,s;
		cin >> n >> l >> r >> s;
		vector<int>arr(n+1);
		for(int i = l; i<=r; i++){
			arr[i] = i-l+1;
		}
		bool f = true;
		int sum = (r-l+1)*(r-l+2)/2;
		if(s<sum)f = false;
		if(s>n*(n+1)/2-(n-(r-l+1))*(n-(r-l+1)+1)/2)f = false;
		if(!f)cout << "-1\n";
		else{
			for(int i = 0; i<n-(r-l+1); i++){
				if(sum==s)break;
				for(int j = r; j>=l; j--){
					arr[j]++; sum++;
					if(sum==s)break;
				}
			}
			set<int>s;
			for(int i = 1; i<=n; i++){
				s.insert(i);
			}
			for(int i = l; i<=r; i++){
				s.erase(arr[i]);
			}
			for(int i = 1; i<=n; i++){
				if(i>=l&&i<=r)continue;
				arr[i] = *s.begin();
				s.erase(s.begin());
			}
			for(int i = 1; i<=n; i++){
				cout << arr[i] << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}