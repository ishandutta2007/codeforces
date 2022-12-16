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

#define MAXN 4010

int numw[MAXN];
int numb[MAXN];
vector<int> child[MAXN];
string s;

void dfs(int curr) {
    numw[curr] = 0;
    numb[curr] = 0;
    for (int nxt : child[curr]) {
        dfs(nxt);
        numw[curr] += numw[nxt];
        numb[curr] += numb[nxt];
    }
    if (s[curr] == 'W') numw[curr]++;
    else numb[curr]++;
}

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        rep(i, 0, n) {
            numw[i] = -1;
            numb[i] = -1;
            child[i].clear();
        }

        rep(i, 1, n) {
            int x;
            cin >> x;
            x--;
            child[x].pb(i);
        }
        cin >> s;
        dfs(0);
        int out = 0;
        rep(i, 0, n) {
            if (numw[i] == numb[i]) out++;
        }
        cout << out << '\n';
    }
}