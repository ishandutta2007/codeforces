#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;

const int INF = 1e9 + 2;

ll n, m, k;
vector<int> changed[1003];

int main()
{
    cin >> n >> m;
    string s, t;
    cin >> s >> t;
    int min_ = INF;
    int ind = 0;
    for (int i = 0; i < m - n + 1; i++)
    {
        int must_change = 0;
        for (int j = i; j < i + n; j++)
        {
            if (s[j - i] != t[j])
            {
                must_change++;
                changed[i].push_back(j - i + 1);
            }
        }
        if (must_change < min_)
        {
            min_ = must_change;
            ind = i;
        }
    }
    cout << changed[ind].size() << endl;
    for (int i = 0; i < changed[ind].size(); i++)
    {
        cout << changed[ind][i] << " ";
    }
}