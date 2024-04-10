#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int N;
        cin >> N;
        long long tot = (1LL << (N + 1)) - 2;
        long long sub = ((1LL << (N / 2)) - 1) << (N / 2);
        long long diff = abs(sub - (tot - sub));
        cout << diff << '\n';
    }
}