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
    	int n;
    	cin >> n;
    	vi a(n);
    	multiset<int> s1, s2;
    	for(int i = 0; i < n; i++) {
    		cin >> a[i];
    		if(a[i] % 2 == 0) {
    			s1.insert(a[i]);
    		} else {
    			s2.insert(a[i]);
    		}
    	}
    	ll a1 = 0;
    	ll a2 = 0;
    	for(int i = 0; i < n; i++) {
    		int last1 = -1;
    		int last2 = -1;
    		if(s1.size() != 0) {
    			last1 = *(s1.rbegin());
    		}
    		if(s2.size() != 0) {
    			last2 = *(s2.rbegin());
    		}
    		if(last1 >= last2) {
    			s1.erase(s1.find(last1));
    			if(i % 2 == 0) {
    				a1 += last1;
    			}
    		} else {
    			s2.erase(s2.find(last2));
    			if(i % 2 == 1) {
    				a2 += last2;
    			}
    		}
    	}
    	if(a1 > a2) {
    		cout << "Alice\n";
    	} else if(a1 < a2) {
    		cout << "Bob\n";
    	} else {
    		cout << "Tie\n";
    	}
    }
}