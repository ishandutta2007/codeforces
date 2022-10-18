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
    int n = readi();
    vector<int> l = readsi(n);
    l.push_back(l.back());

    int last = l[0];
    int start = 0;
    int end = 0;
    int max = 0;

    for (int i = 0; i < n + 1; i++)
    {
        if (last == l[i])
        {
            if (start < end)
            {
                //cout << "von " << start << " bis " << end <<  endl;
                int length = end - start;
                if (length/2 > max)
                    max = length/2;
                if (length % 2 == 0)
                {
                    FORR(j, start, end)
                        l[j] = l[start];
                }
                else
                {
                    FORR(j, start, start + (end - start)/2 + 1)
                        l[j] = l[start];
                    FORR(j, start + (end - start)/2 + 1, end)
                        l[j] = l[end];

                }
            }
            start = i;
            end = start;
        }
        else
        {
            last = l[i];
            end += 1;
        }
    }

    l.pop_back();
    cout << max << endl;
    for (int i : l)
        cout << i << " ";


}