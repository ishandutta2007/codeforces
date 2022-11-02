#include <iostream>
#include <cstdio>
#include <cstring>
#define int long long
using namespace std;

//  <|_|>

//  What are you doing in my swamp ?

char Mot[20];

int Get() {
    Mot[0] = Mot[2] = 'a';
    scanf("%s", Mot);
    if (Mot[2] == 'n')
        return -1;
    if (Mot[2] == 'w')
        return 0;
    if (Mot[0] == 'U')
        return 1;
    return 2;
}

void Read() {
    printf("1 1");
    cout << endl;
    int nul = Get();
    if (nul < 0)
        return;
    printf("1 2");
    cout << endl;
    for (int i = 1; i < 8; i ++)
    {
        int ans = Get();
        int col = 2;
        while (ans >= 1)
        {
            if (ans == 1)
            {
                if (col <= 2)
                    col ^= 3;
                else
                    col = 2;
            }
            else
            {
                if (col >= 7)
                    break;
                else
                    col += 2;
            }
            printf("%lld %lld", i, col);
            cout << endl;
            ans = Get();
        }
        if (ans < 0)
            return;
        printf("%lld %lld", i + 1, col);
        cout << endl;
        if (col != 2)
        {
            ans = Get();
            if (ans < 0)
                return;
            printf("%lld 2", i + 1);
            cout << endl;
        }
    }
    return;
}

signed main() {
    int nbTests = 1;
    scanf("%lld", &nbTests);
    while (nbTests --)
    {
        Read();
    }
    return 0;
}