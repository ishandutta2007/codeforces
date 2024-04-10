#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <cstring>
#include <cstdio>
#include <cassert>
#include <queue>
#include <bitset>
#include <cmath>
#include <sstream>
#include <string>
#include <vector>

#define mp make_pair
#define pb push_back
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),(v).end()

using namespace std;

typedef pair<int, int> ii;
typedef long long int64;
typedef vector<int> vi;

template<class T> T abs(T x) {return x > 0 ? x : (-x); }
template<class T> T sqr(T x) {return x * x; }

vector<string> tokenize(string s)
{
    vector<string> res;
    string cur;
    for (int i = 0; i < sz(s); ++i)
    {
        if (s[i] == '>')
        {
            cur += s[i];
            res.pb(cur);
            cur = "";
        }
        else
        {
            cur += s[i];
        }
    }
    return res;
}

int main()
{
    string s;
    char c;
    while (1)
    {
        c = getc(stdin);
        if (c == EOF) break;
        if (isspace(c)) continue;
        s += c;
    }
    vector<string> v = tokenize(s);
    vi res;
    vi st;
    int cur = 0;
    for (int i = 0; i < sz(v); ++i)
    {
        if (v[i] == "<table>")
        {
            st.pb(cur);
            cur = 0;
            continue;
        }
        if (v[i] == "</table>")
        {
            res.pb(cur);
            cur = st[sz(st) - 1];
            st.pop_back();
            continue;
        }
        if (v[i] == "<td>") ++cur;
    }
    sort(all(res));
    for (int i = 0; i < sz(res); ++i)
        cout << res[i] << " ";
    cout << "\n";
    return 0;
}