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

bool erat[10000005];
int p[10000005];
int p2[10000005];

bool Pal(int x){
    vector < int > t;
    while (x) t.pb(x % 10), x /= 10;
    REP(t.size(),i) if (t[i] != t[t.size()-1-i]) return false;
    return true;
}

int main(){
    FOR(2,2000001,i) if (!erat[i]){
        for (int j = i; j <= 2000000; j += i) erat[j] = true;
        p[i] = 1;
    }
    FOR(1,2000001,i) if (Pal(i)) p2[i] = 1;
    REP(2000000,i) p[i+1] += p[i], p2[i+1] += p2[i];

    int p, q;
    scanf("%d%d", &p, &q);

    int r = -1;
    FOR(1,2000000,i) if (::p[i] * (ll)q <= (ll)p * p2[i]) r = i;
    //TRACE(::p[9999999] _ p2[9999999]);
    if (r != -1) printf("%d\n", r);
    else printf("Palindromic tree is better than splay tree\n");

    return 0;
}