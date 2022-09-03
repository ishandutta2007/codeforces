#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        string S;
        cin >> S;
        vector<string> ret;
        for (int i = 0; i < S.length(); i++) if (S[i] != '0')
        {
            string T(S.length() - i, '0');
            T[0] = S[i];
            ret.emplace_back(T);
        }
        cout << ret.size() << '\n';
        for (auto s : ret) cout << s << ' ';
        cout << '\n';
    }
}