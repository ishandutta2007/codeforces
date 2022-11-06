#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int n,k;
	cin >> n >> k;
	vector<int>arr;
	for(int i = 1; i<=n; i++){
		arr.push_back(i);
		arr.push_back(i);
	}
	int mn = 0;
	for(int i = 0; i<n; i++){
		mn+=arr[i];
	}
	int mx = n*(n+1)-mn;
	mn = n*(n+1)/2;
	//cout << mn << " " << mx << "\n";
	if(k<mn){
		cout <<"-1\n";
		return 0;
	}
	int want = min(mx,k);
	vector<int>val;
	for(int i = n; i<2*n; i++){
		val.push_back(arr[i]);
	}
	sort(val.begin(),val.end());
	int rqminus = mx-want;
	for(int i = 0; i<n; i++){
		if(rqminus==0)break;
		if(rqminus>=val[i]-(i+1)){
			rqminus-=val[i]-(i+1);
			val[i] = i+1;
		}
		else{
			while(rqminus>0){
				rqminus--;
				val[i]--;
			}
		}
	}
	/*
	for(int i = 0; i<n; i++){
		cout << val[i] << " ";	
	}
	cout << "nae\n";
	*/
	vector<int>ans(n);
	vector<int>ans2(n);
	queue<int>q;
	for(int i = 0; i<n; i++){
		if(i%2==0){
			ans[i] = val[i];
		}
		else{
			ans2[i] = val[i];
		}
	}
	vector<int>freq(n+1,2);
	for(int i = 0; i<n; i++){
		freq[val[i]]--;
	}
	for(int i = 1; i<=n; i++){
		for(int j = 0; j<freq[i]; j++){
			q.push(i);
		}
	}
	for(int i = 0; i<n; i++){
		if(ans[i]==0)ans[i] = q.front();
		else ans2[i] = q.front();
		q.pop();
	}
	cout << want << "\n";
	for(int i = 0; i<n; i++){
		cout << ans[i] << " ";
	}
	cout << "\n";
	for(int i = 0; i<n; i++){
		cout << ans2[i] << " ";
	}
	cout << "\n";
	return 0;
}