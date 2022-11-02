#include <iostream>
#include <string>
#include <stack>
#include <utility>
using namespace std;

stack<pair<long long, long long> > st;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);	
	int n; cin >> n;
	long long c = 0, op = (1LL << 32LL) - 1;
	st.push(make_pair(1, 0));
	bool of = false;
	for (int i = 0; i < n; i++) {
		string s; cin >> s;
		if (of) continue;
		if (s[0] == 'f') {
			long long p; cin >> p;
			st.push(make_pair(p, 0));
		}
		else if (s[0] == 'a') 
			st.top().second++;
		else {
			long long t = st.top().first * st.top().second;
			st.pop(); st.top().second += t;
		}
		if (st.top().second > op || st.top().first * st.top().second > op) {
			of = true;
		}
	}
	if (of) cout << "OVERFLOW!!!" << '\n';
	else cout << st.top().second << '\n';
	return 0;
}