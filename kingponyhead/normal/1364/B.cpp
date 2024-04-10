// Screw this ..
#include<bits/stdc++.h>
#define pb push_back
using namespace std;
const int N = 1e6 + 9, Mod = 1e9 + 7;
int n, q, m, A[N];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> q;
    for (; q; q --)
    {
        cin >> n;
        long long SM = 0;
        vector < int > vec;
        for (int i = 1; i <= n; i ++)
        {
            cin >> A[i];
            if (!vec.size())
            {
                vec.push_back(A[i]);
                continue;
            }
            if (vec.size() == 1)
            {
                SM += abs(A[i] - vec.back());
                vec.push_back(A[i]);
                continue;
            }
            if (abs(vec.back() - A[i]) + abs(vec.back() - vec[(int)vec.size() - 2]) == abs(A[i] - vec[(int)vec.size() - 2]))
                vec.pop_back();
            SM += abs(A[i] - vec.back());
            vec.push_back(A[i]);
        }
        printf("%d\n", (int)vec.size());
        for (int i : vec)
            printf("%d ", i);
        printf("\n");
    }
    return 0;
}