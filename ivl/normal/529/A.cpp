#include <bits/stdc++.h>

#define FOR(a,b,c) for (int c = (int)(a); c < (int)(b); ++c)
#define REP(n,i) FOR(0,n,i)
#define pb push_back
#define ll long long
#define pii pair < int, int >
#define x first
#define y second
#define real long double
#define point pair < real, real >

#define TRACE(x) cerr << #x << " = " << x << endl
#define _ << " _ " <<

using namespace std;

const int Mod = 1000000007;
class mint{
public:
    int x;
    mint(ll y = 0){
        y %= Mod;
        x = (int)y;
    }
};
mint operator+(mint a, mint b){a.x += b.x; if (a.x >= Mod) a.x -= Mod; return a;}
mint operator-(mint a, mint b){a.x -= b.x; if (a.x < 0) a.x += Mod; return a;}
mint operator*(mint a, mint b){return mint((ll)a.x * b.x);}
bool operator==(mint a, mint b){return a.x == b.x;}
bool operator!=(mint a, mint b){return a.x != b.x;}

pii operator+(pii a, pii b){
    if (a.y < b.x) b.x -= a.y, a.y = 0;
    else a.y -= b.x, b.x = 0;
    return {a.x + b.x, a.y + b.y};
}

pii F(char c){
    if (c == '(') return {0, 1};
    else return {1, 0};
}

string s;
int l;

pii Pref[1000015], Suff[1000015];

mint _H[1000015], *H = _H+1;
mint HP = 101;
mint Hpot[1000015];

mint HL[1000015], HR[1000015];

mint Hash(int lo, int hi){
    if (lo < 0) return HL[hi-lo+1];
    if (lo > 2000000) return HR[hi-lo+1];
    return H[hi] - H[lo-1] * Hpot[hi-lo+1];
}

mint Hash(pii t){return Hash(t.x, t.x + t.y - 1);}

mint Hash(int t){return Hash(t, t);}

int LCP(int a, int b, int MaxLen){
    int lo = 0, hi = MaxLen, mid = (lo+hi+1) / 2;
    while (lo != hi){
        if (Hash(a, a+mid-1) == Hash(b, b+mid-1)) lo = mid;
        else hi = mid-1;
        mid = (lo+hi+1) / 2;
    } return lo;
}

vector < pii > Func(int id){
    pii t = Suff[l-id] + Pref[id];
    return {{-2000000, t.x}, {id, l-id}, {0, id}, {3000000, t.y}};
}

bool Cmp(int id1, int id2){
    // string = [(((] suffix(l-id) + prefix(id) + [)))]
    if (id2 == -1) return true;

    vector < pii > V1 = Func(id1), V2 = Func(id2);
    vector < int > Vp = {0};
    for (int i = 0, j = V1[0].y; i < 4; ++i, j += V1[i].y) Vp.pb(j);
    for (int i = 0, j = V2[0].y; i < 4; ++i, j += V2[i].y) Vp.pb(j);
    sort(Vp.begin(), Vp.end());
    vector < pii > VV1, VV2;
    int tmp = 0;
    for (int i = 0, j = 1; i < 4; ++i){
        while (j < (int)Vp.size() && Vp[j] <= tmp+V1[i].y){
            VV1.pb({V1[i].x + Vp[j-1] - tmp, Vp[j] - Vp[j-1]});
            ++j;
        }
        tmp += V1[i].y;
    }
    tmp = 0;
    for (int i = 0, j = 1; i < 4; ++i){
        while (j < (int)Vp.size() && Vp[j] <= tmp+V2[i].y){
            VV2.pb({V2[i].x + Vp[j-1] - tmp, Vp[j] - Vp[j-1]});
            ++j;
        }
        tmp += V2[i].y;
    }

    REP(Vp.size()-1,i) if (Hash(VV1[i]) != Hash(VV2[i])){
        tmp = LCP(VV1[i].x, VV2[i].x, VV1[i].y);
        return Hash(VV1[i].x + tmp).x < Hash(VV2[i].x + tmp).x;
    }
    return false;
}

int main(){
    Hpot[0] = 1;
    FOR(1,1000005,i) Hpot[i] = Hpot[i-1] * HP, HL[i] = HL[i-1] * HP + ')', HR[i] = HR[i-1] * HP + '(';

    cin >> s;
    l = (int)s.size();
    REP(l,i) H[i] = H[i-1] * HP + s[i];
    REP(l,i) Pref[i+1] = Pref[i] + F(s[i]);
    REP(l,i) Suff[i+1] = F(s[l-i-1]) + Suff[i];
    int MinLen = l*2;
    REP(l+1,i){
        pii t = Suff[l-i] + Pref[i];
        MinLen = min(MinLen, l + t.x + t.y);
    } TRACE(MinLen);
    int Best = -1;
    REP(l+1,i){
        pii t = Suff[l-i] + Pref[i];
        if (MinLen != l + t.x + t.y) continue;
        if (Cmp(i, Best)) Best = i;
    }
    pii r = Suff[l-Best] + Pref[Best];
    REP(r.x,i) cout << "(";
    cout << string(s.begin()+Best, s.end()) << string(s.begin(), s.begin()+Best);
    REP(r.y,i) cout << ")";
    cout << endl;
    return 0;
}