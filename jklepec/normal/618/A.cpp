#include <set>
#include <map>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>

#define FOR(i, a, b) for(int i = a; i < b; ++i)
#define all(a) (a).begin(), (a).end()
#define gcd(a, b) __gcd(a, b)
#define _ << " " <<

using namespace std;

typedef long long int64;
typedef pair<int, int> point;

vector<int> v;

int main() {
   ios_base::sync_with_stdio(false); cin.tie(0);
   int n; cin >> n;
   for(int i = 0; i < n; ++i) {
      v.push_back(1);
      while(v.size() >= 2) {
         int x = v[v.size() - 1];
         int y = v[v.size() - 2];
         if(x != y)
            break;
         v.pop_back();
         v.pop_back();
         v.push_back(x + 1);
      }
   }
   for(int i = 0; i < v.size(); ++i)
      cout << v[i] << " ";
}