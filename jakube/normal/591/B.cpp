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
    int m = readi();
    vector<char> name = reads<char>(n);
    //map<char, char> letters;
    vector<pair<char, char>> letters;
    string s = "abcdefghijklmnopqrstuvwxyz";
    for(char c : s) {
        //letters.insert(make_pair(c, c));
        letters.push_back(make_pair(c, c));
    }

    FOR(i, m){
        char a = read<char>();
        char b = read<char>();
        FOR(j, 26) {
            if (letters[j].second == a)
                letters[j].second = b;
            else if (letters[j].second == b)
                letters[j].second = a;
        }
    }

    for (char c : name)
    {
        cout << letters[(c - 'a')].second;
    }
}