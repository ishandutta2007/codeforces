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
int a[MAXN];

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int numones = 0;
        rep(i, 0, n) {
            cin >> a[i];
            if (a[i] == 1) numones++;
        }

        int numzeroes = n - numones;

        int out = min(numones, numzeroes);
        int onessofar = 0;
        int zeroessofar = 0;
        rep(i, 0, n) {
            
            int zeroesleft = numzeroes - zeroessofar;
            if (zeroesleft <= onessofar) {
                out = min(out, onessofar);
            } else {
                out = min(out, zeroesleft);
            }

            if (a[i] == 0) zeroessofar++;
            if (a[i] == 1) {
                onessofar++;
            }

        }

        cout << out << endl;


    }
}