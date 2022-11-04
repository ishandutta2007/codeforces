#include<bits/stdc++.h>
#define MAX 4008004
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
int g[MAX];
char a[MAX];
int b[MAX], c[MAX];
int n, m;
int st[MAX];
int stnow = 0;
int encode(int i, int j) {
    return i * (m + 2) + j;
}
pair<int, int> decode(int i) {
    return {i / (m + 2), i % (m + 2)};
}
bool valid(int i) {
    auto p = decode(i);
    return (p.first > 0 && p.second > 0 && p.first <= n && p.second <= m);
}


void dfs1(int i) {
    while(valid(i)) {
        c[i] = 1;
        st[stnow++] = i;
        if(c[g[i]] == 0) {
            break;
        } else if(c[g[i]] == 2) {
            i = g[i];
            continue;
        } else {
            int now = stnow - 1;
            while(now > 0 && st[now] != g[i]) {
                --now;
            }
            int am = stnow - now;
            b[g[i]] = am;
            now = stnow - 1;
            while(now > 0 && st[now] != g[i]) {
                b[st[now]] = am;
                --now;
            }
            break;
        }
    }
    while(stnow > 0) {
        c[st[--stnow]] = 0;
    }
}




/*
    c[i] = 1;
    st[stnow++] = i;
    if(valid(i)) {
        if(c[g[i]] == 0) {

        } else if(c[g[i]] == 2) {
            if(dfs1(g[i])) {
                c[i] = 0;
                --stnow;
                return true;
            }
        } else {
            int now = stnow - 1;
            while(now > 0 && st[now] != g[i]) {
                --now;
            }
            int am = stnow - now;
            b[g[i]] = am;
            now = stnow - 1;
            while(now > 0 && st[now] != g[i]) {
                b[st[now]] = am;
                --now;
            }
            c[i] = 0;
            --stnow;
            return true;
        }
    }
    --stnow;
    c[i] = 0;
    return false;
}
*/
void dfs2(int i) {
    if(b[i] != -1) {
        return;
    }
    while(true) {
        if(b[i] != -1) {
            break;
        }
        if(!valid(i)) {
            b[i] = 0;
            break;
        }
        st[stnow++] = i;
        i = g[i];
    }

    while(stnow > 0) {
        b[st[stnow - 1]] = 1 + b[g[st[stnow - 1]]];
        --stnow;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #ifdef _FILE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int t;
    cin >> t;
    while(t--) {
        cin >> n >> m;
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                cin >> a[encode(i, j)];
            }
        }
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                int x = i;
                int y = j;
                int id1 = encode(i, j);
                if(a[id1] == 'U') {
                    --x;
                } else if(a[id1] == 'D') {
                    ++x;
                } else if(a[id1] == 'R') {
                    ++y;
                } else {
                    --y;
                }
                g[id1] = encode(x, y);
            }
        }
        for(int i = 0; i <= n + 1; i++) {
            for(int j = 0; j <= m + 1; j++) {
                int id1 = encode(i, j);
                c[id1] = 2;
                b[id1] = -1;
            }
        }
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                int id1 = encode(i, j);
                if(c[id1] == 2) {
                    dfs1(id1);
                }
            }
        }
        int res = -1;
        int x = -1;
        int y = -1;
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                int id1 = encode(i, j);
                dfs2(id1);
                if(b[id1] > res) {
                    x = i;
                    y = j;
                    res = b[id1];
                }
            }
        }
        cout << x << ' ' << y << ' ' << res << '\n';
    }
}