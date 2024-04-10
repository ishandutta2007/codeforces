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
        int n, m, k;
        cin >> n >> m >> k;
        string a, b;
        cin >> a >> b;
        priority_queue<char, vector<char>, greater<char>> s;
        priority_queue<char, vector<char>, greater<char>> t;
        for (char c : a) {
            s.push(c);
        }
        for (char c : b) t.push(c);
        bool slast = false;
        int currstreak = 0;
        string out;
        while ((!empty(s)) && (!empty(t))) {
            if (s.top() < t.top()) {
                // choose from s
                if (slast && currstreak >= k) {
                    // choose from t
                    out.pb(t.top());
                    t.pop();
                    slast = false;
                    currstreak = 1;
                } else {
                    out.pb(s.top());
                    s.pop();
                    if (slast) {
                        currstreak++;
                    } else {
                        slast = true;
                        currstreak = 1;
                    }
                }
            } else {
                // choose from t
                if ((!slast) && currstreak >= k) {
                    // choose from s
                    out.pb(s.top());
                    s.pop();
                    slast = true;
                    currstreak = 1;
                } else {
                    out.pb(t.top());
                    t.pop();
                    if (!slast) {
                        currstreak++;
                    } else {
                        slast = false;
                        currstreak = 1;
                    }
                }
            }
        }
        cout << out << endl;
    }
}