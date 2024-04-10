// Screw this ..
#include<bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;
const int N = 1e6 + 9, Mod = 1e9 + 7;
int n, q, m, A[N];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> q;
    for (; q; q --)
    {
        string S;
        cin >> S;
        n = (int)S.size();
        int cnt[2] = {0, 0};
        int tt = 0;
        for (int i = 0; i < n; i ++)
        {
            int w = (S[i] - '0');
            int ww = (S[i] - '0') ^ 1;
            if (cnt[ww])
                cnt[ww] --, tt ++;
            else
                cnt[w] ++;
        }
        puts(tt & 1 ? "DA" : "NET");
    }
    return 0;
}