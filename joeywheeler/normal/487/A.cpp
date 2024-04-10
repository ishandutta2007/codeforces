#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

long long hme, hmon, ame, amon;
long long dme, dmon;
long long H,A,D;

long long cur;

int main() {
    scanf("%lld %lld %lld", &hme, &ame, &dme);
    scanf("%lld %lld %lld", &hmon, &amon, &dmon);
    ame = ame-dmon;
    amon = max(0ll,amon-dme);

    scanf("%lld%lld%lld",&H,&A,&D);
    if (ame <= 0) {
        cur += A*(1-ame);
        ame = 1;
    }

    long long best = 1e16;
    for (; amon >= 0; amon--, cur+=D) {
        long long oame = ame;
        long long ocur = cur;
        for (; ame <= 200; ame++, cur += A) {
            long long tml = max(hmon / ame - 5, 0ll);
            while (tml*ame < hmon) tml++;
            long long hpdrain = amon * tml;
            long long nhp = max(hme,hpdrain+1);
            best = min(best, cur + (nhp-hme)*H);
        }
        cur = ocur;
        ame = oame;
    }
    printf("%lld\n", best);
}