#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <math.h>
#include <chrono>
#pragma GCC optimize("-O3")
using namespace __gnu_pbds;
using namespace std;

#define endl "\n"
#define mp make_pair
#define st first
#define nd second
#define pii pair<int, int>
#define pb push_back
#define _upgrade ios_base::sync_with_stdio(0), cout.setf(ios::fixed), cout.precision(10) // ,cin.tie(0), cout.tie(0)
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define FWD(i, a, b) for (int i = (a); i < (b); ++i)

typedef long double K;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> indexed_set; // find_by_order(x) <-returns x-th element   order_of_key(x) <- returns order of element x

main()
{
    _upgrade;
    int n, k;
    cin >> n >> k;
    cout << 3 * n + min(k - 1, n - k) << endl;
}