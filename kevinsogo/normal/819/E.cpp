#include <bits/stdc++.h>
using namespace std;

vector<int> c3(int a, int b, int c) {
    vector<int> v;
    v.push_back(a);
    v.push_back(b);
    v.push_back(c);
    return v;
}
vector<int> c4(int a, int b, int c, int d) {
    vector<int> v;
    v.push_back(a);
    v.push_back(b);
    v.push_back(c);
    v.push_back(d);
    return v;
}

#define N 1111
bool vis[N];
bool rem[N*N];
vector<vector<int>> construct(int n) {
    vector<vector<int>> res;
    if (n == 3) {
        res.push_back(c3(0, 1, 2));
        res.push_back(c3(0, 1, 2));
    } else {
        vector<vector<int>> ores = construct(n - 1);
        for (int i = 0; i < n; i++) vis[i] = false;
        for (int i = 0; i < ores.size(); i++) rem[i] = false;
        if (!(n & 1)) {
            for (int i = 0; i < ores.size(); i++) {
                vector<int>& v = ores[i];
                if (v.size() != 3) continue;
                rem[i] = true;
                vis[v[0]] = vis[v[1]] = vis[v[2]] = true;
                res.push_back(c3(n - 1, v[0], v[1]));
                res.push_back(c3(n - 1, v[1], v[2]));
                res.push_back(c3(n - 1, v[2], v[0]));
                break;
            }
        }
        for (int i = 0; i < ores.size(); i++) {
            vector<int>& v = ores[i];
            if (rem[i]) continue;
            if (v.size() != 3) continue;
            #define subok(a,b,c) do {\
                if (!vis[v[a]] && !vis[v[b]]) {\
                    rem[i] = true;\
                    vis[v[a]] = vis[v[b]] = true;\
                    res.push_back(c3(n - 1, v[a], v[b]));\
                    res.push_back(c4(n - 1, v[a], v[c], v[b]));\
                }\
            } while (0)
            subok(0, 1, 2);
            subok(1, 2, 0);
            subok(2, 0, 1);
        }
        for (int i = 0; i < ores.size(); i++) {
            if (rem[i]) continue;
            res.push_back(ores[i]);
        }
    }
    return res;
}

int main() {
    int n;
    scanf("%d", &n);
    vector<vector<int>> cycs = construct(n);
    printf("%d\n", int(cycs.size()));
    for (int i = 0; i < cycs.size(); i++) {
        printf("%d", int(cycs[i].size()));
        for (int j = 0; j < cycs[i].size(); j++) {
            printf(" %d", cycs[i][j] + 1);
        }
        printf("\n");
    }

}