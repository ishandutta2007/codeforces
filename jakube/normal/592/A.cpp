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
#include <queue>
#include <cmath>
#include <limits.h>

using namespace std;

#define lld long long
#define llu unsigned long long
#define all(v) v.begin(),v.end()
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

int main() {
    ios_base::sync_with_stdio(false);
    //cin.tie (NULL);
    cout.precision(10);
    cout << fixed;

    int min_A = 8;
    int min_B = 8;

    vector<string> v;

    FOR(i, 8)
        v.push_back(read<string>());


    FOR(i, 8) {
        FOR(j, 8) {
            if (v[j].at(i) != '.') {
                if (v[j].at(i) == 'W' && j < min_A)
                    min_A = j;
                break;
            }
        }
    }

    FOR(i, 8){
        for( int j = 7; j >= 0; j--) {
            if (v[j].at(i) != '.') {
                if (v[j].at(i) == 'B' && 7 - j < min_B)
                    min_B = 7 - j;
                break;
            }
        }
    }

    cout << (min_A <= min_B ? 'A' : 'B');



}