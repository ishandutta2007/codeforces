#include <bits/stdc++.h>
#define mp make_pair
#define pb emplace_back
#define fi first
#define se second
#define ick cout<<"ickbmi32.9\n"
using namespace std;
void solve() {
    int n, q;
    cin >> n >> q;
    int arr[n + 5];
    unordered_map<int, int> pfid;
    for(int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    pair<int, int> lim[n + 5];
    int l = 1, ol = 1;
    for(int r = 1; r <= n; r++) {
        unordered_set<int> fc;
        fc.clear();
        for(int i = 2; i <= sqrt(arr[r]); i++) {
            while(arr[r] % i == 0) {
                fc.insert(i);
                arr[r] /= i;
            }
        }
        if(arr[r] > 1) fc.insert(arr[r]);
        for(auto x: fc) {
            //cout << r << ' ' << x << '\n';
            l = max(l, pfid[x] + 1);
            pfid[x] = r;
        }
        for(int i = ol; i < l; i++) lim[i].se = r - 1;
        lim[r].fi = l;
        ol = l;
    }
    for(int i = ol; i <= n; i++) lim[i].se = n;
    //for(int i = 1; i <= n; i++) cout << lim[i].fi << " a " << lim[i].se << '\n';
    int pos[n + 5][20];
    for(int i = 1; i <= n; i++) {
        pos[i][0] = lim[i].se;
    }
    for(int i = 1; i <= 17; i++) {
        for(int j = 1; j <= n; j++) {
            pos[j][i] = pos[min(n, pos[j][i - 1] + 1)][i - 1];
            //cout << pos[j][i] << ' ';
        }
        //cout << '\n';
    }
    int pos2[n + 5][20];
    for(int i = 1; i <= n; i++) {
        pos2[i][0] = lim[i].fi;
    }
    for(int i = 1; i <= 17; i++) {
        for(int j = 1; j <= n; j++) {
            pos2[j][i] = pos2[max(1, pos2[j][i - 1] - 1)][i - 1];
            //cout << pos[j][i] << ' ';
        }
        //cout << '\n';
    }
    int ll, rr;
    while(q--) {
        cin >> ll >> rr;
        l = ll;
        int ans1 = 0, ans2 = 0;
        for(int i = 17; i >= 0; i--) {
            if(pos[ll][i] < rr) {
                ll = pos[ll][i] + 1;
                ans1 += (1 << i);
            }
        }
        ll = l;
        for(int i = 17; i >= 0; i--) {
            if(pos2[rr][i] > ll) {
                rr = pos[rr][i] - 1;
                ans2 += (1 << i);
            }
        }
        cout << min(ans1, ans2) + 1 << '\n';
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t;
    
    t = 1;
    //cin >> t;
    
    while(t--) solve();
    return 0;
}