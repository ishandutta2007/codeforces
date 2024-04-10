#include <iostream>
#include <vector>
#include <set>
#include <cstdio>
#include <algorithm>
#include <map>
using namespace std;
typedef long long i64;
#define forn(i, n) for(int i = 0; i < (int)(n); i++)
const int maxn = 200500;

int n;
string s1, s2;

i64 s[maxn];
double get(const vector<int> &a, const vector<int> &b)
{
    forn(i, n)
    {
        s[i] = b[i]?(i+1):0;
        if (i) s[i] += s[i-1];
    }
    double res = 0;
    forn(i, n) if (i && a[i])
        res += s[i-1] * (n-i);
    return res;
}

void solve()
{
    double s = 0;
    vector<int> a(n), b(n);
    forn(I, 2)
    {
        for (char c = 'A'; c <= 'Z'; c++)
        {
            forn(i, n) a[i] = s1[i] == c;
            forn(i, n) b[i] = s2[i] == c;
            //cerr << get(a, b) << endl;
            s += get(a, b);
            //cerr << s << endl;
        }
        swap(s1, s2);
    }
    forn(i, n) if (s1[i] == s2[i])
        s += double(i+1)*(n-i);
    
    cout.precision(10);
    cout << fixed;
    //cout << s << endl;
    cout << (double) s / ((double)n*(n+1)*(2*n+1)/6.) << endl;
}

int main()
{
    //freopen("input.txt", "r", stdin);
    
    cin >> n >> s1 >> s2;
    solve();
    
    return 0;
}