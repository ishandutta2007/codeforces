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

#define MAXM 200'010

template<class T>
struct RMQ {
	vector<vector<T>> jmp;
	RMQ(const vector<T>& V) : jmp(1, V) {
		for (int pw = 1, k = 1; pw * 2 <= sz(V); pw *= 2, ++k) {
			jmp.emplace_back(sz(V) - pw * 2 + 1);
			rep(j,0,sz(jmp[k]))
				jmp[k][j] = min(jmp[k - 1][j], jmp[k - 1][j + pw]);
		}
	}
	T query(int a, int b) {
        if (a == b) return 1e9;
		assert(a < b); // or return inf if a == b
		int dep = 31 - __builtin_clz(b - a);
		return min(jmp[dep][a], jmp[dep][b - (1 << dep)]);
	}
};

int n, m;
int a[MAXM];
vi b(MAXM);

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // m number of cols
    // n height
    cin >> n >> m;

    rep(i, 0, m) {
        cin >> a[i];
        a[i]--;
        b[i] = -1*a[i];
    }

    RMQ rt(b);

    int t;
    cin >> t;
    while (t--) {
        int x1, y1, x2, y2, k;
        cin >> x1 >> y1 >> x2 >> y2 >> k;
        x1--; y1--; x2--; y2--;

        bool ok = true;
        if (a[y1] >= x1 || a[y2] >= x2) {
            ok = false;
        }

        if (((x1-x2) % k != 0) || ((y1-y2) % k != 0)) {
            ok = false;
        }

        int rem = x1 % k;
        int maxheight;
        if ((n % k) > rem) {
            maxheight = (n/k)*k + rem;
        } else {
            maxheight = (n/k)*(k) - k + rem;
        }
        int maxkill = -1*rt.query(min(y1, y2), max(y1, y2)+1);
        if (maxkill >= maxheight || (!ok)) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
        }
        //cout << maxheight << endl;

    }
}