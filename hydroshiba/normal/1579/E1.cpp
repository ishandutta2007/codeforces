#include "bits/stdc++.h"
using namespace std;

void solve(){
	int n;
	cin >> n;

	deque<int> q;

	while(n--){
		int val;
		cin >> val;

		if(q.front() > val) q.push_front(val);
		else q.push_back(val);
	}

	while(!q.empty()) cout << q.front() << ' ', q.pop_front();
	cout << '\n';
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t;
	cin >> t;

	while(t--) solve();
}