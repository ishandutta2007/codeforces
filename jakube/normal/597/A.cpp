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

lint dividable(lint limit, lint divisor)
{
    return limit / divisor + 1;
}

int main() {
    int max = INT_MAX / 2;

    ios_base::sync_with_stdio(false);
    //cin.tie (NULL);
    cout.precision(10);
    cout << fixed;

    lint k, a, b;
    cin >> k >> a >> b;


    if (a >= 0)
    {
        lint result = dividable(b, k);
        if (a > 0)
            result -= dividable(a-1, k);
        cout << result;
    }
    else if (a < 0 && b >= 0)
    {
        lint result = dividable(b, k);
        result += dividable(-a, k) - 1;
        cout << result;
    }
    else
    {
        lint result = dividable(-a, k) - dividable(-b - 1, k);
        cout << result;
    }

}