//  Codeforces Beta Round #75

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

int N;
int A[100010];
int vis[100010];
int cycLen, cyc[100010];

int smallM[8];
int small[8][100010][8];

int M;
int ansLen[100010], ans[100010][8];
bool sep[100010];

int main() {
    int u, v;
    int i, j, ii;
    int x;
    int k;
    
    for (; ~scanf("%d", &N); ) {
        for (u = 0; u < N; ++u) {
            A[u] = in() - 1;
        }
        M = 0;
        memset(sep, 0, sizeof(sep));
        memset(smallM, 0, sizeof(smallM));
        memset(vis, 0, sizeof(vis));
        for (u = 0; u < N; ++u) if (!vis[u]) {
            cycLen = 0;
            for (v = u; !vis[v]; v = A[v]) {
                vis[v] = 1;
                cyc[cycLen++] = v;
            }
//cout<<"cyc : ";pv(cyc,cyc+cycLen);
            for (i = 0; i + 5 <= cycLen; i += 4) {
                ansLen[M] = 5;
                for (j = 0; j < 4; ++j) {
                    ans[M][j] = cyc[i + j];
                }
                ans[M][4] = cyc[cycLen - 1];
                ++M;
            }
            x = cycLen - i;
            if (x == 1) continue;
            for (j = 0; j < x; ++j) {
                small[x][smallM[x]][j] = cyc[cycLen - x + j];
            }
            ++smallM[x];
        }
//cout<<"TASK : "<<smallM[2]<<" "<<smallM[3]<<" "<<smallM[4]<<endl;
/*
        for (i = 0; i < smallM[4]; ++i) {
            small[2][smallM[2]][0] = small[4][i][0];
            small[2][smallM[2]][1] = small[4][i][3];
            ++smallM[2];
            small[3][smallM[3]][0] = small[4][i][1];
            small[3][smallM[3]][1] = small[4][i][2];
            small[3][smallM[3]][2] = small[4][i][3];
            ++smallM[3];
        }
//cout<<"NEW_TASK : "<<smallM[2]<<" "<<smallM[3]<<endl;
*/
//for(i=0;i<smallM[2];++i)pv(small[2][i],small[2][i]+2);
//for(i=0;i<smallM[3];++i)pv(small[3][i],small[3][i]+3);
        int sho = smallM[2] + smallM[3];
        int km = 0;
        for (k = 0; k <= smallM[3]; k += 3) {
            int m2 = smallM[2];
            int m3 = smallM[3] - k;
            int tmp = k / 3 * 2;
            int tmp23 = min(m2, m3);
            tmp += tmp23;
            m2 -= tmp23;
            m3 -= tmp23;
            tmp += (m2 + 1) / 2;
            tmp += m3;
            if (sho > tmp) {
                sho = tmp;
                km = k;
            }
        }
//cout<<"sho = "<<sho<<endl;cout<<"km = "<<km<<endl;
        {
            ii = i = 0;
            for (; i < km; i += 3) {
                ansLen[M] = 5;
                sep[M] = true;
                ans[M][0] = small[3][i + 0][0];
                ans[M][1] = small[3][i + 0][2];
                ans[M][2] = small[3][i + 1][0];
                ans[M][3] = small[3][i + 1][1];
                ans[M][4] = small[3][i + 1][2];
                ++M;
                ansLen[M] = 5;
                sep[M] = true;
                ans[M][0] = small[3][i + 0][1];
                ans[M][1] = small[3][i + 0][2];
                ans[M][2] = small[3][i + 2][0];
                ans[M][3] = small[3][i + 2][1];
                ans[M][4] = small[3][i + 2][2];
                ++M;
            }
            for (; ii < smallM[2] && i < smallM[3]; ++ii, ++i) {
                ansLen[M] = 5;
                sep[M] = true;
                ans[M][0] = small[2][ii][0];
                ans[M][1] = small[2][ii][1];
                ans[M][2] = small[3][i][0];
                ans[M][3] = small[3][i][1];
                ans[M][4] = small[3][i][2];
                ++M;
            }
            for (; ii < smallM[2]; ii += 2) {
                ansLen[M] = (ii + 1 < smallM[2]) ? 4 : 2;
                sep[M] = true;
                ans[M][0] = small[2][ii + 0][0];
                ans[M][1] = small[2][ii + 0][1];
                ans[M][2] = small[2][ii + 1][0];
                ans[M][3] = small[2][ii + 1][1];
                ++M;
            }
            for (; i < smallM[3]; ++i) {
                ansLen[M] = 3;
                ans[M][0] = small[3][i][0];
                ans[M][1] = small[3][i][1];
                ans[M][2] = small[3][i][2];
                ++M;
            }
        }
        {
            for (i = 0; i < smallM[4]; ++i) {
                ansLen[M] = 4;
                for (j = 0; j < 4; ++j) {
                    ans[M][j] = small[4][i][j];
                }
                ++M;
            }
        }
//cerr<<"!!!ANSWER!!!"<<endl;
        printf("%d\n", M);
        for (i = 0; i < M; ++i) {
            printf("%d\n", ansLen[i]);
            for (j = 0; j < ansLen[i]; ++j) {
                if (j) putchar(' ');
                printf("%d", ans[i][j] + 1);
            }
            puts("");
            for (j = 0; j < ansLen[i]; ++j) {
                if (j) putchar(' ');
                int jj = j + 1;
                if (sep[i]) {
                    if (jj == 2) {
                        jj = 0;
                    } else if (jj == ansLen[i]) {
                        jj = 2;
                    }
                } else {
                    if (jj == ansLen[i]) {
                        jj = 0;
                    }
                }
                printf("%d", ans[i][jj] + 1);
            }
            puts("");
        }
    }
    
    return 0;
}