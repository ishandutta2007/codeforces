#include <bits/stdc++.h>
using namespace std;

int main(int argc, const char *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie (NULL);
    cout.precision(10);
    cout << fixed;

    int N;
    cin >> N;
    map<int, pair<bool, bool>> m;

    int tmp;
    cin >> tmp;
    m.insert({tmp, {false, false}});
    for (int idx = 1; idx < N;  idx++)
    {
        cin >> tmp;
        
        auto it = m.lower_bound(tmp);
        if (it == m.end()) {
            m.rbegin()->second.second = true;
            cout << m.rbegin()->first << " ";
        }
        else if(it == m.begin())
        {
            m.begin()->second.first = true;
            cout << m.begin()->first << " ";
        }
        else{
            if (!it->second.first)
            {
                it->second.first = true;
                cout << it->first << " ";
            }
            else
            {
                (--it)->second.second = true;
                cout << it->first << " ";
            }

        }
        
        m.insert({tmp, {false, false}});
    }

    cout << endl;
    return 0;
}