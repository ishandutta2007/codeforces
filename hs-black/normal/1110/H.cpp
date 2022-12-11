/*
  
 | _ _|
  ` _x 
   /  |
  /   ?
 | |||
 | (__)_)
 
  */

#include <queue>
#include <vector>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MP make_pair
#define ll long long
#define fi first
#define se second
using namespace std;

template <typename T>
void read(T &x) {
    x = 0; bool f = 0;
    char c = getchar();
    for (;!isdigit(c);c=getchar()) if (c=='-') f=1;
    for (;isdigit(c);c=getchar()) x=x*10+(c^48);
    if (f) x=-x;
}

template<typename F>
inline void write(F x, char ed = '\n') {
    static short st[30];short tp=0;
    if(x<0) putchar('-'),x=-x;
    do st[++tp]=x%10,x/=10; while(x);
    while(tp) putchar('0'|st[tp--]);
    putchar(ed);
}

template <typename T>
inline void Mx(T &x, T y) { x < y && (x = y); }

template <typename T>
inline void Mn(T &x, T y) { x > y && (x = y); }

const int N = 30050, M = 2005;
int sum[N][M], dp[M][N];
char fr[M][N];
int ch[N][10], f[N], cnt, n;
inline int To(int x, int c) {
    if (!ch[x][c]) ch[x][c] = ++cnt;
    return ch[x][c];
}

char L[N], R[N];
void insert(void) {
    int L1 = strlen(L + 1), L2 = strlen(R + 1);
    if (L1 == L2) {
        int x = 0, y = 0;
        for (int i = 1;i <= L1; i++) {
            int l = L[i] - '0', r = R[i] - '0';
            if (x == y) {
                for (int j = l + 1;j < r; j++)
                    sum[To(x, j)][L1-i]++;
//                write(cnt);
            }
            else {
                for (int j = l + 1;j <= 9; j++)
                    sum[To(x, j)][L1-i]++;
                for (int j = 0;j < r; j++)
                    sum[To(y, j)][L2-i]++;
//                write(cnt);
            }
            x = To(x, l), y = To(y, r);
        }
        sum[x][0]++; sum[y][0] += x != y;
//        write(cnt);
        return;
    }
    int x = 0, y = 0;
    for (int i = 1;i <= L1; x = To(x, L[i] - '0'), i++)
        for (int j = L[i] - '0' + 1;j <= 9; j++)
            sum[To(x, j)][L1-i]++;
//    write(cnt);
    for (int i = 1;i <= L2; y = To(y, R[i] - '0'), i++)
        for (int j = R[i] - '0' - 1;j >= (i == 1); j--)
            sum[To(y, j)][L2-i]++;
//    write(cnt);
    for (int i = L1 + 1;i < L2; i++)
        for (int k = 1;k <= 9; k++)
            sum[To(0, k)][i-1]++;
    ++sum[x][0], ++sum[y][0];
//	write(cnt);
}

int len;

void build(void) {
    queue<int> q; int L = strlen(R + 1);
    for (int i = 0;i <= 9; i++)
        if (ch[0][i]) q.push(ch[0][i]);
    while (q.size()) {
        int x = q.front(); q.pop();
        for (int i = 0;i < L; i++) sum[x][i] += sum[f[x]][i];
        for (int i = 0;i <= 9; i++) {
            if (!ch[x][i]) ch[x][i] = ch[f[x]][i];
            else q.push(ch[x][i]), f[ch[x][i]] = ch[f[x]][i];
        }
    }
    for (int i = 0;i <= cnt; i++)
        for (int j = 0;j <= n; j++) 
            sum[i][j] = sum[i][j] + sum[i][j-1];
}

void DP(void) {
    for (int i = 1;i <= n; i++) {
        for (int j = 0;j <= cnt; j++) {
            for (int d = 0;d <= 9; d++) {
                int nw = dp[i-1][ch[j][d]] + sum[ch[j][d]][i-1];
                if (nw > dp[i][j]) dp[i][j] = nw, fr[i][j] = d;
            }
        }
    }
    write(dp[n][0]); int t = 0;
    for (int i = n; i; t = ch[t][fr[i][t]], i--) putchar(fr[i][t] | '0');
}

int main() {
    scanf ("%s%s%d", L + 1, R + 1, &n);
    insert(), build(), DP();
    return 0;
}

/*

4552411111370906
4552411308370906
2000

*/