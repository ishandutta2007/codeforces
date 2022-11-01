#include <cstdio>
#include <algorithm>
#include <vector>
#include <iostream>
#include <string>
#include <set>
#include <cstdlib>

#define FOR(a,b,c) for (int c = (int)(a); c < (int)(b); ++c)
#define REP(n,i) FOR(0,n,i)
#define pb push_back
#define ll long long

#define TRACE(x) cerr << #x << " = " << x << endl
#define _ << " _ " <<

using namespace std;

const int Mod = 1000000007;
class mint{
public:
    int x;
    mint(ll y = 0){
        y %= Mod;
        if (y < 0) y += Mod;
        x = y;
    }
};
mint operator+(mint a, mint b){return mint(a.x + b.x);}
mint operator*(mint a, mint b){return mint((ll)a.x * b.x);}
void operator*=(mint &a, mint b){a = a * b;}

mint Pow(mint t, int x){
    mint r = 1;
    while (x){
        if (x & 1) r *= t;
        t *= t;
        x >>= 1;
    } return r;
}

class str{
public:
    int l;
    mint x;
};
str operator+(str a, str b){
    str r = {a.l + b.l, b.x + a.x * Pow(10, b.l)};
    if (r.l >= Mod-1) r.l -= Mod-1;
    return r;
}
void operator+=(str &a, str b){a = a + b;}

string s;
int n;
char c[100005];
string in[100005];

str val[256];

int main(){
    cin >> s >> n;
    REP(n,i){
        cin >> in[i];
        c[i] = in[i][0];
        in[i] = string(in[i].begin() + 3, in[i].end());
        //TRACE(in[i]);
    }
    REP(256,i) val[i] = {1, i};
    for (int i = n-1; i >= 0; --i){
        str curr = {0, 0};
        for (auto x : in[i]) curr += val[x - '0'];
        val[c[i] - '0'] = curr;
    }
    str r = {0, 0};
    for (auto x : s) r += val[x - '0'];
    printf("%d\n", r.x.x);
    return 0;
}