#include <bits/stdc++.h>
 
#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define mp make_pair
#define pb push_back
 
using namespace std;
 
typedef pair<int, int> pii;
typedef long long ll;
 
int main() 
{
    
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    
    vector<vector<string> > v(20);
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        v[sz(s)].pb(s);
        sum += sz(s);
    }
    
    char d;
    cin >> d;
    
    sum += (n / 2);
    int len = sum / (n / 2);
    
    for (int i = 0; i < 20; ++i) {
        sort(all(v[i]));
    }
    
    vector<string> ans;
    for (int i = 0; i < 20 && len - i - 1 >= i; ++i) {
        if (v[i].empty()) {
            continue;
        }
        int x = i, y = len - i - 1;
        if (x == y) {
            for (int j = 0; j < sz(v[i]); j += 2) {
                string tmp = v[i][j];
                tmp += d;
                tmp += v[i][j + 1];
                ans.pb(tmp);
            }
        } else {
            for (int j = 0; j < sz(v[x]); ++j) {
                string t1 = v[x][j];
                t1 += d;
                t1 += v[y][j];
                string t2 = v[y][j];
                t2 += d;
                t2 += v[x][j];
                ans.pb(min(t1, t2));
            }
        }
    }
    
    sort(all(ans));
    
    for (int i = 0; i < sz(ans); ++i) {
        cout << ans[i] << "\n";
    }
    
}