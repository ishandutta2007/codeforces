#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <set>
#include <map>
#include <cassert>
#include <numeric>
#include <string>
#include <cstring>
#include <cmath>

using namespace std;

#define lld long long int
#define llu unsigned long long int
#define all(v) v.begin(),v.end()
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define FOR(I, N) for (int I = 0; I < (N); ++I)
#define FORR(I, A, B) for (int I = (A); I < (B); ++I)

const double EPS = 1e-4;
const lld MOD = 1000000007ll;

template<typename T>
T read()
{
    T tmp;
    cin >> tmp;
    return tmp;
}
#define readi read<int>
#define readl read<lld>

template<typename T>
vector<T> reads(int count)
{
    vector<T> values;
    values.reserve(count);
    for (int i = 0; i < count; i++)
        values.push_back(read<T>());
    return values;
}
#define readsi reads<int>
#define readsl reads<lld>

vector<int> a, p;
bool sortfunction (int i,int j) { return (p[i]<p[j]); }

int main() {
    ios_base::sync_with_stdio(false);

    long long n = read<long long>();

    long long result = 1;

    while(n % 2 == 0)
    {
        n /= 2;
        result = 2;
    }

    long long div = 3;
    while (div*div <= n)
    {
        if (n % div == 0)
        {
            result *= div;
            while (n % div == 0)
                n /= div;
        }
        div += 2;
    }

    if (n > 1)
        result *= n;


    cout << result;
}