#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

//  <|_|>

//  M. Broccoli

const int MAX_VALUES = (5e5 + 1);

int Grundy[MAX_VALUES];

char In[MAX_VALUES];

vector <int> Chains;

int nbValues;

void Init() {
    for (int i = 0; i < 200; i ++)
    {
        vector <int> nv;
        for (int k = 0; k < i - 1; k ++)
        {
            nv.push_back(Grundy[i - k - 2] ^ Grundy[k]);
        }
        sort(nv.begin(), nv.end());
        nv.push_back(1 << 30);
        nv.resize(unique(nv.begin(), nv.end()) - nv.begin());
        int j = 0;
        while (nv[j] == j)
            j ++;
        Grundy[i] = j;
    }
    return;
}

void Read() {
    scanf("%d %s", &nbValues, In);
    int cur = 0;
    Chains.clear();
    int nbA = 0;
    for (int i = 0; i < nbValues; i ++)
    {
        nbA += In[i] == 'R';
        if (i && In[i] == In[i - 1])
        {
            while (cur >= 200)
                cur -= 34;
            Chains.push_back(cur);
            cur = 0;
        }
        cur ++;
    }
    while (cur >= 200)
        cur -= 34;
    Chains.push_back(cur);
    if (2 * nbA != nbValues)
    {
        if (2 * nbA > nbValues)
            printf("Alice\n");
        else
            printf("Bob\n");
        return;
    }
    int ans = 0;
    for (int a : Chains)
        ans ^= Grundy[a];
    if (!ans)
        printf("Bob\n");
    else
        printf("Alice\n");
    return;
}

signed main() {
    Init();
    int nbTests = 1;
    scanf("%d", &nbTests);
    while (nbTests --)
    {
        Read();
    }
    return 0;
}