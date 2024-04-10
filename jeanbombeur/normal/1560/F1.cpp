#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define int long long
using namespace std;

//  <|_|>

//  A wizard is never late nor early. He arrives precisely when he means to

const int MAX_DIGITS = (10);

int Digits[MAX_DIGITS];
int Seen[MAX_DIGITS];
int IsMax[MAX_DIGITS];

void Solve() {
    int n, k;
    scanf("%lld %lld", &n, &k);
    fill_n(Seen, MAX_DIGITS, 0);
    int nb = 0;
    while (n > 0)
        Digits[nb ++] = n % 10, n /= 10;
    int maxFixed = nb;
    int maxDigit = 0, minDigit = 9;
    for (int i = nb - 1; i >= 0; i --)
    {
        if ((Seen[Digits[i]] == 0) <= k)
        {
            k -= Seen[Digits[i]] ++ == 0;
            maxFixed = i;
            IsMax[i] = Digits[i] >= maxDigit;
            maxDigit = max(maxDigit, Digits[i]);
            minDigit = min(minDigit, Digits[i]);
        }
        else
        {
            if (Digits[i] > maxDigit)
            {
                for (int j = i + 1; j < nb; j ++)
                {
                    k += -- Seen[Digits[j]] == 0;
                    if (IsMax[j] && k == 0)
                        maxFixed = j + 1;
                    else
                    {
                        minDigit = 9;
                        for (int l = nb - 1; l > j; l --)
                        {
                            minDigit = min(minDigit, Digits[l]);
                        }
                        if (k == 0)
                        {
                            for (int l = Digits[j] + 1; l < 10; l ++)
                            {
                                if (Seen[l])
                                {
                                    Digits[j] = l;
                                    break;
                                }
                            }
                        }
                        else
                        {
                            Digits[j] ++;
                            minDigit = min(minDigit, Digits[j]);
                            if (k >= 2 || Seen[Digits[j]])
                                minDigit = 0;
                        }
                        break;
                    }
                }
            }
            else
            {
                for (int j = Digits[i] + 1; j < 10; j ++)
                {
                    if (Seen[j])
                    {
                        Digits[i] = j;
                        break;
                    }
                }
                maxFixed = i;
            }
            break;
        }
    }
    for (int i = nb - 1; i >= maxFixed; i --)
    {
        printf("%c", (char)Digits[i] + '0');
    }
    for (int i = maxFixed - 1; i >= 0; i --)
    {
        printf("%c", (char)minDigit + '0');
    }
    printf("\n");
    return;
}

signed main() {
    int nbTests = 1;
    scanf("%lld", &nbTests);
    while (nbTests --)
    {
        Solve();
    }
    return 0;
}