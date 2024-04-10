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

#define MAXM 100'010

int a[MAXM];

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<int> gapsize(m);
        rep(i, 0, m) {
            cin >> a[i];
            a[i]--;
        }
        sort(a, a+m);
        rep(i, 0, m-1) {
            gapsize[i] = a[i+1]-a[i]-1;
        }
        gapsize[m-1] = (a[0]+n)-a[m-1]-1;

        sort(all(gapsize));
        reverse(all(gapsize));

        ll out = m;
        ll dayspassed = 0;
        rep(i, 0, m) {
            if (dayspassed*2 >= gapsize[i]) {
                out += gapsize[i];
            } else if (dayspassed*2 == gapsize[i]-1) {
                // eat one
                out += gapsize[i] - 1;
                dayspassed++;
            } else {
                ll covered = dayspassed*2;
                // now eat one
                dayspassed++;
                // still expands from other side
                covered++;
                // eat another
                dayspassed++;
                out += covered;
            }
        }
        cout << out << '\n';

    }
}