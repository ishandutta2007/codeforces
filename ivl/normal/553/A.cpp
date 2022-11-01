#include <cstdio>
#include <algorithm>
#include <vector>
#include <iostream>
#include <assert.h>
#include <stack>
#include <unistd.h>
#include <bitset>

#define FOR(a,b,c) for (int c = (int)(a); c < (int)(b); ++c)
#define REP(n,i) FOR(0,n,i)
#define pb push_back
#define pii pair < int, int >
#define x first
#define y second
#define ll long long
#define TRACE(x) cerr << #x << " = " << x << endl

using namespace std;

const int MOD = 1000000007;
class mint{
public:
    int x;
    mint(ll y = 0){
        y %= MOD;
        if (y < 0) y += MOD;
        x = y;
    }
};
mint operator+(mint a, mint b){return mint(a.x + b.x);}
mint operator*(mint a, mint b){return mint((ll)a.x * b.x);}
void operator*=(mint &a, mint b){a = a * b;}

mint CH[2005][2005];
mint choose(int a, int b){
    if (b < 0 || b > a) return 0;
    return CH[a][b];
}

int k;
int c[1005];

int main(){
    FOR(0,2001,i) FOR(0,i+1,j){
        if (j == 0 || j == i) CH[i][j] = 1;
        else CH[i][j] = CH[i - 1][j - 1] + CH[i - 1][j];
    }
    scanf("%d", &k);
    REP(k,i) scanf("%d", c + i);
    mint R = 1;
    int Count = 1;
    for (auto x : vector < int >(c, c + k)){
        R *= choose(Count - 1 + x - 1, x - 1);
        Count += x;
    } printf("%d\n", R.x);
    return 0;
}