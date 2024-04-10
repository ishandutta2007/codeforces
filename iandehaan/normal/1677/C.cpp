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

#define MAXN 100'010
constexpr int inf = 1e9;

int par[MAXN];
int sizes[MAXN];

int getPar(int x) {
    if (par[x] == x) return x;
    return par[x] = getPar(par[x]);
}

void Union(int x, int y) {
    if (getPar(x) == getPar(y)) return;
    sizes[getPar(y)] += sizes[getPar(x)];
    par[getPar(x)] = getPar(y);
}

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        //cout << t << endl;
        int n;
        cin >> n;
        int a[n];
        int b[n];
        rep(i, 0, n) {
            cin >> a[i];
            a[i]--;
        }
        rep(i, 0, n) {
            cin >> b[i];
            b[i]--;
        }
        //cerr << "here" << endl;
        rep(i, 0, n) {
            par[i] = i;
            sizes[i] = 1;
        }

        rep(i, 0, n) {
            Union(a[i], b[i]);
        }

        vector<pii> comps;
        rep(i, 0, n) {
            if (i == getPar(i)) {
                comps.pb(mp(sizes[i], i));
                if (sizes[i] == 1) {
                    comps[sz(comps)-1].first = inf;
                }
            }
        }

        sort(all(comps));
        //reverse(all(comps));

        int usedleft = 0;
        int usedright = 0;

        ll out = 0;
        for (int ind = 0; ind < sz(comps); ind++) {
            int newsize = comps[ind].first;
            //cout << newsize << endl;
            if (comps[ind].first == inf) newsize = 1;
            //cout << "now " << newsize << endl;
            if (newsize % 2 == 1) newsize--;

            //cerr << "problem1 " << newsize << endl;


            vector<int> usinghere;
            while (newsize) {
                if (usedleft < usedright) {
                    usinghere.pb(usedleft+1);
                    usedleft++;
                } else {    
                    usinghere.pb(n-usedright);
                    usedright++;
                }

                newsize--;
            }
            //cerr << "problem " << newsize << endl;
            for (int i = 0; i+1 < sz(usinghere); i++) {
                //cout << usinghere[i] << ' ' << usinghere[i+1] << endl;
                out += abs(usinghere[i+1]-usinghere[i]);
            }
            if (sz(usinghere) > 1) {
                out += abs(usinghere[0]-usinghere[sz(usinghere)-1]);
            }
        }   
        cout << out << '\n';
    }
}