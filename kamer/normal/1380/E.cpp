#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <queue>
#include <stack>
#include <math.h>
#include <array>
#include <functional>
#include <numeric>
#include <algorithm>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
#define LL_MAX 9223372036854775807
#define LL_MIN -9223372036854775806
#define read(to, thresh) for(int i=0; i < thresh; ++i) cin >> to[i];
 
template<class T>
void smin(T &a, T b) {a = min(a, b);}
template<class T>
void smax(T &a, T b) {a = max(a, b);}
template<class T>
T min(vector<T> &a) {return *min_element(a.begin(), a.end());}
template<class T>
T max(vector<T> &a) {return *max_element(a.begin(), a.end());}
template<class T>
void print(vector<T> &a, string sep) {for(T el: a) cout << el << sep; cout << endl;}
 
// pair<int, int> surrounding(set<int>::iterator it, set<int> s) {
//     pair<int, int> p;
//     if(it == s.begin()) {
//         cout << *it << endl;
//         p.first = -1;
//     }
//     else {
//         --it;
//         p.first = *it;
//         ++it;
//     }
    
//     it++;
//     if(it == s.end()) {
//         p.second = -1;
//     }
//     else {
//         p.second = *it;
//     }
//     return p;
// }
 
void solve() {
    int n, m; cin >> n >> m;
    vector<set<int>> t(m, set<int>());
    for(int i=1; i <= n; i++) {
        int x; cin >> x;
        t[x-1].insert(i);
    }
    int difficulty = 0;
    for(auto el: t) {
        int prev = -1;
        for(auto it = el.begin(); it != el.end(); it++) {
            if(prev != -1) {
                if(*it > prev + 1) {
                    difficulty++;
                }
            }
            prev = *it;
        }
        auto it = el.end();
        it--;
        if(*it != n) difficulty++;
    }
 
    cout << difficulty << endl; 
 
    for(int k=1; k < m; k++) {
        int a, b; cin >> a >> b;
        a--; b--;
        int l = t[a].size() <= t[b].size() ? a : b;
        int r = (a+b) - l;
 
        for(auto it = t[l].begin(); it != t[l].end(); it++) {
            t[r].insert(*it);
            pair<int, int> nums;
            if(it == t[l].begin()) {
                nums.first = -1;
            }
            else {
                --it;
                nums.first = *it;
                ++it;
            }
            
            it++;
            if(it == t[l].end()) {
                nums.second = -1;
            }
            else {
                nums.second = *it;
            }
            it--;
            
            if(
                nums.first != -1 && nums.second != -1 
                && nums.first + 1 == *it 
                && nums.second - 1 == *it
            ) {
                continue;
            }
 
            // we should consider it
            if(nums.first == -1) {
                auto itr = t[r].find(*it);
                if(itr != t[r].begin()){
                    itr--;
                    if(*itr == *it - 1) {
                        difficulty--;
                    }
                    itr++;
                }
                itr++;
                if (itr != t[r].end() && *itr == *it + 1) {
                    difficulty--;
                }
                itr--;


                //if(nums.second == -1) {
                //    // cout << "DEBUG " << *it << endl;
                //    itr++;
                //    if(itr != t[r].end() && *itr == *it + 1) {
                //        difficulty--;
                //    }
                //    itr--;
                //}
            }
            else if(nums.second == -1) {
                auto itr = t[r].find(*it);
                itr++;
                if(itr != t[r].end() && *itr == *it + 1) {
                    difficulty--;
                }
                //else if(itr == t[r].end()) {
                //    difficulty--;
                //}
                itr--; itr--;
                if(*itr + 1 == *it && *itr != nums.first) {
                    difficulty--;
                }
                itr++;
            }
            else {
                auto itr = t[r].find(*it);
                itr--;
                int prevnum = *itr;
                itr++; itr++;
                int nextnum = -1;
                if (itr != t[r].end()) nextnum = *itr;
                itr--;
                if(prevnum + 1 == *it && prevnum != nums.first) difficulty--;
                if(nextnum - 1 == *it) difficulty--;
                //if(prevnum + 1 == *it && *it == nextnum - 1 && prevnum != nums.first) {
                //    difficulty--;
                //}
            }
        }
 
        if(a != r) swap(t[a], t[r]);
 
        cout << difficulty << endl;
    }
 
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    // int t; cin >> t;
    
    // while(t--) {
        solve();
    // }
}