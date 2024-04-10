#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <cstring>
#include <cstdio>
#include <cassert>
#include <queue>
#include <bitset>
#include <cmath>
#include <sstream>
#include <string>
#include <vector>

#define mp make_pair
#define pb push_back
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),(v).end()

using namespace std;

typedef pair<int, int> ii;
typedef long long int64;
typedef vector<int> vi;

template<class T> T abs(T x) {return x > 0 ? x : (-x); }
template<class T> T sqr(T x) {return x * x; }

const char names[100][100] = { "Sheldon", "Leonard", "Penny", "Rajesh", "Howard" };

int main()
{
    int64 n;
    cin >> n;
    --n;
    while (n >= 5) {
        n -= 5;
        n /= 2;
    }

    cout << names[n] << "\n";
    return 0;
}