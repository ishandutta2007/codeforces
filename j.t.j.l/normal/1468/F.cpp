#include <bits/stdc++.h>

using namespace std;

int N;
typedef pair<int,int> pii;

pii normalize(pii x) {
    int g = __gcd(abs(x.first), abs(x.second));
    x.first /= g;
    x.second /= g;
    return x;
}

map<pii, int>cnt;

int main() {
    int T;
    scanf("%d",&T);
    while(T--) {
        cnt.clear();
        scanf("%d",&N);
        long long ans = 0;
        for (int i=0;i<N;i++) {
            int a,b,c,d;
            scanf("%d%d%d%d",&a,&b,&c,&d);
            pii fuck(c - a, d - b);
            fuck = normalize(fuck);
            ans += cnt[pii(-fuck.first, -fuck.second)];
            cnt[fuck] += 1;
        }
        printf("%lld\n",ans);
    }
}