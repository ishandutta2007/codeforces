#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

#define MOD 1000000007ll

using namespace std;

typedef long long ll;

ll val[10], len[10];

char buf[200000];

ll pw(ll a, ll b) {
    if (b == 0) return 1;
    else {
        ll x = pw(a,b/2);
        if (b&1) return (x*x%MOD)*a%MOD;
        return x*x%MOD;
    }
}

void proc(char a, string b) {
    ll nv = 0, nl = 0;
    for (int i = sz(b)-1; i >= 0; i--) {
        nv += pw(10,nl) * val[b[i]-'0'];
        nl += len[b[i]-'0'];
        nv %= MOD;
        nl %= MOD-1;
    }
    val[a-'0'] = nv;
    len[a-'0'] = nl;
}

int main() {
    int n; string s;
    scanf(" %s", buf); s = buf;
    scanf("%d", &n);

    vector<pair<char,string> > r;
    FO(i,0,n) {
        char ch; string t;
        scanf(" %c%*c%*c", &ch);
        gets(buf); t = buf;
        r.push_back(make_pair(ch,t));
    }
    FO(i,0,10) {
        val[i] = i; len[i] = 1;
    }
    for (int i = sz(r)-1; i >= 0; i--) proc(r[i].first, r[i].second);
    proc('0', s);
    printf("%lld\n", val[0]);
}