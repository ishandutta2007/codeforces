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

    lint n, t, sum, i;
    cin >> n;
    FOR(j, n) {
        cin >> t;
        if (t%2==0)
            sum = (t/2)*(t+1);
        else
            sum = t*((t+1)/2);
        for (i=1; i <= t; i*=2)
            sum -= 2*i;
        cout << sum << endl;
    }
}