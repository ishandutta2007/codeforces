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

#define MAXK 1'000'010

bool startgoodcol[MAXK];
bool seenrem[MAXK];
bool badevent[MAXK];
int badrowevents[MAXK];

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        string a;
        cin >> a;
        int k = n*m;
        
        int zeropref = 0;
        for (int i = 0; i < k; i++) {
            if (a[i] == '0') zeropref++;
            else break;
        }
        

        for (int i = 0; i < m; i++) {
            seenrem[i] = false;
            badrowevents[i] = false;
        }

        

        for (int i = 0; i < k; i++) {
            int rem = i % m;
            if (a[i] == '1' && (!seenrem[rem])) {
                seenrem[rem] = true;
                startgoodcol[i] = true;
            } else {
                startgoodcol[i] = false;
            }
        }

        int run = 0;
        for (int i = 0; i < k; i++) {
            badevent[i] = false;
            if (a[i] == '0') {
                run++;
            } else {
                run = 0;
            }
            //cout << i << ' ' << run << endl;
            if (run >= m) {
                badevent[i] = true;
            }
        }

        int goodcols = 0;
        //int badrows = 0;
        for (int i = 0; i < k; i++) {
            if (startgoodcol[i]) {
                //cout << "good col " << i << endl;
                goodcols++;
            }
            if (badevent[i]) {
                //cout << "bad row " << i << endl;
                badrowevents[i%m]++;
            }
            int numrows = (i+1 + m - 1) / m;
            int extra = (i+1) % m;
            int out = numrows - badrowevents[i%m] + goodcols;
            if (extra != 0 && extra <= zeropref) {
                //cout << "decr " << extra << ' ' << zeropref << endl;
                out--;
            }
            cout << out << ' ';
        }
        cout << '\n';
        

        // full row of m enters => add 1 for every multiple of n after this
    }
}