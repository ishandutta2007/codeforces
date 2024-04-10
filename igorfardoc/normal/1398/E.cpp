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
    int n;
    cin >> n;
    multiset<pair<pair<int, int>, int>> s;
    multiset<int> balls;
    ll sum = 0;
    ll sumback = 0;
    pair<pair<int, int>, int> last = {{-1, -1}, -1};
    int ammoln = 0;
    for(int i = 0; i < n; i++) {
    	int t, d;
    	cin >> t >> d;
    	sum += d;
    	//cout << "Start" << endl;
    	if(t == 0) {
    		if(d > 0) {
    			balls.insert(d);
    			pair<pair<int, int>, int> here = {{d, t}, i};
    			s.insert(here);
    			if(last.first.first != -1) {
    				if(here > last) {
    					sumback -= last.first.first;
    					last = *(s.upper_bound(last));
    					sumback += here.first.first;
    				}
    			}
    		} else {
    			d = -d;
    			balls.erase(balls.find(d));
    			auto it = s.lower_bound({{d, t}, 0});
    			auto here = *it;
    			s.erase(it);
    			if(last.first.first != -1) {
    				if(here >= last) {
    					sumback -= here.first.first;
    					last = *(--s.lower_bound(last));
    					sumback += last.first.first;
    				}
    			}
    		}
    	} else {
    		if(d > 0) {
    			ammoln++;
    			pair<pair<int, int>, int> here = {{d, t}, i};
    			s.insert(here);
    			if(last.first.first == -1) {
    				last = *(--s.end());
    				sumback = last.first.first;
    			} else {
    				if(here > last) {
    					sumback += here.first.first;
    				} else {
    					last = *(--s.find(last));
    					sumback += last.first.first;
    				}
    			}
    		} else {
    			d = -d;
    			ammoln--;
    			auto it = s.lower_bound({{d, t}, 0});
    			auto here = *it;
    			s.erase(it);
    			if(ammoln == 0) {
    				sumback = 0;
    				last = {{-1, -1}, -1};
    			} else {
    				if(here >= last) {
    					sumback -= here.first.first;
    					last = *(s.lower_bound(last));
    				} else {
    					sumback -= last.first.first;
    					last = *(s.upper_bound(last));
    				}
    			}
    		}
    	}
    	//cout << "End" << endl;
    	ll ans = sum;
    	if(ammoln == 0) {
    		cout << ans << '\n';
    		continue;
    	}
    	if(!balls.empty() && *(balls.rbegin()) >= last.first.first) {
    		ans += sumback;
    	} else {
    		ans += sumback - last.first.first;
    		if(!balls.empty()) {
    			ans += *(balls.rbegin());
    		}
    	}
    	cout << ans << '\n';
    }
}