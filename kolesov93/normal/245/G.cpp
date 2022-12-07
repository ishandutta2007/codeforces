#include <iostream>
#include <memory.h>
#include <set>
#include <map>
#include <string>
#include <vector>

using namespace std;

const int N = 10000;

map<string, int> q;
map<int, string> names;
set< pair<int, int> > friends;
int n = 0;

int getN(string a) {
    if (q.find(a) == q.end()) {
        q[a] = n++;
        names[n - 1] = a;
    }
    return q[a];
}

vector<int> g[N];
short w[N][N];

int main() {
    //freopen("in", "r", stdin);
    //cerr << sizeof(w) << endl;

    memset(w, -1, sizeof(w));
    int m;
    cin >> m;
    while (m--) {
        string x, y;
        cin >> x >> y;

        int a = getN(x), b = getN(y);
        friends.insert(make_pair(a, b));
        friends.insert(make_pair(b, a));
        g[a].push_back(b);
        g[b].push_back(a);
    }

    

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < g[i].size(); ++j) 
            for (int k = 0; k < j; ++k) {
                if (friends.find(make_pair(g[i][j],g[i][k])) == friends.end()) {
                    w[ g[i][k] ][ g[i][j] ] = w[ g[i][j] ][ g[i][k] ] = max(w[ g[i][j] ][ g[i][k] ], short(0));
                    ++w[ g[i][j] ][ g[i][k] ];
                    ++w[ g[i][k] ][ g[i][j] ];
                }
            }
    }

    cout << q.size() << endl;
    for (int i = 0; i < n; ++i) {
        short mx = -1;
        for (int j = 0; j < n; ++j)
                mx = max(mx, w[i][j]);

        if (mx == -1) {
            cout << names[i] << " " << n - 1 - g[i].size() << endl;
            continue;
        }
        
        int res = 0;
        for (int j = 0; j < n; ++j)
            if (mx == w[i][j]) ++res;
        cout << names[i] << " " << res << endl;
    }

    return 0;
}