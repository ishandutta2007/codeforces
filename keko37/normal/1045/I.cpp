#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <ext/pb_ds/assoc_container.hpp>

#define X first
#define Y second
#define MP make_pair
#define PB push_back

using namespace __gnu_pbds;
using namespace std;

typedef long long ll;
typedef pair < int, int > pii;
typedef pair < ll, ll > pll;
typedef vector < int > vi;
typedef vector < ll > vl;

const int N = 1e5 + 500;
const int M = 1e6 + 500;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int LOG = 26;
const int OFF = (1 << LOG);
const double EPS = 1e-9;
const double PI = 3.1415926535;

int n, l;
char s[M];
gp_hash_table < int , int > bio;
vi par, nep;
ll sol = 0;

int main(){
    scanf("%d", &n);
    for(int i = 0;i<n;i++){
        scanf("%s", s);
        l = strlen(s);
        int msk = 0;
        for(int j = 0;j<l;j++)
            msk ^= (1 << (s[j] - 'a'));
        for(int j = 0;j<26;j++)
            nep.PB(msk ^ (1 << j));
        par.PB(msk);
    }
    sort(par.begin(), par.end());
    sort(nep.begin(), nep.end());
    for(int i = 0;i<par.size();){
        int oi = i;
        while(i < par.size() && par[i] == par[oi]) i++;
        sol += (ll)(i - oi) * (ll)(i - oi - 1) / 2LL;
    }
    int j = 0;
    ll sol2 = 0;
    for(int i = 0;i<nep.size();){
        int oi = i;
        while(i < nep.size() && nep[i] == nep[oi]) i++;
        while(j < par.size() && par[j] < nep[oi]) j++;
        int oj = j;
        while(j < par.size() && par[j] == nep[oi]) j++;
        sol2 += (ll)(i - oi) * (ll)(j - oj);
    }
    sol += sol2 / 2LL;
    printf("%lld\n", sol);
    return 0;
}