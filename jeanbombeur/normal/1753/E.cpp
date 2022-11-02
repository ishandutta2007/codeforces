#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#define int long long
using namespace std;

//  <|_|>

//  M. Broccoli

const int MAX_MACHINES = (1e6);
const int MAX_LOG = 30;

vector <pair <int, int>> Mult;

int CurMult[MAX_LOG];

vector <int> Machines[MAX_LOG];

vector <int> Sets;

int nbMachines, budget, priceAdd, priceMult;

void TestAll(int i, int nb, int cur) {
    if (!nb)
        Sets.push_back(cur);
    if (i >= (int)Mult.size())
        return;
    int j = i + 1;
    while (j < (int)Mult.size() && Mult[j].first == Mult[i].first)
        j ++;
    for (int k = 0; k <= min(nb, j - i); k ++)
    {
        TestAll(j, nb - k, cur);
        cur ^= 1 << (i + k);
    }
    return;
}

int Dicho(int id, int mult, int mini, int sum) {
    int pos = -1;
    int sz = Machines[id].size();
    for (int jump = 1 << MAX_LOG; jump; jump >>= 1)
    {
        if (pos + jump < sz - 1 && (Machines[id][pos + jump + 1] - Machines[id][pos + jump]) * mult >= mini)
            pos += jump;
    }
    return sum ? mult * (Machines[id][++ pos] - Machines[id][0]) : ++ pos;
}

void Read() {
    scanf("%lld %lld %lld %lld\n", &nbMachines, &budget, &priceAdd, &priceMult);
    int fullMult = 1;
    for (int i = 0; i < nbMachines; i ++)
    {
        int a;
        char x;
        scanf("%c %lld\n", &x, &a);
        if (x == '*' && a > 1)
        {
            Mult.push_back({a, Mult.size()});
            fullMult *= a;
        }
        if (x == '+')
            Machines[Mult.size()].push_back(a);
    }
    int ans = 0;
    sort(Mult.begin(), Mult.end());
    int sz = Mult.size();
    for (int i = 0; i <= sz; i ++)
    {
        Machines[i].push_back(1LL << 31);
        sort(Machines[i].begin(), Machines[i].end());
        reverse(Machines[i].begin(), Machines[i].end());
        for (int j = 1; j < (int)Machines[i].size(); j ++)
        {
            Machines[i][j] += Machines[i][j - 1];
        }
    }
    for (int nb = 0; nb <= budget / priceMult; nb ++)
    {
        Sets.clear();
        TestAll(0, nb, 0);
        int nbMoves = (budget - nb * priceMult) / priceAdd;
        for (int mask : Sets)
        {
            int start = 1;
            CurMult[sz] = 1;
            for (int i = 0; i < sz; i ++)
            {
                CurMult[Mult[i].second] = Mult[i].first;
                if ((mask >> i) & 1)
                {
                    CurMult[sz] *= Mult[i].first;
                    CurMult[Mult[i].second] = 1;
                }
            }
            for (int i = 0; i <= sz; i ++)
            {
                start += Machines[i].back() - Machines[i][0];
                start *= CurMult[i];
            }
            int cross = -1;
            for (int jump = 1LL << 62; jump; jump >>= 1)
            {
                int mult = 1;
                int sum = 0;
                for (int i = sz; i >= 0; i --)
                {
                    mult *= CurMult[i];
                    sum += Dicho(i, fullMult - mult, cross + jump, 0);
                }
                if (sum >= nbMoves)
                    cross += jump;
            }
            int sum = 0;
            int cnt = 0;
            int mult = 1;
            for (int i = sz; i >= 0; i --)
            {
                mult *= CurMult[i];
                sum += Dicho(i, fullMult - mult, cross, 1);
                cnt += Dicho(i, fullMult - mult, cross, 0);
            }
            sum -= (cnt - nbMoves) * cross;
            ans = max(ans, sum + start);
        }
    }
    printf("%lld\n", ans);
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