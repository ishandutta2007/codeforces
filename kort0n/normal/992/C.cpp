#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <string>
#include <sstream>
#include <complex>
#include <vector>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
using namespace std;
typedef long long unsigned int ll;

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))

const long long p = 1000000007;

long long beki(long long a, long long b)
{
    if(b == 0){
        return 1;
    }
    long long ans = beki(a, b / 2);
    ans = ans * ans % p;
    if(b % 2 == 1){
        ans = ans * a;
        ans = ans % p;
    }
    return ans;
}

int main() {
    //cout.precision(10);
    long long n, k;
    cin >> n >> k;
    if(n == 0){
        cout << 0 << endl;
        return 0;
    }
    n = n % p;
    cout << (((n % p) * beki(2, k)) % p + (((n - 1 + p) % p) * beki(2, k)) % p + 1) % p << endl;
    return 0;
}