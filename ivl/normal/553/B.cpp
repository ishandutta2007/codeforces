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

int n;
ll k;

ll F[105];

int main(){
    F[0] = F[1] = 1;
    FOR(2,55,i) F[i] = F[i - 1] + F[i - 2];
    scanf("%d%I64d", &n, &k), --k;
    for (int p = 0; p < n;){
        if (k < F[n - 1 - p]) printf("%d ", p + 1), ++p;
        else printf("%d %d ", p + 2, p + 1), k -= F[n - 1 - p], p += 2;
    } printf("\n");
    return 0;
}