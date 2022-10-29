#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;

const int MAXN = 1e6 + 10;
const int MM = 1e9 + 7;


ll pw(ll p, ll q){
    ll ret = 1;
    for (; q; q >>= 1){
        if (q & 1)
            ret = ret * p % MM;
        p = p * p % MM;
    }
    return ret;
}

int n, m, q;
int w[MAXN], cnt[MAXN], v[MAXN];
char s[MAXN];

PII P[MAXN];
vector<PII> Q[MAXN];
int ans[MAXN];

int main(){
    scanf("%d%d%d", &n, &m, &q);
    for (int i = 0; i < n; i++)
        scanf("%d", &w[i]);
    for (int i = 1; i <= m; i++){
        scanf("%s", s);
        int x = 0;
        for (int j = 0; j < n; j++)
            x |= (s[j] - '0') << j;
        cnt[x]++;
    }
    int nn = 1 << n;
    for (int i = 0; i < nn; i++){
        v[i] = 0;
        for (int j = 0; j < n; j++)
            if ((i >> j) & 1)
                v[i] += w[j];
    }
    int mm = nn - 1;
    for (int i = 1; i <= q; i++){
        scanf("%s", s);
        int x = 0, y = 0;
        for (int j = 0; j < n; j++)
            x |= (s[j] - '0') << j;
        scanf("%d", &y);
        Q[x ^ mm].push_back(PII(y, i));
/*
        int ans = 0;
        int umi = x ^ mm;
        for (int j = 0; j < nn; j++)
            if (v[j ^ umi] <= y)
                ans += cnt[j];
        printf("%d\n", ans);
*/  }
    for (int i = 0; i < nn; i++) if (Q[i].size()){
        // \count {j | v[j ^ i] <= Q[i].first} -> ans[Q[i].second]
        for (int j = 0; j < nn; j++)
            P[j] = PII(v[j ^ i], cnt[j]);
        sort(P, P + nn);
        sort(Q[i].begin(), Q[i].end());
        int now = 0;
        for (int j = 0, k = 0; j < Q[i].size(); j++){
            while (k < nn && P[k].first <= Q[i][j].first){
                now += P[k].second;
                k++;
            }
            ans[Q[i][j].second] = now;
        }
    }
    for (int i = 1; i <= q; i++)
        printf("%d\n", ans[i]);
    return 0;
}