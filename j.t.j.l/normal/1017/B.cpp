#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;

const int MAXN = 1e5 + 10;
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

char s[MAXN], t[MAXN];
int n;
int f[100];

int main(){
    scanf("%d", &n);
    scanf("%s", s);
    scanf("%s", t);
    for (int i = 0; i < n; i++){
        int p = s[i] - '0', q = t[i] - '0';
        f[p * 2 + q]++;
    }
    ll ans = 0;
    for (int i = 0; i < 4; i++){
        for (int j = i + 1; j < 4; j++){
            int p1 = i >> 1, q1 = i & 1;
            int p2 = j >> 1, q2 = j & 1;
            int u1 = p1 | q1, v1 = p2 | q2;
            int u2 = p2 | q1, v2 = p1 | q2;
            if (u1 != u2 || v1 != v2){
                //cout << p1 << ' ' << q1 << ' ' << p2 << ' ' << q2 << ' ' << f[i] << ' ' << f[j] << endl;
                ans += 1ll * f[i] * f[j];
            }
        }
    }
    printf("%lld\n", ans);
    return 0;
}