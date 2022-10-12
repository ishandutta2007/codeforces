#include <bits/stdc++.h>
 
using namespace std;
 
int ask(int i)
{
    cout << "? " << i + 1 << endl;
    int x;
    cin >> x;
    return x - 1;
}
 
void solve()
{
    int n;
    cin >> n;
 
    vector<int> myp(n, -1);
    for (int i = 0; i < n; i++)
    {
        if (myp[i] == -1)
        {
            vector<int> cycle;
            int answer = ask(i);
            int x = ask(i);
            cycle.push_back(x);
            while (x != answer)
            {
                x = ask(i);
                cycle.push_back(x);
            }
            for (int j = 0; j < cycle.size(); j++)
            {
                myp[cycle[j]] = cycle[(j + 1) % cycle.size()];
            }
        }
    }
    cout << "! ";
    for (int i = 0; i < myp.size(); i++) cout << myp[i] + 1 << " ";
    cout << endl;
}
 
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}