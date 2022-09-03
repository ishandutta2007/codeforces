#include <iostream>
#include <cmath>
#include <algorithm>
#include <queue>

using namespace std;

int n, k1, k2, a;
queue<int> st1, st2;

int main()
{
    cin >> n;
    cin >> k1;
    for (int i = 0; i < k1; i++)
    {
        cin >> a;
        st1.push(a);
    }
    cin >> k2;
    for (int i = 0; i < k2; i++)
    {
        cin >> a;
        st2.push(a);
    }
    for (int i = 0; i < 1000000; i++)
    {
        if (st1.size() == 0)
        {
            cout << i << " " << 2;
            return 0;
        }
        if (st2.size() == 0)
        {
            cout << i << " " << 1;
            return 0;
        }
        int g1 = st1.front();
        st1.pop();
        int g2 = st2.front();
        st2.pop();
        if (g1 > g2)
        {
            st1.push(g2);
            st1.push(g1);
            continue;
        }
        st2.push(g1);
        st2.push(g2);
    }
    cout << -1;
    return 0;
}