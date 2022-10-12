#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <map>

using namespace std;
#define all(x) (x).begin(), (x).end()
#define forn(i, n) for (int i = 0; i != (n); i++)
#define fi first
#define se second
#define pb push_back
#define sz size()

int n;

int main()
{
    cin >> n;
    string s;
    cin >> s;
    vector<char> perm;
    perm.push_back('B');
    perm.push_back('R');
    perm.push_back('G');
    int ans = 1e9;
    vector<char> ccc;
    forn(i, 6)
    {
        next_permutation(all(perm));
        vector<char> cc(n);
        for (int j = 0; j < n; j++)
        {
            cc[j] = perm[j % 3];
        }
        int v = 0;
        for (int i = 0; i < n; i++)
        {
            v += s[i] != cc[i];
        }
        if (v < ans)
        {
            ans = v;
            ccc = cc;
        }
    }
    cout << ans << endl;
    for (int i = 0; i < n; i++)
    {
        cout << ccc[i];
    }
}