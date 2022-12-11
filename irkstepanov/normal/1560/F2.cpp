#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;

void upd(string& ans, const string& nx) {
    if (ans == "" || ans > nx) {
        ans = nx;
    }
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    //freopen("input.txt", "r", stdin);

    int tt;
    cin >> tt;

    while (tt--) {
        string n;
        int k;
        cin >> n >> k;
        set<char> setik;
        for (int i = 0; i < sz(n); ++i) {
            setik.insert(n[i]);
        }
        string ans = "";
        if (sz(setik) <= k) {
            ans = n;
        }
        for (int pref = 0; pref < sz(n); ++pref) {
            for (int d = n[pref] - '0' + 1; d < 10; ++d) {
                //cout << "!" << pref << " " << d << endl;
                setik.clear();
                string curr = "";
                for (int i = 0; i < pref; ++i) {
                    setik.insert(n[i]);
                    curr += n[i];
                }
                setik.insert(char(d + '0'));
                curr += char(d + '0');
                /*if (pref == 3 && d == 3) {
                    cout << "!" << sz(setik) << " " << k << endl;
                }*/
                if (sz(setik) > k) {
                    continue;
                }
                string saved = curr;
                char smallest = *setik.begin();
                while (sz(curr) < sz(n)) {
                    curr += smallest;
                }
                upd(ans, curr);

                curr = saved;
                if (sz(setik) < k) {
                    char smallest = '0';
                    while (sz(curr) < sz(n)) {
                        curr += smallest;
                    }
                    upd(ans, curr);
                }
            }
        }

        cout << ans << "\n";
    }
    
}