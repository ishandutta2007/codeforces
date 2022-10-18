#include <bits/stdc++.h>

using namespace std;

#define ALL(v) v.begin(),v.end()
#define FOR(I, N) for (int I = 0; I < (N); ++I)
#define FORR(I, A, B) for (int I = (A); I < (B); ++I)

typedef long long int lint;
typedef long double ld;

const double EPS = 1e-4;
const lint MOD = 1000000007L;


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

lint calc(lint upper, lint number)
{
    if (upper == 0)
        return 0;
    return ((upper - 1) / number) + 1;
}

lint mypow(lint n, lint k)
{
    lint result = 1;
    FOR(i, k)
        result *= n;
    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    //cin.tie (NULL);
    cout.precision(10);
    cout << fixed;

    int n = readi();
    int k = readi();

    vector<int> a = readsi(n/k);
    vector<int> b = readsi(n/k);

    lint result = 1;

    FOR(i, n/k)
    {
        lint t = calc(mypow(10L, k), a[i]) - (calc((b[i] + 1) * mypow(10L, k - 1), a[i]) -
                                          calc(b[i] * mypow(10L, k - 1), a[i]));
        result = (result * t) % MOD;
    }

    cout << result << endl;
}