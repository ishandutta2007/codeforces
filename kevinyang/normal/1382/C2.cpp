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
		string s;
		string s2;
		cin >> s;
		cin >> s2;
		vector<int>arr(n);
		vector<int>arr2(n);
		for(int i = 0; i<n; i++){
			arr[i] = (int)s[i]-(int)'0';
			arr2[i] = (int)s2[i] -(int)'0';
		}
		int left = 0;
		int right = n-1;
		int add = 0;
		int count = 0;
		vector<int>ans;
		while(left<right){
			if(add%2==0){
				//go from right
				if((arr[right]+add)%2==arr2[n-count-1]){
					right--;
					count++;
					continue;
				}
				if((arr[left]+add)%2==arr2[n-count-1]){
					ans.push_back(1);
					arr[left] = (arr[left]+1)%2;
				}
				ans.push_back(n-count);
				for(int i = left; i<right; i++){
					if(arr[right-(i-left)]!=arr[i]){
						right--;
						count++;
					}
					else{
						break;
					}
				}
				add++;
			}
			else{
				if((arr[left]+add)%2==arr2[n-count-1]){
					left++;
					count++;
					continue;
				}
				if((arr[right]+add)%2==arr2[n-count-1]){
					ans.push_back(1);
					arr[right] = (arr[right]+1)%2;
				}
				ans.push_back(n-count);
				for(int i = right; i>left; i--){
					if(arr[left+(right-i)]!=arr[i]){
						left++;
						count++;
					}
					else{
						break;
					}
				}
				add++;
			}
		}
		if((arr[left]+add)%2!=arr2[0])ans.push_back(1);
		cout << ans.size() << " ";
		for(int nxt:ans){
			cout << nxt << " ";
		}
		cout << "\n";
	}
	return 0;
}