// KingPonyHead
#include<bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;
const int N = 1e6 + 77;
int n, q, W[N], D[N];
int main()
{
    cin >> q;
    while (q --)
    {
        cin >> n;
        for (int i = 1; i <= n; i ++)
            cin >> W[i];
        set < pair < int , int > > S;
        for (int i = 1; i <= n; i ++)
            D[i] = 0;
        for (int i = 1; i < n; i ++)
        {
            int a, b;
            cin >> a >> b;
            D[a] ++;
            D[b] ++;
        }
        ll SM = 0;
        for (int i = 1; i <= n; i ++)
        {
            SM += W[i], D[i] --;
            if (D[i])
            S.insert({W[i], i});
        }
        cout << SM;
        for (int i = 2; i < n; i ++)
        {
            auto X = * S.rbegin();
            S.erase(X);
            SM += X.first;
            D[X.second] --;
            if (D[X.second])
                S.insert(X);
            cout << " " << SM;
        }
        cout << "\n";
    }
}