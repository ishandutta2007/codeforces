#include <bits/stdc++.h>
using namespace std;
struct fast_ios { fast_ios(){ cin.tie(0); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } fast_ios_;


int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        string S;
        cin >> S;
        if (S == string(S.length(), S[0]))
        {
            cout << S << '\n';
        }
        else
        {
            string ret;
            for (auto c : S) ret += "01";
            cout << ret << '\n';
        }
    }
}