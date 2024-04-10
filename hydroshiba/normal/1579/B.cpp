#include "bits/stdc++.h"
using namespace std;

void shift(int l, int r, int d, vector<int> &arr){
	vector<int> vec(arr.begin() + l, arr.begin() + r + 1);

	int n = r - l + 1;
	for(int i = 0; i < d; ++i) vec.push_back(vec[i]);
	vec.erase(vec.begin(), vec.begin() + d);

	for(int i = l; i <= r; ++i) arr[i] = vec[i - l];
}

void solve(){
	int n;
	cin >> n;

	vector<int> arr(n);
	for(int &i : arr) cin >> i;
	int lastpos = n - 1;
	queue<int> l, r;

	for(int i = 0; i < n; ++i){
		int pos = (max_element(arr.begin(), arr.begin() + lastpos + 1) - arr.begin());
		if(pos == lastpos){
			--lastpos;
			continue;
		}
		shift(pos, lastpos, 1, arr);
		l.push(pos + 1);
		r.push(lastpos + 1);
		--lastpos;
	}

	cout << l.size() << '\n';
	while(!l.empty()){
		cout << l.front() << ' ' << r.front() << " 1\n";
		l.pop();
		r.pop();
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t;
	cin >> t;

	while(t--)
		solve();
}