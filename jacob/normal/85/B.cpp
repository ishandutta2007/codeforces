    #include <queue>
    #include <vector>
    #include <algorithm>
    #include <cstdio>
    using namespace std;
  
    int main(void) {
           int k[3];
           int t[3];
           int n;
           vector<long long> c[4];
           scanf("%d%d%d", &k[0], &k[1], &k[2]);
           scanf("%d%d%d", &t[0], &t[1], &t[2]);
           scanf("%d", &n);
           c[0].resize(n);
           for (int i = 0; i < n; i++)
                   scanf("%I64d", &c[0][i]);
           for (int i = 0; i < 3; i++) {
                   typedef long long ll;
                   priority_queue<ll, vector<ll>, greater<ll> > q;
                   for (int j = 0; j < min(n, k[i]); j++)
                           q.push(0L);
                   c[i+1].resize(n);
                   for (int j = 0; j < n; j++) {
                           c[i+1][j] = max(c[i][j], q.top()) + t[i];
                           q.pop();
                           q.push(c[i+1][j]);
                   }
           }
           long long res = 0;
           for (int i = 0; i < n; i++) {
                   res = max(res, c[3][i] - c[0][i]);
           }
           printf("%I64d\n", res);
           return 0;
   }