#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
#include <set>
#include <iostream>
#include <queue>
using namespace std;

int n, q;
vector<string> to[6];

queue<string> Q;
set<string> vis;

int main() {
    scanf("%d%d", &n, &q);
    char a[10], b[10];
    for (int i = 0; i < q; i++) {
        scanf("%s%s", a, b);
        to[b[0] - 'a'].push_back(a);
    }
    string sb = "";
    sb += 'a';
    Q.push(sb);
    vis.insert(sb);
    long long ans = 0;
    while (!Q.empty()) {
        string u = Q.front(); Q.pop();
       // cout << u <<endl;
        if (u.length() == n) {
            ans++;
            continue;
        }
        string tmp = "";
        for (int i = 0; i < 1; i++) {
            for (int j = 0; j < to[u[i] - 'a'].size(); j++) {
                string v = tmp + to[u[i] - 'a'][j];
                if (i + 1 != u.length()) v += u.substr(i + 1, u.length() - i);
                if (vis.find(v) != vis.end()) continue;
                vis.insert(v);
                Q.push(v);
            }
            tmp += u[i];
        }
    }
    printf("%lld\n", ans);
    return 0;
}