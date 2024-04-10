#include <bits/stdc++.h>
#define REP(i,n) for(int i=0; i<(int)(n); ++i)
using namespace std;
typedef long long LL;

int *buildFail(char *p) {
  int m = strlen(p);
  int *fail = new int[m+1];
  int j = fail[0] = -1;
  for (int i = 1; i <= m; ++i) {
    while (j >= 0 && p[j] != p[i-1]) j = fail[j];
    fail[i] = ++j;
  }
  return fail;
}
void match(char *t, char *p, int *fail, vector<bool>& mtc) {
  int n = strlen(t), m = strlen(p);
  for (int i = 0, k = 0; i < n; ++i) {
    while (k >= 0 && p[k] != t[i]) k = fail[k];
    if (++k >= m) {
      // match at t[i-m+1 .. i]
      mtc[i] = true;
      k = fail[k];
    }
  }
}

typedef long long LL;
const int MOD = 1000000007;
int add(int x, int y) {
    return (x + y) % MOD;
}
const int MAX = 100010;

int main(){
    char s[MAX], t[MAX];
    while(scanf("%s", &s) != EOF) {
        scanf("%s", &t);
        int n = strlen(s);
        int t_size = strlen(t);
        int* fail = buildFail(t);

        vector<bool> mt(n);
        match(s, t, fail, mt);

        vector<int> dp(n + 10);
        vector<int> sum(n + 11);
        vector<int> what(n + 11);
        dp[0] = 1;
        sum[0] = 1;
        what[0] = 1;
        int last = -1;
        for(int i = 0; i < n; i++) {
            if(mt[i]) last = i;
            if(last == -1) {
                dp[i+1] = 0;
            }else {
                int b = last - t_size + 1;
                dp[i+1] = what[b];
            }
            sum[i+1] = add(sum[i], dp[i+1]);
            what[i+1] = add(add(what[i], sum[i]), dp[i+1]);
        }
        int ans = 0;
        REP(i, n) {
            ans = add(ans, dp[i+1]);
        }
        cout << ans << endl;
    }
    return 0;
}