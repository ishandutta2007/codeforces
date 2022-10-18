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

int main() {
    int count = readi();
    vector<vector<lld>> values;
    values.reserve(count);
    FOR(i, count) {
        vector<lld> t = readsl(3);
        t.push_back(1);
        values.push_back(t);
    }

    vector<int> children;
    FOR(i, count)
    {
        if (values[i][3]) //still in line
        {
            children.push_back(i);
            //cry in doctors office

            long cry = values[i][0];
            int current = i+1;
            while (cry > 0 && current<values.size())
            {
                if (values[current][3])
                {
                    values[current][2] -= cry;
                    cry--;
                }
                current++;
            }

            //cry in hall
            cry = 0;
            FORR(cur, i+1, values.size())
            {
                if (values[cur][3])
                {
                    values[cur][2] -= cry;
                    if (values[cur][2] < 0)
                    {
                        values[cur][3] = 0;
                        if (cry <= 1e6)
                            cry += values[cur][1];
                    }
                }

            }
        }
    }
    cout << children.size() << endl;
    for (auto& a : children)
        cout << a+1 << " ";

}