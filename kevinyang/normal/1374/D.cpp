#include <bits/stdc++.h>
using namespace std;
int main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		int n,k;
		cin >> n >> k;
		vector<int>arr(n);
		for(int i = 0; i<n; i++){
			cin >> arr[i];
			arr[i] = k-(arr[i]%k);
			arr[i]%=k;
		}
		set<int>rems;
		for(int i = 0; i<n; i++){
			if(arr[i]!=0)
			rems.insert(arr[i]);
		}
		map<int,int>counts;
		for(int nxt:rems){
			counts[nxt] = 0;
		}
		for(int i = 0; i<n; i++){
			if(arr[i]!=0){
				counts[arr[i]] = counts[arr[i]]+1;
			}
		}
		int num = 0;
		int count = 0;
		for(int nxt:rems){
			if(counts[nxt]>=count){
				count = counts[nxt]; num = nxt;
			}
		}
		//cout << count << " " << num << "\n";
		if((long long)(max(count-1,0))*(long long)(k)+num==0){
			cout << "0\n"; continue;
		}
		cout << (long long)(max(count-1,0))*(long long)(k)+num+1<< "\n";
	}
	return 0;
}