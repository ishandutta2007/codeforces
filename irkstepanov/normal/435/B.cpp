#include <bits/stdc++.h>

#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;

int main()
{

    string s;
    int k;

    cin >> s >> k;

    while (k)
    {
        int kprev = k;
        int i;
        for (i = 0; i < s.size(); i++)
        {
            for (char c = '9'; c > s[i]; c--)
            {
                int j;
                for (j = i + 1; j < s.size(); j++)
                    if (s[j] == c) break;
                if (j == s.size()) continue;
                if (k >= j - i)
                {
                    for (int x = j; x > i; x--)
                        swap(s[x], s[x - 1]);
                    k -= (j - i);
                }
            }
        }
        if (k == kprev)
            --k;
    }

    cout << s;

}