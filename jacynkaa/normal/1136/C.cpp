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

bool porownaj(vector<int> &A, vector<int> &B)
{
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    REP(i, A.size())
    if (A[i] != B[i])
        return false;
    return true;
}

main()
{
    _upgrade;
    int n, m;
    cin >> n >> m;

    vector<vector<int>> AP(10000);
    vector<vector<int>> BP(10000);
    int x;
    REP(i, n)
    REP(j, m)
    {
        cin >> x;
        AP[i + j].push_back(x);
    }
    REP(i, n)
    REP(j, m)
    {
        cin >> x;
        BP[i + j].push_back(x);
    }
    REP(i, 2000)

    if (porownaj(AP[i], BP[i]) == false)
    {
        cout << "NO" << endl;
        exit(0);
    }
    cout << "YES" << endl;
}