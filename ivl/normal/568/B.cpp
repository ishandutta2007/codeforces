#include <cstdio>
#include <algorithm>
#include <vector>
#include <iostream>
#include <string>
#include <set>
#include <cstdlib>
#include <assert.h>
#include <map>
#include <cstring>
#include <bitset>

#define FOR(a,b,c) for (int c = (int)(a); c < (int)(b); ++c)
#define REP(n,i) FOR(0,n,i)
#define pb push_back
#define ll long long
#define pii pair < int, int >
#define x first
#define y second
#define real long double
#define prr pair < real, real >

#define TRACE(x) cerr << #x << " = " << x << endl
#define _ << " _ " <<

using namespace std;

const int Mod = 1000000007;
class mint{
public:
    int x;
    mint(ll y = 0){
        y %= Mod;
        x = y;
    }
};
mint operator+(mint a, mint b){return mint(a.x + b.x);}
mint operator*(mint a, mint b){return mint((ll)a.x * b.x);}
void operator+=(mint &a, mint b){a = a + b;}
void operator*=(mint &a, mint b){a = a * b;}

int n;

mint memo[4005][4005][2];
bool bio[4005][4005][2];
mint dp(int x, int y, bool z){
    if (x == 0) return z;
    mint &r = memo[x][y][z];
    if (bio[x][y][z]++) return r;
    return r = dp(x-1, y, true) + y * dp(x-1, y, z) + dp(x-1, y+1, z);
}

int main(){
    scanf("%d", &n);
    printf("%d\n", dp(n, 0, false).x);
    return 0;
}