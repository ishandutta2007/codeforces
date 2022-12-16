#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define pb push_back
#define mp make_pair

#define MAXN 200'010

// (pos, intensity), ind
pair<pair<ll, ll>, int> a[MAXN];
ll mins[MAXN];

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n;
        ll m;
        cin >> n >> m;
        rep(i, 0, n) {
            cin >> a[i].first.first >> a[i].first.second;
            a[i].second = i;
        }
        sort(a, a+n); // sort by position
        map<ll, ll> rainamt;
        multiset<ll> values;
        ll sm = 0;
        rep(i, 0, n) {
            rainamt[a[i].first.first] += a[i].first.second;
            

            if (i == 0 || a[i-1].first.first != a[i].first.first) {
                while (!values.empty() && (*begin(values) <= a[i].first.first)) {
                    sm -= *begin(values);
                    values.erase(begin(values)); // remove too-small elements

                }

                ll amtleft = sm - a[i].first.first*sz(values);
                rainamt[a[i].first.first] += amtleft;
            }

            

            values.insert(a[i].first.second+a[i].first.first);
            sm += a[i].first.second + a[i].first.first;
        }

        //for (auto x : rainamt) cout << x.first << ' ' << x.second << endl;

        //cout << "now back" << endl;

        // now backwards
        values.clear();
        sm = 0;
        ll startpos = a[n-1].first.first;
        for (int i = n-1; i >= 0; i--) {
            if (i == n-1 || a[i+1].first.first != a[i].first.first) {
                while (!values.empty() && (*begin(values) <= (startpos-a[i].first.first))) {
                    sm -= *begin(values);
                    values.erase(begin(values)); // remove too-small elements

                }

                //cout << i << ' ' << sm << ' ' << a[i].first.first << endl;

                ll amtleft = sm - (startpos-a[i].first.first)*sz(values);
                rainamt[a[i].first.first] += amtleft;
            }

            values.insert(a[i].first.second+(startpos-a[i].first.first));
            sm += a[i].first.second + (startpos-a[i].first.first);
            //cout << "inserted " << a[i].first.second + (startpos-a[i].first.first) << endl;
        }

        //for (auto x : rainamt) cout << x.first << ' ' << x.second << endl;

        //cout << "post" << endl;

        
        ll curmin = -1e10;
        rep(i, 0, n) {
            
            if (i == 0 || a[i-1].first.first != a[i].first.first) {
                ll neededdec = rainamt[a[i].first.first]-m;
                //cout << a[i].first.first << ' ' << rainamt[a[i].first.first] << ' ' << neededdec << endl;
                if (neededdec > 0) {
                    // our position must go down by neededdec
                    // so 0 must go down by neededdec - a[i].first.first
                    curmin = max(curmin, neededdec - a[i].first.first);
                }
            }

            //cout << "curmin " << curmin << endl;
            mins[i] = curmin + a[i].first.first;

            //cout << i << ' ' << mins[i] << endl;
        }
        //cout << "between" << endl;

        curmin = -1e10;
        for (int i = n-1; i >= 0; i--) {
            

            if (i == n-1 || a[i+1].first.first != a[i].first.first) {
                ll neededdec = rainamt[a[i].first.first]-m;

                if (neededdec > 0) {
                    curmin = max(curmin, neededdec - (startpos-a[i].first.first));
                }
            }

            mins[i] = max(mins[i], curmin + (startpos-a[i].first.first));

            //cout << i << ' ' << mins[i] << endl;
        }

        string out;
        rep(i, 0, n) out.pb('0');
        rep(i, 0, n) {
            if (mins[i] <= a[i].first.second) {
                out[a[i].second] = '1';
            }
        }
        cout << out << '\n';
    }
}