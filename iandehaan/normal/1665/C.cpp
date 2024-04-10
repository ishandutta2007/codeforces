#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
#define pb push_back 
#define mp make_pair

int main() {
    cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int p[n];
        pair<int, int> deg[n];
        int realdeg[n];
        for (int i = 0; i < n; i++) {
            deg[i] = mp(0, i);
            realdeg[i] =0 ;
        }
        p[0] = -1;
        for (int i = 1; i < n; i++) {
            cin >> p[i];
            p[i]--;
            deg[p[i]].first++;
            realdeg[p[i]]++;
        }

        sort(deg, deg+n);

        int infecttime[n];

        int currtime = 0;

        for (int i = n-1; i >= 0; i--) {
            if (deg[i].first == 0) {
                // don't infect
                infecttime[deg[i].second] = 0;
            } else {
                infecttime[deg[i].second] = currtime;
                currtime++;
            }
        }
        // now we infect root
        currtime++;

        vector<int> amtleft;
        for (int i = 0; i < n; i++) {
            int timepassed = currtime - infecttime[i];
            //cout << i << ' ' << realdeg[i] << ' ' << timepassed << endl;
            if (timepassed < realdeg[i]) {
                
                amtleft.pb(realdeg[i]-timepassed);
            }
        }

        sort(all(amtleft));
        //reverse(all(amtleft));
        
            while (sz(amtleft) != 0) {
                currtime++;
                int x = amtleft[sz(amtleft)-1];
                amtleft.pop_back();
                x--;
                amtleft.pb(x);
                sort(all(amtleft));
                for (int i = 0; i < sz(amtleft); i++) amtleft[i]--;
                vector<int> newvec;
                for (int i = 0; i < sz(amtleft); i++) {
                    if (amtleft[i] > 0) newvec.pb(amtleft[i]);
                }
                amtleft = newvec;
                
            }
        
        cout << currtime << endl;
    }
}