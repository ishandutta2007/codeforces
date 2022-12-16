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

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n, d12, d23, d13;
        cin >> n >> d12 >> d23 >> d13;

        // special case: don't stick it off, just put it in middle
        if (d13 + d23 == d12) {
            cout << "YES\n";
            int currextra = 4;
            vi mainpath;
            mainpath.pb(1);
            while (sz(mainpath) < d13) {
                mainpath.pb(currextra);
                currextra++;
            }
            mainpath.pb(3);
            while (sz(mainpath) < d12) {
                mainpath.pb(currextra);
                currextra++;
            }
            mainpath.pb(2);
            while (currextra <= n) {
                mainpath.pb(currextra);
                currextra++;
            }

            rep(i, 0, sz(mainpath)-1) {
                cout << mainpath[i] << ' ' << mainpath[i+1] << '\n';
            }
            continue;
        }

        int numused = d12 + 1; // path 1 -> 2

        bool found = false;
        rep(i, 0, numused) {
            //cout << "trying " << i << endl;
            // try sticking it off anywhere
            int distfrom1 = i-0;
            int distfrom2 = (numused-1)-i;
            if (distfrom1 >= d13 || distfrom2 >= d23) continue;
            //cout << distfrom1 << ' ' << distfrom2 << endl;

            int slack1 = d13-distfrom1;
            int slack2 = d23-distfrom2;
            //cout << slack1 << ' ' << slack2 << endl;
            if (slack1 != slack2) continue; 
            int neededverts = slack1;
            if (neededverts + numused > n) continue;

            found = true;
            cout << "YES\n";
            int currextra = 4;
            vi mainpath;
            mainpath.pb(1);
            while (sz(mainpath)+1 < numused) {
                mainpath.pb(currextra);
                currextra++;
            }
            mainpath.pb(2);

            vi offshoot;
            while (sz(offshoot)+1 < neededverts) {
                offshoot.pb(currextra);
                currextra++;
            }
            offshoot.pb(3);

            while (currextra <= n) {
                mainpath.pb(currextra);
                currextra++;
            }

            rep(j, 0, sz(mainpath)-1) {
                cout << mainpath[j] << ' ' << mainpath[j+1] << '\n';
            }
            cout << mainpath[i] << ' ' << offshoot[0] << '\n';
            rep(j, 0, sz(offshoot)-1) {
                cout << offshoot[j] << ' ' << offshoot[j+1] << '\n';
            }

            break;
        }

        if (!found) cout << "NO\n";
    }
}