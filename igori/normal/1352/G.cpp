#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <algorithm>
#include <cmath>
#include <time.h>
#include <unordered_set>
#include <bitset>
#include <deque>

using namespace std;

void solve()
{
    int n;
    cin >> n;
    if (n <= 3)
    {
        cout << -1 << "\n";
        return;
    }
    deque<int> kek;
    kek.push_back(3);
    kek.push_back(1);
    kek.push_back(4);
    kek.push_back(2);
    for (int i = 5; i <= n; i++)
    {
        if (i % 2 == 1) kek.push_back(i);
        else kek.push_front(i);
    }
    while (kek.size())
    {
        cout << kek.front() << " ";
        kek.pop_front();
    }
    cout << "\n";
}

signed main()
{
    srand(time(NULL));
    #ifdef ONLINE_JUDGE
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
    #endif // ONLINE_JUDGE
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}