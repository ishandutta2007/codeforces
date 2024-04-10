#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

int n, m, q;
pair<int,int> e[200005];

// r, s, qi
vector<tuple<int,int,int> > qul[200005];
// l, t, qi
vector<tuple<int,int,int> > qur[200005];

int ans[200005];

vector<int> v;
int ind[1005];
int lt[1005], T, O;
bitset<1000> b[1000];
bitset<1000> rb[200005];

void go(int rs, int re) {
    if (re-rs < 0) return;

    // process all queries involving edge md
    int md = (rs+re)/2;

    T++; O = 0;
    FO(i,rs,re+1) {
        int x, y; tie(x,y) = e[i];
        if (lt[x] != T) {
            lt[x] = T;
            ind[x] = O++;
        }
        if (lt[y] != T) {
            lt[y] = T;
            ind[y] = O++;
        }
    }
    FO(i,0,O) {
        b[i].reset();
        b[i].set(i);
    }
    FO(i,md,re+1) {
        // proc edge i
        int x, y; tie(x,y) = e[i];
        b[ind[y]] = b[ind[x]] |= b[ind[y]];
        while (sz(qur[i]) && get<0>(qur[i].back()) <= md) {
            int l, t, qi;
            tie(l, t, qi) = qur[i].back();
            qur[i].pop_back();
            if (lt[t] == T) {
                rb[qi] = b[ind[t]];
            }
        }
    }
    FO(i,0,O) {
        b[i].reset();
        b[i].set(i);
    }
    for (int i = md; i >= rs; i--) {
        if (i != md) {
            // proc edge i
            int x, y; tie(x,y) = e[i];
            b[ind[y]] = b[ind[x]] |= b[ind[y]];
        }
        while (sz(qul[i]) && get<0>(qul[i].back()) >= md) {
            int r, s, qi;
            tie(r, s, qi) = qul[i].back();
            qul[i].pop_back();
            if (lt[s] == T) {
                ans[qi] = (b[ind[s]] & rb[qi]).any();
            }
        }
    }

    go(rs, md-1);
    go(md+1, re);
}

int main() {
    scanf("%d %d %d", &n, &m, &q);
    FO(i,0,m) {
        scanf("%d %d", &e[i].first, &e[i].second);
        e[i].first--; e[i].second--;
    }
    FO(i,0,q) {
        int l, r, s, t; scanf("%d %d %d %d", &l, &r, &s, &t);
        l--; r--; s--; t--;
        qul[l].emplace_back(r,s,i);
        qur[r].emplace_back(l,t,i);
    }
    FO(i,0,m) {
        sort(qul[i].begin(),qul[i].end());
        sort(qur[i].begin(), qur[i].end());
        reverse(qur[i].begin(), qur[i].end());
    }
    go(0,m-1);
    FO(i,0,q) printf(ans[i] ? "Yes\n" : "No\n");
}