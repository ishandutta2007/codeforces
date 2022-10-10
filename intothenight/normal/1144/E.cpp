#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int k;
	string ss, tt;
	cin >> k >> ss >> tt;
	vector<int> s, t;
	for(int i = 0; i < k; i ++){
		s.push_back(ss[i] - 'a');
		t.push_back(tt[i] - 'a');
	}
	deque<int> q;
	int up = 0;
	for(int i = k - 1; i >= 0; i --){
		q.push_front((up + s[i] + t[i]) % 26);
		up = (up + s[i] + t[i]) / 26;
		if(!i){
			q.front() += up * 26;
		}
	}
	int down = 0;
	vector<int> res;
	for(int i = 0; i < k; i ++){
		res.push_back((down + q[i]) >> 1);
		down = ((down + q[i]) & 1) ? 26 : 0;
	}
	for(auto x: res){
		cout << (char) (x + 'a');
	}
	return 0;
}