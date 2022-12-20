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
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) cin >> a[i];

        int bst = 0; // count the number of twos
        pair<int, int> out = mp(-1, 0);

        pair<int, int> nextneg[n];
        int prevneg = -1;
        for (int i = 0; i < n; i++) {
            
            nextneg[i].first = prevneg;
            if (a[i] < 0) prevneg = i;
        }

        prevneg = n;

        for (int i = n-1; i >= 0; i--) {
            
            nextneg[i].second = prevneg;
            if (a[i] < 0) prevneg = i;
        }

        pair<int, int> nextzero[n];
        int lastseenzero = -1;
        for (int i = 0; i < n; i++) {
            nextzero[i].first = lastseenzero;
            if (a[i] == 0) lastseenzero = i;

        }
        lastseenzero = n;

        for (int i = n-1; i >= 0; i--) {
            
            nextzero[i].second = lastseenzero;
            if (a[i] == 0) lastseenzero = i;
        }

        int negpref[n];
        negpref[0] = 0;
        if (a[0] < 0) negpref[0]++;
        for (int i = 1; i < n; i++) {
            negpref[i] = negpref[i-1];
            if (a[i] < 0) negpref[i]++;
        }

        int twopref[n];
        twopref[0] = 0;
        if (abs(a[0]) == 2) twopref[0]++;
        for (int i = 1; i < n; i++) {
            twopref[i] = twopref[i-1];
            if (abs(a[i]) == 2) twopref[i]++;
        }

        for (int i = 0; i < n; i++) {
            // consider putting leftptr here
            int rtptr = nextzero[i].second;
            
            int numnegs = negpref[rtptr-1] - negpref[i];
            bool ok = true;

            if ((numnegs % 2) == 1) {
                // have to adjust rtptr to the right
                int moveneg = -1;
                if (rtptr != n) moveneg = nextneg[rtptr].first;
                else {
                    if (a[n-1] < 0) moveneg = n-1;
                    else moveneg = nextneg[n-1].first;
                }

                if (moveneg <= i) ok = false;
                rtptr = moveneg;
            }
            if (!ok) continue;

            int numtwos = twopref[rtptr-1] - twopref[i];
            if (numtwos > bst) {
                bst = numtwos;
                out = mp(i, rtptr);
            }


        }

        // try not eating anything on the left
        if (a[0] != 0) {
            int rtptr = nextzero[0].second;
            int numnegs = negpref[rtptr-1];
            bool ok = true;

            if ((numnegs % 2) == 1) {
                // have to adjust rtptr to the right
                int moveneg = -1;
                if (rtptr != n) moveneg = nextneg[rtptr].first;
                else {
                    if (a[n-1] < 0) moveneg = n-1;
                    else moveneg = nextneg[n-1].first;
                }

                if (moveneg <= 0) ok = false;
                rtptr = moveneg;
            }
            if (ok) {

                int numtwos = twopref[rtptr-1];
                if (numtwos > bst) {
                    bst = numtwos;
                    out = mp(-1, rtptr);
                }
            }
        }



        cout << out.first + 1 << ' ' << n - out.second << endl;

        
    }
}