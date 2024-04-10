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

    string s;
    cin >> s;

    vector<char> cs;
    for (char c : s)
        cs.push_back(c);

    int n;
    cin >> n;
    FOR(i, n)
    {
        int l, r, k;
        cin >> l >> r >> k;

        vector<char> cs2(cs);
        FORR(j, l-1, r)
        {
            cs2[(j - (l-1) + k) % (r-l+1) + (l-1)] = cs[j];
        }
        cs = cs2;
    }
    for(char c:cs)
        cout << c;
}