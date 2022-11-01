#include <bits/stdc++.h>
using namespace std;
#define fo(i,a,b) for (int i = (a); i < (b); i++)
#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define pb push_back
#define eb emplace_back
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
#define MAX_N 200005
ll N, R, l[MAX_N], t[MAX_N];
ll nBottles;
vector <ll> ansArr;
int main() {
    scanf ("%lld %lld" , &N, &R);
    FO (i,0,N) {
        scanf ("%lld", &l[i]);
    }
    FO (i,0,N) {
        scanf ("%lld", &t[i]);
    }
    FO (i,0,N) {
        if (t[i] < l[i]) {
            printf ("-1\n");
            return 0;
        }
    }
    ll cLeft (0), cTime(0);
    FO (i,0,N) {
        if (cLeft >= l[i]) {
            cLeft -= l[i];
            cTime += l[i];
            continue;
        }
        t[i] -= cLeft;
        l[i] -= cLeft;
        cTime += cLeft;
        cLeft = 0;
        if (t[i] >= 2*l[i]) {
            cTime += 2*l[i];
            continue;
        }
        ll cDiff = t[i] - l[i];
        l[i] -= cDiff;
        t[i] -= 2*cDiff;
        cTime += cDiff*2;
        ll temTime = cTime;
        while (ansArr.size() < 100005 && temTime < cTime+t[i]) {
            ansArr.push_back (temTime);
            temTime += R;
        }
        nBottles += l[i]/R;
        ll temLeft = l[i] % R;
        if (temLeft != 0) {
            nBottles++;
            cLeft = R-temLeft;
        }
        cTime += t[i];
    }
    printf ("%lld\n", nBottles);
    if (nBottles <= 100000) {
        FO (i,0,ansArr.size()) {
            printf ("%lld ", ansArr[i]);
        }
        printf ("\n");
    }
    return 0;
}