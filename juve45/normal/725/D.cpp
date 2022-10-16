#include <bits/stdc++.h>

#define dbg(x) cerr<<#x": "<<x<<"\n"
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(long long _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

#define st first
#define nd second

using namespace std;

const long long N = 300100;
long long n, k, m, c[N], w[N], ans = 1e9;

priority_queue <long long> pq;

vector <pair<long long, long long> > small;

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n;
	cin >> c[1] >> w[1];
	long long pos = 0, limit= 0 ;
	for(long long i = 2; i <= n; i++) {
		cin >> c[i] >> w[i];

		if(c[i] > c[1]) {
			pos++;
			pq.push(c[i] - w[i] - 1);
		} else  {
			limit = max(limit, c[i]);
			small.push_back({c[i], w[i]});
		}
	}

	sort(small.begin(), small.end());


	long long spare = c[1];
	if(!small.empty()) 
		spare -= small.back().st;

	// dbg(pos);
	ans = min(ans, pos + 1);
	while(!small.empty()) {

		while(!pq.empty() && spare + pq.top() >= 0) {
			pos--;
			ans = min(ans, pos + 1);
			spare += pq.top();
			pq.pop();
		}
		long long cost = small.back().st;
		// dbg(pos);	
		// dbg(ans);
		while(!small.empty() && cost == small.back().st) {
			pq.push({small.back().st - small.back().nd - 1});
			small.pop_back();
			pos++;
		}
		
		spare += cost;
		if(!small.empty()) 
			spare -= small.back().st;
	}

	while(!pq.empty() && spare + pq.top() >= 0) {
		pos--;
		ans = min(ans, pos + 1);
		spare += pq.top();
		pq.pop();
	}

		dbg(pos);	
		dbg(ans);
	cout << ans << '\n';


}