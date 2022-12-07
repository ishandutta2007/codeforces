#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#include <deque>
#include <string>
#include <string.h>
#include <queue>
#include <stdlib.h>
#include <set>

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
const ld PI = acosl(-1.);
using namespace std;

const int N = 100111;

struct cell {
    int a, b, num;

    cell(int aa = 0, int ab = 0, int anum = 0) {
        a = aa;
        b = ab;
        num = anum;
    }

    bool operator<(const cell& A) const {
        return b < A.b || (b == A.b && a > A.a);
    }
} a[N];

int main() {
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);

    int n, p, k;
    scanf("%d%d%d", &n, &p, &k);

    for (int i = 0; i < n; ++i) {
        int A, B;
        scanf("%d%d", &A, &B);
        a[i] = cell(A, B, i + 1);
    }

    sort(a, a + n);

    priority_queue< pair< pair<int, int> , int> > q;    
    for (int i = p - k; i < n; ++i) {
        q.push(make_pair(make_pair(a[i].a, i), a[i].num)); 
    }

    int mn = n;
    for (int i = 0; i < k; ++i) {
        pair< pair<int, int>, int> w = q.top(); q.pop();
        printf("%d ", w.second);
        mn = min(mn, w.first.second);
    }
    int t = p - k;
    while (t--) {
        printf("%d ", a[--mn].num);
    }
    
    puts("");

    return 0;
}