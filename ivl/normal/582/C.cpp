#include <bits/stdc++.h>

#define FOR(a,b,c) for (int c = (int)(a); c < (int)(b); ++c)
#define REP(n,i) FOR(0,n,i)
#define pb push_back
#define ll long long

#define TRACE(x) cerr << #x << " = " << x << endl
#define _ << " _ " <<

using namespace std;

int n;
int a[200005];

int maks[200005];
bool good[200005];

void makemax(int &aa, int b){if (aa < b) aa = b;}

int gcd(int aa, int b){
    while (b) aa %= b, swap(aa, b);
    return aa;
}

vector < int > Cnt[200005];

ll F(int c){
    memset(maks, 0, sizeof maks);
    REP(n,i) makemax(maks[i%c], a[i]);
    REP(n,i) good[i] = (a[i] == maks[i%c]);
    vector < int > V = {0};
    REP(n,i) if (good[i]) ++V.back(); else V.pb(0);
    vector < int > V2(n+1, 0);
    if (V.back() == n){
        FOR(1,n+1,i) V2[i] = n;
    } else {
        if (good[0] && good[n-1]) V.front() += V.back(), V.pop_back();
        for (auto x : V) FOR(1,x+1,i) V2[i] += x-i+1;
    }
    ll R = 0;
    for (auto x : Cnt[c]) R += V2[x];
    return R;
}

int main(){

    scanf("%d", &n);
    REP(n,i) scanf("%d", a+i), Cnt[gcd(n, i+1)].pb(i+1);

    ll R = 0;
    FOR(1,n,i) if (n%i == 0){
        R += F(i);
    } printf("%I64d\n", R);

    return 0;
}