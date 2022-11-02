#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
#define int long long
using namespace std;

//  <|_|>

//  M. Broccoli

const int MAX_ROWS = (2e5);

int Lig[MAX_ROWS];
int Col[MAX_ROWS];

int BorderLig[MAX_ROWS];
int BorderCol[MAX_ROWS];

int nbRows, nbColumns;
int startLig, startCol;

bool Check(int val) {
    if (val < Lig[0] + Col[0])
        return false;
    if (val >= Lig[startLig] + Col[startCol])
        return true;
    int ansWith = 0, ansWithout = 0;
    BorderLig[0] = nbColumns;
    for (int i = 0; i < nbRows; i ++)
    {
        if (i)
            BorderLig[i] = BorderLig[i - 1];
        while (BorderLig[i] && Lig[i] + Col[BorderLig[i] - 1] > val)
            BorderLig[i] --;
        ansWith += BorderLig[i];
    }
    ansWith = nbRows * nbColumns - ansWith;
    ansWithout = ansWith - 1;
    BorderCol[0] = nbRows;
    for (int i = 0; i < nbColumns; i ++)
    {
        if (i)
            BorderCol[i] = BorderCol[i - 1];
        while (BorderCol[i] && Col[i] + Lig[BorderCol[i] - 1] > val)
            BorderCol[i] --;
    }
    int sum = ansWith;
    int nbTaken = 0;
    for (int i = 0; i < nbRows; i ++)
    {
        sum += nbTaken + BorderLig[i] - nbColumns;
        ansWith = max(ansWith, sum);
        ansWithout = max(ansWithout, sum - (i <= startLig && nbTaken <= startCol));
        while (nbTaken < nbColumns && i + 1 + BorderCol[nbTaken] - nbRows >= 0)
        {
            sum += i + 1 + BorderCol[nbTaken] - nbRows;
            nbTaken ++;
            ansWith = max(ansWith, sum);
            ansWithout = max(ansWithout, sum - (i <= startLig && nbTaken <= startCol));
        }
    }
    return ansWith == ansWithout;
}

void Read() {
    scanf("%lld %lld", &nbRows, &nbColumns);
    for (int i = 0; i < nbRows; i ++)
    {
        scanf("%lld", &Lig[i]);
    }
    for (int i = 0; i < nbColumns; i ++)
    {
        scanf("%lld", &Col[i]);
    }
    startLig = Lig[0], startCol = Col[0];
    sort(Lig, Lig + nbRows);
    sort(Col, Col + nbColumns);
    for (int i = 0; i < nbRows; i ++)
    {
        if (startLig == Lig[i])
        {
            startLig = i;
            break;
        }
    }
    for (int i = 0; i < nbColumns; i ++)
    {
        if (startCol == Col[i])
        {
            startCol = i;
            break;
        }
    }
    int ans = -1;
    for (int jump = (1 << 30); jump; jump >>= 1)
    {
        if (!Check(ans + jump))
            ans += jump;
    }
    printf("%lld\n", ++ ans);
    return;
}

signed main() {
    int nbTests = 1;
    // scanf("%lld", &nbTests);
    while (nbTests --)
    {
        Read();
    }
    return 0;
}