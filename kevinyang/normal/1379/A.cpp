#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int t;
	cin >> t;
	vector<char>str = {'a','b','a','c','a','b','a'};
	while(t--){
		int n;
		cin >> n;
		string s;
		cin >> s;
		int count = 0;
		for(int i = 0; i<=n-7; i++){
			bool f = true;
			for(int j = i; j<i+7; j++){
				if(s[j]!=str[j-i]){
					f = false;
				}
			}
			if(f){
				count++;
			}
		}
		if(count>1){
			cout << "No\n";
		}
		else if(count==1){
			cout << "Yes\n";
			for(int i = 0; i<n; i++){
				if(s[i]=='?'){
					cout << 'z';
				}
				else{
					cout << s[i];
				}
			}
			cout << "\n";
		}
		else{
			vector<int>ans;
			for(int i = 0; i<=n-7; i++){
				for(int j = i; j<i+7; j++){
					if(s[j]=='?'){

					}
					else if(s[j]==str[j-i]){

					}
					else{
						break;
					}
					if(j==i+6){
						ans.push_back(i);
					}
				}
			}
			vector<char>arr(n);
			bool f = false;
			for(int nxt: ans){
				for(int i = 0; i<n; i++){
					arr[i] = s[i];
				}
				for(int i = nxt; i<nxt+7; i++){
					arr[i] = str[i-nxt];
				}
				count = 0;
				for(int i = 0; i<=n-7; i++){
					bool f2 = true;
					for(int j = i; j<i+7; j++){
						if(arr[j]!=str[j-i]){
							f2 = false;
						}
					}
					if(f2){
						count++;
					}
				}
				if(count==1){
					f = true;
					cout << "Yes\n";
					for(int i = 0; i<n; i++){
						if(arr[i]=='?'){
							cout << 'z';
						}
						else{
							cout << arr[i];
						}
					}
					cout << "\n";
					break;
				}
			}
			if(!f){
				cout << "No\n";
			}
		}
	}
	return 0;
}