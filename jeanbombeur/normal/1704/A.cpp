#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
#define int long long
using namespace std;

//  <|_|>

//  M. Broccoli

const int MAX_LENGTH = (2e5);

char In[MAX_LENGTH];
char Out[MAX_LENGTH];

int szIn, szOut;

void Read() {
    scanf("%lld %lld %s %s", &szIn, &szOut, In, Out);
    while (szOut > 1)
    {
        if (In[szIn - 1] != Out[szOut - 1])
        {
            printf("NO\n");
            return;
        }
        szIn --, szOut --;
    }
    int cnt = 0;
    for (int i = 0; i < szIn; i ++)
    {
        if (In[i] == Out[cnt])
            cnt ++;
    }
    if (cnt >= szOut)
        printf("YES\n");
    else
        printf("NO\n");
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