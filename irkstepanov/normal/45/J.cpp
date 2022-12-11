#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef double ld;
typedef pair<ld, ld> pld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

mt19937 rr(1);

void rs(vector<int>& p) {
    for (int i = 1; i < sz(p); ++i) {
        int j = rr() % (i + 1);
        swap(p[i], p[j]);
    }
}

int main() {
 
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int i, j;
    cin >> i >> j;

    if (i >= 5) {
        vector<vector<int> > m(i, vector<int>(j));
        for (int v = 0; v < j; ++v) {
            int curr = i * v + 1;
            for (int u = 0; u < i; ++u) {
                m[u][v] = curr;
                curr += 2;
                if (curr > (v + 1) * i) {
                    curr = v * i + 2;
                }
            }
        }
        for (int u = 0; u < i; ++u) {
            for (int v = 0; v < j; ++v) {
                cout << m[u][v] << " ";
            }
            cout << "\n";
        }
        return 0;
    }
    if (j >= 5) {
        vector<vector<int> > m(i, vector<int>(j));
        for (int u = 0; u < i; ++u) {
            int curr = u * j + 1;
            for (int v = 0; v < j; ++v) {
                m[u][v] = curr;
                curr += 2;
                if (curr > (u + 1) * j) {
                    curr = u * j + 2;
                }
            }
        }
        for (int u = 0; u < i; ++u) {
            for (int v = 0; v < j; ++v) {
                cout << m[u][v] << " ";
            }
            cout << "\n";
        }
        return 0;
    }

    //for (int i = 1; i <= 4; ++i) {
        //for (int j = 1; j <= 4; ++j) {
            bool found = false;
            for (int iter = 0; iter < 100; ++iter) {
                vector<int> p(i * j);
                for (int a = 0; a < sz(p); ++a) {
                    p[a] = a + 1;
                }
                rs(p);
                vector<vector<int> > m(i, vector<int>(j));
                int u = 0, v = 0;
                for (int a = 0; a < sz(p); ++a) {
                    m[u][v] = p[a];
                    ++v;
                    if (v == j) {
                        v = 0;
                        ++u;
                    }
                }
                bool valid = true;
                for (int u = 0; u < i; ++u) {
                    for (int v = 0; v < j; ++v) {
                        if (u + 1 < i && abs(m[u][v] - m[u + 1][v]) == 1) {
                            valid = false;
                        }
                        if (v + 1 < j && abs(m[u][v] - m[u][v + 1]) == 1) {
                            valid = false;
                        }
                    }
                }
                if (valid) {
                    for (int u = 0; u < i; ++u) {
                        for (int v = 0; v < j; ++v) {
                            cout << m[u][v] << " ";
                        }
                        cout << "\n";
                    }
                    return 0;
                }
            }
        //}
    //}

            cout << "-1\n";

    

}