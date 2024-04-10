#include <map>
#include <set>
#include <vector>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long llint;
typedef pair<int, int> point;

int main() {
   int n; cin >> n;
   if(n % 5 > 0)
      cout << n / 5 + 1;
   else
      cout << n / 5;
   return 0;
}