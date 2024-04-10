#include <bits/stdc++.h>

using namespace std;

#define ALL(v) v.begin(),v.end()
#define FOR(I, N) for (int I = 0; I < (N); ++I)
#define FORR(I, A, B) for (int I = (A); I < (B); ++I)

const double EPS = 1e-4;

typedef long long int lint;
typedef long double ld;

template<typename T>
T read()
{
    T tmp;
    cin >> tmp;
    return tmp;
}
#define readi read<int>

template<typename T>
vector<T> reads(int count){
    vector<T> values;
    values.reserve(count);
    for (int i = 0; i < count; i++)
        values.push_back(read<T>());
    return values;
}
#define readsi reads<int>

int main() {
    ios_base::sync_with_stdio(false);
    //cin.tie (NULL);
    cout.precision(10);
    cout << fixed;

    int n = readi();
    int x1 = readi();
    int x2 = readi();

    vector<pair<int, int>> v;
    FOR(i, n)
    {
        int tmp, tmp2;
        cin >> tmp >> tmp2;
        v.push_back(make_pair(tmp, tmp2));
    }

    sort(ALL(v), [x1, x2](pair<int, int> i, pair<int, int> j){
        lint a = i.first*(lint)x1 + i.second;
        lint b = i.first*(lint)x2 + i.second;
        lint c = j.first * (lint)x1 + j.second;
        lint d = j.first * (lint)x2 + j.second;
        if (min(a, b) < min(c, d))
            return true;
        if (min(a, b) == min(c, d))
            return (max(a, b) < max(c, d));
        return false;
    });

    auto it = adjacent_find(ALL(v), [x1, x2](pair<int, int> i, pair<int, int> j){
        lint a = i.first*(lint)x1 + i.second;
        lint b = i.first*(lint)x2 + i.second;
        lint c = j.first * (lint)x1 + j.second;
        lint d = j.first * (lint)x2 + j.second;

        if (i.first*(lint)j.first >= 0)
        {
            return max(a, b) > max(c, d);
        }

        if (min(a, b) == min(c, d) && max(a, b) == max(c, d))
            return true;


        return ((min(a, b) < c && c < max(a, b)) ||
                (min(a, b) < d && d < max(a, b)) ||
                (min(c, d) < a && a < max(c, d)) ||
                (min(c, d) < b && b < max(c, d)));
    });

    if (it != v.end())
        cout << "YES";
    else
        cout << "NO";
}