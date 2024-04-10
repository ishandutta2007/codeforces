#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <unordered_set>

using namespace std;

vector<string> s;
unordered_set<long long> q;
int n;

int main()
{
    /*freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);*/
    cin >> n;
    s.resize(n);
    getline(cin, s[0]);
    for (int i = 0; i < n; i++)
        getline(cin, s[i]);
    for (int i = n - 1; i >= 0; i--)
    {
        long long h = 0;
        for (int j = 0; j < s[i].length(); j++)
            h = 27 * h + (s[i][j] - 'a' + 1);
        if (q.find(h) == q.end())
        {
            cout << s[i] << endl;
            q.insert(h);
        }
    }
    return 0;
}