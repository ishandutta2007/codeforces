#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#define int long long
using namespace std;

//  <|_|>

//

const int SIZE = (1 << 17);
const int MAX_VALUES = (2e5);

char Start[MAX_VALUES];
char Goal[MAX_VALUES];

vector <int> Occ[26];

pair <char, int> Tree[2 * SIZE];

int nbChar;

void Upd(int node) {
    for (int n = node / 2; n; n /= 2)
        Tree[n] = make_pair(min(Tree[2 * n].first, Tree[2 * n + 1].first), Tree[2 * n].second + Tree[2 * n + 1].second);
    return;
}

int GetSum(int left, int right) {
    int ans = 0;
    for (left += SIZE, right += SIZE; left < right; left >>= 1, right >>= 1)
    {
        if (left & 1)
            ans += Tree[left ++].second;
        if (right & 1)
            ans += Tree[-- right].second;
    }
    return ans;
}

int Search(int node, int target) {
    if (node >= SIZE)
        return 0;
    if (Tree[2 * node].first < target)
        return Search(2 * node, target);
    return Search(2 * node + 1, target) + Tree[2 * node].second;
}

void Solve() {
    scanf("%lld %s %s", &nbChar, Start, Goal);
    for (int i = SIZE; i < nbChar + SIZE; i ++)
    {
        Tree[i] = make_pair(Start[i - SIZE], 1);
        Upd(i);
    }
    for (int i = 0; i < 26; i ++)
    {
        Occ[i].clear();
    }
    for (int i = nbChar - 1; i >= 0; i --)
    {
        Occ[Start[i] - 'a'].push_back(i);
    }
    int ans = 1LL << 60;
    int last = 0;
    for (int i = 0; i < nbChar; i ++)
    {
        if (Tree[1].first < Goal[i])
        {
            ans = min(ans, last + Search(1, Goal[i]));
        }
        if (Occ[Goal[i] - 'a'].size())
        {
            int id = Occ[Goal[i] - 'a'].back();
            // printf(":::%lld\n", id);
            last += GetSum(0, id);
            Tree[id + SIZE] = make_pair('z', 0);
            Upd(id + SIZE);
            Occ[Goal[i] - 'a'].pop_back();
        }
        else
            break;
        // printf("%lld::%lld\n", ans, last);
    }
    for (int i = 0; i < nbChar; i ++)
    {
        Tree[i + SIZE] = make_pair('z', 0);
        Upd(i + SIZE);
    }
    if (ans == (1LL << 60))
        ans = -1;
    printf("%lld\n", ans);
    return;
}

signed main() {
    int nbTests = 1;
    scanf("%lld", &nbTests);
    fill_n(Tree, 2 * SIZE, make_pair('z', 0));
    while (nbTests --)
    {
        Solve();
    }
    return 0;
}