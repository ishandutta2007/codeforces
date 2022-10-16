#include <bits/stdc++.h>
#define mp make_pair
#define pb emplace_back
#define fi first
#define se second
#define int long long
#define inf 1e18
#define ick cout<<"ickbmi32.9\n"
using namespace std;
bool isprime(int k) {
    for(int i = 2; i <= sqrt(k); i++) if(k % i == 0) return false; 
    return true;
}
int bm(int a, int b, int mod) {
    if(b == 0) return 1;
    int t = bm(a, b / 2, mod); 
    t = t * t % mod; 
    return (b % 2 == 1 ? t * a % mod : t);
}
int inv(int a, int mod) {return bm(a, mod - 2, mod);}
void gay(int TC) {cout << "Case #" << TC << ": ";}
int dsu[35];
bool yes[35];
set<int> stuff[36];
int f(int x) {
    if(x == dsu[x]) return x;
    return dsu[x] = f(dsu[x]);
}
void merge(int a, int b) {
    dsu[f(a)] = f(b);
}
void solve(int TC) {
    int n;
    cin >> n;
    int cc = 0;
    int arr[n + 5];
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
        if(arr[i] == 0) {
            arr[i]++;
            cc++;
        }
    }
    int cn = 0;
        for(int i = 0; i <= 30; i++) yes[i] = false;
        for(int i = 0; i <= 30; i++) stuff[i].clear();
        for(int i = 0; i <= 30; i++) dsu[i] = i;
        // for(int i = 0; i <= 30; i++) sth[i].insert(i);
        
        for(int i = 0; i < n; i++) {
            int ls = -1;
            for(int j = 0; j < 30; j++) {
                if(arr[i] & (1 << j)) {
                    yes[j] = true;
                    if(ls != -1) merge(f(j), f(ls));
                    ls = j;
                }
            }
        }
        cn = 0;
        int mx = 0;
        for(int i = 0; i < 30; i++) {
            if(yes[i]) stuff[f(i)].insert(i);
        }
        for(int i = 0; i < 30; i++) {
            cn += (stuff[i].size() > 0);
        }
        int mi = 99;
        for(int i = 0; i < 30; i++) {
            if (stuff[i].size() > 0) {
                mi = min(mi, *(stuff[i].begin()));
            }
        }
        if(cn == 2 && mi == 0) {
            for(int i = 0; i < 30; i++) {
                if (stuff[i].size() > 0) {
                    mx = max(mx, *(stuff[i].begin()));
                }
            }
            int kk = (1 << mx);
            for(int i = 0; i < n; i++) {
                if(arr[i] & kk) {
                    arr[i]++;
                    kk = 0;
                }
            }
            cc++;
        }
        else if(cn > 1) {
            for(int i = 0; i < 30; i++) {
                if (stuff[i].size() > 0) {
                    mx = max(mx, *(stuff[i].begin()));
                }
            }
            int kk = 0;
            for(int i = 0; i < 30; i++) {
                if(*(stuff[i].begin()) == mx) {
                    for(auto x: stuff[i]) kk |= (1 << x);
                }
            }
            int xx = -1, id = -1, cn = 1;
            vector<int> tr;
            for(int i = 0; i < n; i++) {
                if(arr[i] & kk) {
                    if(arr[i] > xx) {
                        tr.pb(i);
                    }   
                    else if(arr[i] == xx) cn++;
                }
            }
            bool done = false;
            cc++;
            for(auto x: tr) {
                arr[x]--;
                cn = 0;
                for(int i = 0; i <= 30; i++) yes[i] = false;
                for(int i = 0; i <= 30; i++) stuff[i].clear();
                for(int i = 0; i <= 30; i++) dsu[i] = i;
                // for(int i = 0; i <= 30; i++) sth[i].insert(i);
                
                for(int i = 0; i < n; i++) {
                    int ls = -1;
                    for(int j = 0; j < 30; j++) {
                        if(arr[i] & (1 << j)) {
                            yes[j] = true;
                            if(ls != -1) merge(f(j), f(ls));
                            ls = j;
                        }
                    }
                }
                cn = 0;
                int mx = 0;
                for(int i = 0; i < 30; i++) {
                    if(yes[i]) stuff[f(i)].insert(i);
                }
                for(int i = 0; i < 30; i++) {
                    cn += (stuff[i].size() > 0);
                }
                if(cn == 1) {
                    done = true;
                    break;
                }
                arr[x]++;
            }
            // cout << done << '\n';
            if(!done) {
                cc++;
                int k = tr[0];
                int ah = (arr[k] & -arr[k]);
                arr[k]--;
                // int ad = 1;
                for(int i = 0; i < n; i++) {
                    if(arr[i] & ah) {
                        arr[i]++;
                        break;
                    }
                }
            }
        }
    cout << cc << '\n';
    for(int i = 0; i < n; i++) cout << arr[i] << ' ';
    cout << '\n'; 
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