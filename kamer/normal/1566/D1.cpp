#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#include <queue>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <deque>
#include <string>
#include <utility>
#include <iomanip>
#include <fstream>
#include <cmath>
using namespace std;
typedef long long ll;

struct FT {
    vector<ll> s;
    FT(int n) : s(n) {}
    void update(int pos, ll dif) { // a [ pos ] += d i f
	for (; pos < s.size(); pos |= pos + 1) s[pos] += dif;
    }
    
    ll query(int pos) { // sum of values in [0 , pos)
	ll res = 0;
	for (; pos > 0; pos &= pos - 1) res += s[pos-1];
	return res;
    }
    
    int lower_bound(ll sum) {// min pos s t sum of [0 , pos ] >= sum
	// Returns n i f no sum i s >= sum, or 1 i f empty sum i s .
	if (sum <= 0) return -1;
	int pos = 0;
	for (int pw = 1 << 25; pw; pw >>= 1) {
	    if (pos + pw <= s.size() && s[pos + pw-1] < sum)
	    pos += pw, sum -= s[pos-1];
	}
	return pos;
    }
};

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed << setprecision(14);
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<FT> fen_tree(n, FT(m));;

        vector<int> ax(n * m);
        for (int i = 0; i < n * m; i++) cin >> ax[i];
        vector<int> a = ax;

        sort(a.begin(), a.end());
        int currentIndex = 0;
        unordered_map<int, int> rev_map;
        vector<int> counts;

        for (int i = 0; i < n * m; i++) {
            if (rev_map.find(a[i]) == rev_map.end()) {
                counts.push_back(0);
                rev_map[a[i]] = currentIndex;
                currentIndex++;
            }
            counts[currentIndex - 1]++;
        }

        vector<int> currentPos(currentIndex, 0);
        vector<vector<int>> pos(currentIndex, vector<int>());

        int currentCount = 0;
        for (int i = 0; i < currentIndex; i++) {
            int finalCount = currentCount + counts[i];
            if ((finalCount - 1) / m == currentCount / m) {
                for (int j = finalCount - 1; j >= currentCount; j--) {
                    pos[i].push_back(j);
                }
            } else {
                while (currentCount / m != (finalCount - 1) / m) {
                    for (int j = (currentCount / m) * m + m - 1; j >= currentCount; j--) {
                        pos[i].push_back(j);
                    }
                    currentCount = (currentCount / m) * m + m;
                }

                for (int j = finalCount - 1; j >= currentCount; j--) {
                    pos[i].push_back(j);
                }
            }

            currentCount = finalCount;
        }
        
        ll res = 0;
        for (int i = 0; i < n * m; i++) {
            int index = rev_map[ax[i]];
            int position = pos[index][currentPos[index]];
            currentPos[index]++;

            int pos_n = position / m;
            int pos_m = position % m;

            fen_tree[pos_n].update(pos_m, 1);
            ll x = fen_tree[pos_n].query(pos_m);
            res += x;
            // cout << "T " << i << " " << position << " " << x << "\n";
        }

        cout << res << "\n";

    }
}