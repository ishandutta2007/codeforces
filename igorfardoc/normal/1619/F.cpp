#include<bits/stdc++.h>
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
    int t;
    cin >> t;
    while(t--) {
    	int n, m, k;
    	cin >> n >> m >> k;
    	int small = n / m;
    	int big = (n - 1) / m + 1;
    	int ambig = n % m;
    	int amsmall = m - ambig;
    	int playbig = big * ambig;
    	int playsmall = small * amsmall;
    	//cout << small << ' ' << big << ' ' << amsmall << ' ' << ambig << ' ' << playsmall << ' ' << playbig << endl;
    	vi now;
    	for(int i = 0; i < n; i++) {
    		now.push_back(i);
    	}
    	int pt = 0;
    	for(int o = 0; o < k; o++) {
    		vvi here(m);
    		/*if(n - pt < playbig) {
    			reverse(now.begin(), now.end());
    			pt = 0;
    		}*/
    		int stnow = 0;
    		if(n % m == 0) {
    			for(int i = 0; i < n; i++) {
	    			if(here[stnow].size() == small) {
	    				++stnow;
	    			}
	    			here[stnow].push_back(now[i]);
	    		}
	    	} else {
	    		for(int i = pt % n; i != (pt + playbig) % n; i=(i + 1) % n) {
	    			if(here[stnow].size() == big) {
	    				++stnow;
	    			}
	    			here[stnow].push_back(now[i]);
	    		}
	    		if(playbig != 0) {
	    			++stnow;
	    		}
	    		for(int i = (pt + playbig) % n; i != pt % n; i=(i + 1) % n) {
	    			if(here[stnow].size() == small) {
	    				++stnow;
	    			}
	    			here[stnow].push_back(now[i]);
	    		}
	    		pt += playbig;
	    	}
    		for(const auto& el : here) {
    			cout << el.size() << ' ';
    			for(const auto& el1 : el) {
    				cout << el1 + 1 << ' ';
    			}
    			cout << '\n';
    		}
    		//cout << endl;
    	}
    	cout << '\n';
    }
}