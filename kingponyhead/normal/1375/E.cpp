// Ponies everywhere ...
#include<bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;
const int N = 1009, Mod = 1e9 + 7;
int n, m, q, A[N], R[N];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n;
    vector < pair < int , int > > V, T;
    for (int i = 1; i <= n; i ++)
        cin >> A[i], V.push_back({A[i], i});
    sort(V.begin(), V.end());
    for (int i = 0; i < n; i ++)
        A[V[i].second] = i + 1;
    for (int i = 1; i <= n; i ++)
        R[A[i]] = i;
    for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= n - i; j ++)
            if (R[j] > R[j + 1])
                swap(R[j], R[j + 1]), T.push_back({R[j], R[j + 1]});
    printf("%d\n", (int)T.size());
    for (auto X : T)
        printf("%d %d\n", X.first, X.second);
    return 0;
}