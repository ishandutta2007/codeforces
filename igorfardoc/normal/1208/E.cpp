#include<bits/stdc++.h>
#define INF 1000000001
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;



int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	#ifdef _FILE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
	#endif
    int n, w;
    cin >> n >> w;
    vector<ll> ans(w, 0);
    vector<ll> sum(w + 1, 0);
    for(int i = 0; i < n; i++) {
    	int c;
    	cin >> c;
    	vi a(c);
    	for(int j = 0; j < c; j++) {
    		cin >> a[j];
    	}
    	if(c * 2 >= w) {
    		vector<int> here(w, -INF);
    		for(int i = 0; i < w - c; i++) {
    			here[i] = 0;
    			here[w - i - 1] = 0;
    		}
    		multiset<int> s;
    		for(int i = 0; i < w; i++) {
    			if(i < c) {
    				s.insert(a[i]);
    			}
    			if(i > w - c) {
    				s.erase(s.find(a[i - (w - c) - 1]));
    			}
    			here[i] = max(here[i], *(s.rbegin()));
    		}
    		for(int i = 0; i < w; i++) {
    			ans[i] += here[i];
    		}
    		continue;
    	}
    	int mx = 0;
    	for(int j = 0; j < c; j++) {
    		mx = max(mx, a[j]);
    		ans[j] += mx;
    	}
    	mx = 0;
    	for(int j = c - 1; j >= 0; j--) {
    		mx = max(mx, a[j]);
    		ans[w + j - c] += mx;
    	}
    	sum[c] += mx;
    	sum[w - c] -= mx;
    }
    ll now = 0;
    for(int i = 0; i < w; i++) {
    	now += sum[i];
    	ans[i] += now;
    	cout << ans[i] << ' ';
    }

}