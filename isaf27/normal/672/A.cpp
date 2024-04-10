#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <ctime>
#include <vector>
#include <queue>
#include <bitset>
#include <cmath>
#include <time.h>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <deque>
#include <iomanip>

using namespace std;

typedef long long ll;
typedef long double ld;
#define TIME clock() * 1.0 / CLOCKS_PER_SEC
#define fast_read cin.sync_with_stdio(0)
#define PREX(number) cout << fixed << setprecision(number)
const ld pi = 3.141592653589793238462643383279;
const ll INF = 1e18;
const int BIG = 1e9;
const int MAX_N = 100001;
const int km = (1 << 18) - 1;

string str(int n)
{
    if (n == 0)
        return "";
    return str(n / 10) + (char)('0' + n % 10);
}

int main()
{   /*
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);/**/
    string s = "";
    for (int i = 1; i <= 1000; i++)
        s += str(i);
    int n;
    cin >> n;
    n--;
    cout << s[n];
    return 0;
}