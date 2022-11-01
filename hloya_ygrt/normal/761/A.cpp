#include <iostream>
#include <fstream>
#include <list>
#include <stack>
#include <deque>
#include <utility>
#include <queue>
#include <set>
#include <map>
#include <bitset>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
#include <iomanip>
#include <ctime>
#include <iterator>
#include <cstdio>
#include <cstring>
#include <cstdlib>
 
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
 
#define f first
#define s second
#define pb push_back
#define mp make_pair
 
const int maxn = 1e5 + 5;
const int inf = 2e9;
const double eps = 1e-8;
const int base = 1073676287;
 
int main() {
    // freopen("input.txt", "r", stdin);
    int a, b;
    cin >> a >> b;
    if ((a + b != 0) && (a - b == -1 || a - b == 0 || a - b == 1))
        cout << "YES";
    else  
        cout << "NO";
    return 0;
}