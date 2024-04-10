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

int main()
{
    string p, q;
    cin >> p >> q;
    string s1, s2;
    int x = int(q[0]) - int(p[0]);
    if (x >= 0)
        for (int i = 0; i < x; i++)
            s1 += 'R';
    else
        for (int i = 0; i < -x; i++)
            s1 += 'L';
    int y = int(q[1]) - int(p[1]);
    if (y >= 0)
        for (int i = 0; i < y; i++)
            s2 += 'U';
    else
        for (int i = 0; i < -y; i++)
            s2 += 'D';
    int n = max(sz(s1), sz(s2));
    cout << n << "\n";
    for (int i = 0; i < n; i++)
    {
        string s;
        if (i < sz(s1)) s += s1[i];
        if (i < sz(s2)) s += s2[i];
        cout << s << "\n";
    }
    return 0;
}