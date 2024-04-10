#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

const int N = 100005;
const int M = 1000005;

int n, m;

char str[N], sb[1005];
bool dp[N];
int path[N][2];

string w[N];

int ch[M][26];
int sz = 1, val[M];

void insert(char *str, int id) {
    int len = strlen(str);
    int u = 0;
    for (int i = 0; i < len; i++) {
        int c;
        if (str[i] >= 'A' && str[i] <= 'Z')
            c = str[i] - 'A';
        else c = str[i] - 'a';
        if (!ch[u][c]) {
            ch[u][c] = sz++;
        }
        u = ch[u][c];
    }
    val[u] = id;
}

void print(int n) {
    if (n == 0) return;
    print(path[n][1]);
    int id = path[n][0];
    for (int i = 0; i < w[id].length(); i++)
        printf("%c", w[id][i]);
    printf(" ");
}

int main() {
    scanf("%d", &n);
    scanf("%s", str + 1);
    scanf("%d", &m);
    for (int i = 1; i <= m; i++) {
        scanf("%s", sb);
        w[i] = sb;
        //reverse(sb, sb + strlen(sb));
        insert(sb, i);
    }
    dp[0] = true;
    for (int i = 1; i <= n; i++) {
        int u = 0;
        for (int j = i; j > 0 && j > i - 1000; j--) {
            int c = str[j] - 'a';
          //  if (j == 4) printf("%d %d %d\n", u, c, ch[u][c]);
            if (!ch[u][c]) break;
            u = ch[u][c];
            if (val[u] && dp[j - 1]) {
                dp[i] = true;
                path[i][0] = val[u];
                path[i][1] = j - 1;
                break;
            }
        }
       //printf("%d %d %d\n", i, dp[i], path[i][1]);
    }
    print(n);
    return 0;
}