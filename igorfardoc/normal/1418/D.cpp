#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
set<int> a;
multiset<int> b;

void calc() {
	if(a.size() <= 2) {
		cout << "0\n";
		return;
	}
	int len = *(a.rbegin()) - *(a.begin());
	len -= *(b.rbegin());
	cout << len << '\n';
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	#ifdef _FILE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
	#endif
    int n, q;
    cin >> n >> q;
    vi mass(n);
    for(int i = 0; i < n; i++) {
    	cin >> mass[i];
    	a.insert(mass[i]);
    }
    sort(mass.begin(), mass.end());
    for(int i = 0; i < n - 1; i++) {
    	b.insert(mass[i + 1] - mass[i]);
    }
    calc();
    for(int o = 0; o < q; o++) {
    	int t, x;
    	cin >> t >> x;
    	if(t == 0) {
    		auto it = a.upper_bound(x);
    		int fir = -1;
    		int sec = -1;
    		if(it != a.end()) {
    			b.erase(b.find(*it - x));
    			fir = *it;
    		}
    		it = a.find(x);
    		if(it != a.begin()) {
    			--it;
    			b.erase(b.find(x - *it));
    			sec = *it;
    		}
    		if(fir != -1 && sec != -1) {
    			b.insert(fir - sec);
    		}
    		a.erase(a.find(x));
    	} else {
    		int fir = -1;
    		int sec = -1;
    		auto it = a.upper_bound(x);
    		if(it != a.end()) {
    			fir = *it;
    			b.insert(*it - x);
    		}
    		if(it != a.begin()) {
    			--it;
    			sec = *it;
    			b.insert(x - *it);
    		}
    		if(fir != -1 && sec != -1) {
    			b.erase(b.find(fir - sec));
    		}
    		a.insert(x);
    	}
    	calc();
    }
}