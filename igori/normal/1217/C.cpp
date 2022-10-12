#include <iostream>
#include <vector>
#include <algorithm>
#include <time.h>
#include <string>

using namespace std;

int summ[500000];

int main()
{
    int q;
    cin >> q;
    while (q--)
    {
        string s;
        cin >> s;
        int n = s.size();
        fill(summ, summ + n + 1, 0);
        for (int i = 0; i < s.size(); i++)
        {
            summ[i] = s[i] - '0';
            if (i) summ[i] += summ[i - 1];
        }
        long long ans = 0;
        for (int i = 0; i < n; i++)
        {
            long long kek = 0, bits = 0, kk = 1;
            for (int j = i; j >= max(0, i - 30); j--)
            {
                kek = kek + (s[j] - '0') * kk;
                kk *= 2;
                bits += s[j] - '0';
                int len = i - j + 1;
                if (kek == len)
                {
                    ans++;
                }
            }
            long long supposion = i - kek + 1;
            if (supposion < 0 || supposion >= i - 30)
            {
                continue;
            }
            if (summ[i] - (supposion > 0 ? summ[supposion - 1] : 0) == bits)
            {
                ans++;
            }
        }
        cout << ans << "\n";
    }
}