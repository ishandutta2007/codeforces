#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
#define int long long
using namespace std;

//  <|_|>

//  We must be better

const int NB = 4;
const int MAX_VALUES = (2e5);

char Val[MAX_VALUES];

int Nb[NB]; // A B AB BA

vector <int> PossibA;
vector <int> PossibB;

void Solve() {
    for (int i = 0; i < NB; i ++)
    {
        scanf("%lld", &Nb[i]);
    }
    scanf("%s", Val);
    int nbA = 0, nbB = 0;
    int sz = strlen(Val);
    for (int i = 0; i < sz; i ++)
    {
        nbA += Val[i] == 'A';
        nbB += Val[i] == 'B';
    }
    if (nbA != Nb[0] + Nb[2] + Nb[3] || nbB != Nb[1] + Nb[2] + Nb[3])
    {
        printf("NO\n");
        return;
    }
    PossibA.clear();
    PossibB.clear();
    int sum = 0;
    for (int i = 0; i < sz; i ++)
    {
        if (i == 0 || Val[i] == Val[i - 1])
        {
            int start = i ++;
            while (i < sz && Val[i] != Val[i - 1])
                i ++;
            int l = i - start;
            if (l & 1)
                sum += l / 2;
            else
            {
                if (Val[start] == 'A')
                    PossibA.push_back(l / 2);
                else
                    PossibB.push_back(l / 2);
            }
            i --;
        }
    }
    sort(PossibA.begin(), PossibA.end());
    sort(PossibB.begin(), PossibB.end());
    reverse(PossibA.begin(), PossibA.end());
    reverse(PossibB.begin(), PossibB.end());
    while (!PossibA.empty() && Nb[2] >= PossibA.back())
    {
        Nb[2] -= PossibA.back();
        PossibA.pop_back();
    }
    while (!PossibB.empty() && Nb[3] >= PossibB.back())
    {
        Nb[3] -= PossibB.back();
        PossibB.pop_back();
    }
    for (int a : PossibA)
        sum += a - 1;
    for (int a : PossibB)
        sum += a - 1;
    if (sum >= Nb[2] + Nb[3])
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
        Solve();
    }
    return 0;
}