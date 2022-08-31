#include <bits/stdc++.h>
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
using namespace std;
using lint = long long;
using pi = pair<lint, lint>;
const int MAXN = 1600;

lint query(int s, int e){
	cout << "? " << s << " " << e << endl;
	lint x; cin >> x; return x;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		vector<lint> a(n + 1);
		for(int i = 1; i <= n; i++) cin >> a[i];
		// even negated
		for(int i = 2; i <= n; i += 2) a[i] *= -1; 
		for(int i = 1; i <= n; i++) a[i] += a[i - 1];
		lint ans = 0;
		vector<pi> cnts;
		for(int i = 1; i <= n; i++) cnts.emplace_back(a[i], i);
		sort(all(cnts));
		vector<pi> stk[2];
		for(int i = n; i; i--){
			pi val(a[i], i);
			if(i % 2 == 0) val.first *= -1;
			while(sz(stk[i % 2]) && stk[i % 2].back().first >= val.first) stk[i % 2].pop_back();
			stk[i % 2].push_back(val);
			int lastpos = n;
			{
				auto l = lower_bound(all(stk[0]), pi(-a[i - 1], -1));
				if(l != stk[0].begin()) lastpos = min(lastpos, (int)prev(l)->second - 1);
			}	
			{

				auto l = lower_bound(all(stk[1]), pi(a[i - 1], -1));
				if(l != stk[1].begin()) lastpos = min(lastpos, (int)prev(l)->second - 1);
			}
			/*
			   for(int j = i; j <= n; j++){
			   if(j % 2 == 0 && a[j] > a[i - 1]) break;
			   if(j % 2 == 1 && a[j] < a[i - 1]) break;
			   lastpos = j;
			}*/
			auto s = lower_bound(all(cnts), pi(a[i - 1], i));
			auto e = upper_bound(all(cnts), pi(a[i - 1], lastpos));
			ans += e - s;
		}
		cout << ans << endl;
	}
}