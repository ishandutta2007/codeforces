#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define mp make_pair
#define pb emplace_back
#define fi first
#define se second
#define int long long
#define inf 1e18
#define ick cout<<"ickbmi32.9\n"
using namespace std;

stack<int> c8k;
unordered_map<int, int> need;
void solve(int TC) {
    need.clear();
    int n, t;
    cin >> n;
    int nn = n;
    int tot = 0;
    while(n--) {
        cin >> t;
        need[t]++;
        tot += t;
    }
    while(!c8k.empty()) c8k.pop();
    c8k.push(tot);
    bool can = true;
    while(!c8k.empty()) {
        if(c8k.size() > nn) {
            can = false;
            break;
        }
        int now = c8k.top();
        c8k.pop();
        if(need[now] > 0) {
            need[now]--;
            nn--;
            // break;
        }
        else {
            if(now == 1) {
                can = false;
                break;
            }
            else {
                int l = now / 2;
                int r = now / 2 + now % 2;
                c8k.push(l);
                c8k.push(r);
            }
        }
    }
    if(can && c8k.empty()) {
        cout << "YES\n";
    }
    else cout << "NO\n";
    // bool can = true;
    // while(pq.size() > 1) {
    //     int a = pq.top();
    //     pq.pop();
    //     int b = pq.top();
    //     pq.pop();
    //     if(abs(b - a) > 1) {can = false; break;}
    //     pq.push(a + b);
    // }
    // if(can && pq.size() == 1) {
    //     cout << "YES\n";
    // }
    // else cout << "NO\n";
}
signed main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(0); cout.tie(0);
    int t = 1;  
    cin >> t; // REMOVE THIS LINE IF ONLY 1 CASE
    //while(t--) solve();
    for(int i = 1; i <= t; i++) solve(i);
    return 0;
}