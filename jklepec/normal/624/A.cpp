#include <set>
#include <map>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef pair<int, int> point;

#define gcd(a, b) __gcd(a, b)
#define all(a) (a).begin(), (a).end()
#define FOR(i, a, b) for(int i = a; i < b; ++i)

const int MAXN = 2e5 + 5;
typedef double lf;

int main() {
   ios_base::sync_with_stdio(false); cin.tie(0);
   lf d, l, v1, v2;
   cin >> d >> l >> v1 >> v2;
   l -= d;
   cout << fixed << (l) / (v1 + v2);
}