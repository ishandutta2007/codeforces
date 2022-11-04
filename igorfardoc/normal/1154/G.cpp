#include<bits/stdc++.h>
#define maxa 10000000
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
vi here[maxa + 1];


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
    vi a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        here[a[i]].push_back(i);
    }
    ll ans = 1000000000000000000ll;
    int id1, id2;
    for(int g = 1; g <= maxa; g++) {
        int minid = -1;
        int maxid = -1;
        for(int val = g; val <= maxa; val+=g) {
            if(here[val].empty()) continue;
            if(minid == -1) {
                minid = here[val][0];
            } else {
                maxid = here[val][0];
            }
            if(maxid != -1) break;
            if(here[val].size() > 1) {
                maxid = here[val][1];
                break;
            }
        }
        if(maxid == -1) continue;
        ll proz = (ll)a[minid] * a[maxid] / g;
        if(proz < ans) {
            ans = proz;
            id1 = minid;
            id2 = maxid;
        }
    }
    cout << min(id1, id2) + 1 << ' ' << max(id1, id2) + 1;
}