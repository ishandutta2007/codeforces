#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <sstream>
#include <iostream>
#include <queue>
//#include <cmath>

#define mp make_pair
#define sz(v)((int)((v).size()))
#define all(v) v.begin(),v.end()
#define pb push_back

using namespace std;

typedef pair<int, int> ii;
typedef long long int64;
typedef vector<int> vi;

template<class T> T abs(T x) {return x > 0 ? x : (-x);}
template<class T> T sqr(T x) {return x * x;}

map<string, int> M;
vector<pair<string, int> > v;

bool better(string s1, string s2)
{
    if (M[s1] != M[s2])
        return M[s1] > M[s2];
    int m = M[s1];
    for (int i = 0; i < sz(v); i++)
    {
        if (v[i].first == s1 && v[i].second >= m) return true;
        if (v[i].first == s2 && v[i].second >= m) return false;
    }
    return false;
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string s;
        int x;
        cin >> s >> x;
        M[s] += x;
        v.pb(mp(s, M[s]));
    }
    string res = M.begin()->first;
    for (map<string, int>::iterator it = M.begin(); it != M.end(); it++)
    {
        if (better(it->first, res))
            res = it->first;
    }
    cout << res << "\n";
    return 0;
}