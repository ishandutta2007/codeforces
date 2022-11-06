#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		int n,k;
		cin >> n >> k;
		string s;
		cin >> s;
		vector<char>arr(n);
		for(int i = 0; i<n; i++){
			arr[i] = s[i];
		}
		int cur = 0;
		if(arr[0]=='W')cur++;
		for(int i = 1; i<n; i++){
			if(arr[i]=='W'&&arr[i-1]=='W'){
				cur+=2;
			}
			else if(arr[i]=='W'){
				cur++;
			}
		}
		if(cur==0){
			cout << max(0LL,2*k-1) << "\n";
			continue;
		}
		//cout << cur << "\n";
		int first;//length,
		vector<int>choices;
		int num = 0;
		for(int i = 0; i<n; i++){
			if(arr[i]=='L')num++;
			else{
				if(num==i)first = num;
				else choices.push_back(num);
				//cout << num << "\n";
				num = 0;
			}
		}
		first+=num;
		sort(choices.begin(),choices.end());
		for(int nxt: choices){
			int p = nxt;
			//cout << p << " ";
			while(k>0&&p>0){
				cur+=2;
				if(p==1)cur++;
				p--; k--;
			}
		}
		while(k>0&&first>0){
			cur+=2;
			first--;
			k--;
		}
		cout << cur << "\n";
	}
	return 0;
}