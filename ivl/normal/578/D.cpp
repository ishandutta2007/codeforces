#include <bits/stdc++.h>

#define FOR(a,b,c) for (int c = (int)(a); c < (int)(b); ++c)
#define REP(n,i) FOR(0,n,i)
#define pb push_back
#define ll long long
#define pii pair < int, int >
#define x first
#define y second

#define TRACE(x) cerr << #x << " = " << x << endl
#define _ << " _ " <<

using namespace std;

int n, m;
string s;

ll F(ll l){
    return l * (l+1) / 2;
}
/*
ll Func(int lo, int hi){
    if (lo == hi) return 0;
    ll R = 0;
    if (s[lo] == s[lo+1]) R -= m-1;
    if (s[hi] == s[hi-1]) R -= m-1;
    return R;
}
*/
int main(){
    cin >> n >> m >> s;
    ll R = 0;

    R += (m-1) * n;
    FOR(2,n+1,i) R += 2 * (m-1) * (n+1-i);

    REP(n-1,i) if (s[i] == s[i+1]) R -= (m-1) * (n);

    char c1 = s[0], c2 = s[1];
    int len = 0;
    FOR(1,n,i){
        if (c1 == s[i-1] && c2 == s[i]){
            ++len;
            swap(c1, c2);
        } else {
            if (c1 != c2) R -= F(len);
            len = 1;
            c1 = s[i];
            c2 = s[i-1];
        }
    }
    if (c1 != c2) R -= F(len);
    printf("%I64d\n", R);
    return 0;
}