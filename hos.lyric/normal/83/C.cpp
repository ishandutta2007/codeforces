//  Codeforces Beta Round #72

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cassert>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <utility>
#include <numeric>
#include <algorithm>
#include <bitset>
#include <complex>

using namespace std;

typedef unsigned uint;
typedef long long Int;
typedef vector<int> vint;
typedef pair<int,int> pint;
#define mp make_pair

template<class T> void pv(T a, T b) { for (T i = a; i != b; ++i) cout << *i << " "; cout << endl; }
template<class T> void pvp(T a, T b) { for (T i = a; i != b; ++i) cout << "(" << i->first << ", " << i->second << ") "; cout << endl; }
template<class T> void chmin(T &t, T f) { if (t > f) t = f; }
template<class T> void chmax(T &t, T f) { if (t < f) t = f; }
int in_c() { int c; for (; (c = getchar()) <= ' '; ) { if (!~c) throw ~0; } return c; }
int in() { int x = 0, c; for (; (uint)((c = getchar()) - '0') >= 10; ) { if (c == '-') return -in(); if (!~c) throw ~0; } do { x = (x << 3) + (x << 1) + (c - '0'); } while ((uint)((c = getchar()) - '0') < 10); return x; }
Int In() { Int x = 0, c; for (; (uint)((c = getchar()) - '0') >= 10; ) { if (c == '-') return -In(); if (!~c) throw ~0; } do { x = (x << 3) + (x << 1) + (c - '0'); } while ((uint)((c = getchar()) - '0') < 10); return x; }

int dx[] = { 1, 0, -1, 0, };
int dy[] = { 0, 1, 0, -1, };

const int L = 26;

int M, N, K;
char S[60][60];
int SX, SY, TX, TY;

int sho;
string ans;

int safe[60];
int csLen, cs[60];
int que[100010], *qb, *qe;
int d[60][60];
bool vis[60][60];

/*
string e[110][110];
string calc(int x, int y) {
    if (e[x][y] == " ") {
        if (S[x][y] == 'T') {
            e[x][y] = "";
        } else {
            int h, xx, yy;
            e[x][y] = "~";
            for (h = 0; h < 4; ++h) {
                xx = x + dx[h];
                yy = y + dy[h];
                if (0 <= xx && xx < M && 0 <= yy && yy < N) {
                    if (d[x][y] == d[xx][yy] + 1) {
                        chmin(e[x][y], S[x][y] + calc(xx, yy));
                    }
                }
            }
        }
    }
    return e[x][y];
}
//*/

string calcIt() {
    csLen = 0;
    for (int l = 0; l < L; ++l) if (safe[l]) cs[csLen++] = l;
assert(csLen == K);
    int k;
    int x, y;
    int h, xx, yy;
    int *qq, *qnxt;
    qb = qe = que;
    memset(vis, 0, sizeof(vis));
    vis[SX][SY] = 1;
    *qe++ = SX; *qe++ = SY;
    string ret = "";
//cout<<"cs: ";pv(cs,cs+K);
    for (; ; ) {
        for (k = 0; k < K; ++k) {
            bool ok = 0;
            qnxt = qe;
            for (qq = qb; qq != qe; ) {
                x = *qq++; y = *qq++;
                for (h = 0; h < 4; ++h) {
                    xx = x + dx[h];
                    yy = y + dy[h];
                    if (0 <= xx && xx < M && 0 <= yy && yy < N) {
                        if (S[xx][yy] == 'T') {
                            return ret;
                        }
                        if (!vis[xx][yy] && d[x][y] == d[xx][yy] + 1) {
                            if (S[xx][yy] - 'a' == cs[k]) {
                                ok = 1;
                                vis[xx][yy] = 1;
                                *qnxt++ = xx;
                                *qnxt++ = yy;
                            }
                        }
                    }
                }
            }
            if (ok) {
                ret += (char)('a' + cs[k]);
                qb = qe;
                qe = qnxt;
                break;
            }
        }
assert(k < K);
    }
}

void solve(int flg) {
    int x, y;
    int h, xx, yy;
    qb = qe = que;
    memset(d, ~0, sizeof(d));
    d[TX][TY] = 0;
    *qe++ = TX; *qe++ = TY;
    for (; qb != qe; ) {
        x = *qb++; y = *qb++;
        for (h = 0; h < 4; ++h) {
            xx = x + dx[h];
            yy = y + dy[h];
            if (0 <= xx && xx < M && 0 <= yy && yy < N) {
                if (S[xx][yy] == 'S') {
                    d[xx][yy] = d[x][y] + 1;
                    goto found;
                }
                if (safe[S[xx][yy] - 'a']) {
                    if (!~d[xx][yy]) {
                        d[xx][yy] = d[x][y] + 1;
                        *qe++ = xx; *qe++ = yy;
                    }
                }
            }
        }
    }
    return;
found:;
//for(x=0;x<M;++x)pv(d[x],d[x]+N);cout<<"====="<<endl;
    if (flg == 0) {
        chmin(sho, d[SX][SY]);
        return;
    } else {
        if (sho != d[SX][SY]) return;
    }
    //for (x = 0; x < M; ++x) for (y = 0; y < N; ++y) e[x][y] = " ";
    string s = calcIt();
    if (ans == "~" || ans.size() > s.size() || ans.size() == s.size() && ans > s) {
        ans = s;
    }
}

void dfs(int k, int a, int flg) {
//cout<<"dfs"<<string(k,' ')<<a<<endl;
    if (k == K) {
        solve(flg);
        return;
    }
    for (; a < L; ++a) {
        safe[a] = 1;
        dfs(k + 1, a + 1, flg);
        safe[a] = 0;
    }
}

int main() {
    int x, y;
    
    for (; ~scanf("%d%d%d", &M, &N, &K); ) {
        for (x = 0; x < M; ++x) {
            scanf("%s", S[x]);
        }
        for (x = 0; x < M; ++x) for (y = 0; y < N; ++y) {
            if (S[x][y] == 'S') SX = x, SY = y;
            if (S[x][y] == 'T') TX = x, TY = y;
        }
        sho = M * N;
        ans = "~";
        dfs(0, 0, 0);
        dfs(0, 0, 1);
        if (ans == "~") ans = "-1";
        if (ans[0] == 'S') ans = ans.substr(1);
        cout << ans << endl;
    }
    
    return 0;
}