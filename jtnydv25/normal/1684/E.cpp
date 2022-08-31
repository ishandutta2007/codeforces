#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int, int>
#define all(c) ((c).begin()), ((c).end())
#define sz(x) ((int)(x).size())

#ifdef LOCAL
#include <print.h>
#else
#define trace(...)
#define endl '\n' // remove in interactive
#endif

int main(){
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL); // Remove in interactive problems
	int t; cin >> t;
	while(t--){
		int n, k; cin >> n >> k;
		vector<int> a(n);
		map<int, int> freq;
		for(int& x: a){
			cin >> x;
			freq[x]++;
		}

		vector<int> freq_count(n + 1);
		for(auto it: freq) freq_count[it.second]++;

		int sum = 0;
		int pos = 1;
		int m = 0;
		int ans = n;
		int tot = freq.size();

		for(int h = 0; h <= n; h++){
			// mex = h
			while(pos <= n && sum + freq_count[pos] * pos < k){
				sum += freq_count[pos] * pos;
				tot -= freq_count[pos];
				pos++;
			}
			int nxt = pos == n + 1 ? 0 : freq_count[pos] * pos;
			// trace(h, pos, sum, nxt);
			if(m > k){
				break;
			}
			if(sum + nxt < k){
				// trace(h);
				ans = min(ans, 0);
			}
			else{
				// if(h != 0)
					ans = min(ans, tot - (k - sum) / pos);
			}
			int c = freq.find(h) == freq.end() ? 0 : freq[h];
			if(c == 0) m++;
			if(c < pos) sum -= c;
			else tot--;
			freq_count[c]--;
		}
		cout << ans << endl;
	}
}