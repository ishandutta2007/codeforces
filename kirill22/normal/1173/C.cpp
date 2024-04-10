#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
	int n;
	cin >> n;
	map<int,int> m;
	vector<int> a(n), b(n);
	for(int i = 0;i < n;i++){
		cin >> a[i];
		if(a[i] != 0){
			m[a[i]] = -1;
		}
	}
	int ind = 0;
	for(int i = 0;i < n;i++){
		cin >> b[i];
		if(b[i] != 0){
			m[b[i]] = i + 1;
		}
		
	}
	int ansi;
	if(m[1] == -1){
		ansi = n;
	}
	else{
		ansi = m[1] - 1;
	}
	set<int> s;
	for(int i = 0;i < n;i++){
		if(a[i] != 0){
			s.insert(a[i]);
		}
	}
	deque<int> B;
	for(int i = 0;i < n;i++){
		B.push_back(b[i]);
	}
	bool fi = true;
	for(int i = 0; i <  ansi;i++){
		if(s.size() == 0){
			fi = false;
			break;
		}
		int x = B.front();
		B.pop_front();
		int y = *s.begin();
		s.erase(s.begin());
		B.push_back(y);
		if(x != 0){
			s.insert(x);
		}
		
	}
	int k = 0;
	for(auto c : B){
		k++;
		if(c != k){
			fi = false;
		}
	}
	if(fi){
		cout << ansi;
		return 0;
	}
	int ans = 0;
	for(int i = 1;i <= n;i++){
		if(m[i] == -1){
			ans = max(ans, n - i + 1);
		}
		else{
			ans = max(ans, n + m[i] - i + 1);
		}
	}
	cout << ans;
}