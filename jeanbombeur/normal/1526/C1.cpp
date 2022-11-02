#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#define int long long
using namespace std;

//   <|_|>
// Check yourself before you Shrek yourself
// The hardest choices require the strongest wills

const int INF = (1000 * 1000 * 1000 + 1);
const int TAILLE_ARBRE = (1 << 18);

pair <int, int> Val[TAILLE_ARBRE];

int Tree[2 * TAILLE_ARBRE];

int nbValeurs;

void Add(int a, int val) {
    for (int i = a; i > 0; i /= 2)
    {
        Tree[i] += val;
    }
    return;
}

int GetSum(int a, int b) {
    int ans = 0;
    if (a > b)
        return 0;
    if (a & 1)
        ans += Tree[a ++];
    if (!(b & 1))
        ans += Tree[b --];
    return ans + GetSum(a / 2, b / 2);
}

int FindLeft(int a) {
    if (Tree[a] > 0)
    {
        if (a >= TAILLE_ARBRE)
            return a;
        if (Tree[2 * a + 1] > 0)
            return FindLeft(2 * a + 1);
        return FindLeft(2 * a);
    }
    if (!(a & 1))
        return FindLeft(a - 1);
    return FindLeft(a / 2);
}

void Remove(int a, int val) {
    while (val > 0)
    {
        int left = FindLeft(a);
        int d = min(Tree[left], val);
        val -= d;
        Add(left, -d);
    }
    return;
}

void Read() {
    scanf("%lld", &nbValeurs);
    for (int i = 0; i < nbValeurs; i ++)
    {
        scanf("%lld", &Val[i].first);
        Val[i].second = i + TAILLE_ARBRE;
    }
    sort(Val, Val + nbValeurs);
    reverse(Val, Val + nbValeurs);
    int ans = 0;
    for (int i = 0; i < nbValeurs; i ++)
    {
        if (GetSum(TAILLE_ARBRE, Val[i].second) + Val[i].first >= 0)
        {
            if (Val[i].first >= 0)
                Add(Val[i].second, Val[i].first);
            else
                Remove(Val[i].second, - Val[i].first);
            ans ++;
        }
    }
    printf("%lld\n", ans);
    return;
}

signed main() {
    Read();
    return 0;
}