#include <bits/stdc++.h>

#define fo(i,a,b) for (int i=(a); i<(b); i++)
#define sz(v) int(v.size())

#define eb emplace_back
#define pb push_back

#define K 16

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

struct str {
    int ex[1<<K];
    string s;
    string e;
};

void upd(int T, int k, int *ex, const string &s) {
    int vl = 0;
    fo(i,0,sz(s)) {
        vl = ((vl << 1) | (s[i]-'0')) & ((1<<k)-1);
        //printf("vl=%d\n", vl);
        if (i >= k-1) ex[vl] = T;
    }
}

str mrg(const str &a, const str &b) {
    str res;
    fo(i,0,1<<K) {
        res.ex[i] = a.ex[i] | b.ex[i];
    }
    string md = a.e + b.s;
    upd(1, K, res.ex, md);
    res.s = a.s + b.s;
    if (sz(res.s) >= (1<<K)) {
        res.s.resize(1<<K);
    }

    res.e = a.e + b.e;
    if (sz(res.e) >= (1<<K)) {
        res.e = res.e.substr(sz(res.e)-(1<<K));
    }

    return res;
}

str ss[500];
int n, m;
char buf[1005];
int exs[1<<K];
int nexs[1<<K];
int T;

int clcvl(const str &a) {
    if (sz(a.s) < K) {
        //printf("a.s = %s\n", a.s.c_str());
        for (int l = K; l >= 0; l--) {
            //printf("l=%d\n", l);
            T++;
            upd(T, l, exs, a.s);
            bool bad = false;
            fo(i,0,1<<l) if (exs[i] != T) {
                bad = true;
                break;
            }
            if (!bad) return l;
        }
        return -1;
    }
    T++;
    fo(i,0,1<<K) exs[i] = a.ex[i] ? T : 0;
    for (int l = K; l >= 0; l--) {
        bool bad = false;
        fo(i,0,1<<l) if (exs[i] != T) {
            bad = true;
            break;
        }
        if (!bad) return l;
        fo(i,0,1<<l) {
            if (exs[i] == T) {
                nexs[i>>1] = T+1;
                nexs[i & ~(1<<(l-1))] = T+1;
            }
        }
        fo(i,0,1<<(l-1)) exs[i] = nexs[i];
        T++;
    }
    return -1;
}

int main() {
    scanf("%d", &n);
    fo(i,0,n) {
        scanf("%s", buf);
        upd(1, K, ss[i].ex, buf);
        ss[i].s = buf;
        ss[i].e = buf;
    }
    scanf("%d", &m);
    fo(i,0,m) {
        int a, b; scanf("%d %d", &a, &b); a--; b--;
        ss[n+i] = mrg(ss[a], ss[b]);
        printf("%d\n", clcvl(ss[n+i]));
    }
}