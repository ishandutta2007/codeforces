#include<bits/stdc++.h>
using namespace std;

inline void Main(){
	int n,k;
	cin >> n >> k;
	vector<int> a;
	for(int i=1;i<=n;i++){
		int x;cin >> x;
		if(a.empty() || a.back()!=x)a.push_back(x);
	}
	int cur=1,ans=1;
	for(size_t i=1;i<a.size();i++){
		// cout << a[i] << endl;
		cur ++;
		if(cur > k){
			cur = 2, ans ++;
		}
		if(cur > k){
			ans = -1;break;
		}
		// cout << cur << ":" << ans << endl;
	}
	cout << ans << endl;
}

int main()
{
	int T;
	cin >> T;
	while(T--){
		Main();
	}
}