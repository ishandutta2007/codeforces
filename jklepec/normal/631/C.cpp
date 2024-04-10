#include <bits/stdc++.h>
#define rep(i, a) for(int i = 0; i < a; ++i)
using namespace std;

const int MAXN = 2e5 + 5;

typedef long long ll;

multiset<int> pref;
multiset<int> nums;

int a[MAXN], sol[MAXN];
int tip[MAXN], b[MAXN];
int mx;

int main() {
   ios_base::sync_with_stdio(false);

   int n, m; cin >> n >> m;

   rep(i, n) {cin >> a[i]; nums.insert(a[i]);}

   rep(i, m) {
      cin >> tip[i] >> b[i];
      pref.insert(b[i]);
      --tip[i];
   }

   mx = *pref.rbegin();

   for(int i = mx; i < n; ++i) {sol[i] = a[i]; nums.erase(nums.lower_bound(a[i]));}

   int i = 0;

   while(pref.find(mx) != pref.end()) {
      pref.erase(pref.lower_bound(b[i]));
      i++;
   }

   int type = tip[i - 1];
   int last = mx;

   while(pref.size()) {
      mx = *pref.rbegin();
      while(last != mx) {
         last --;
         int er;
         if(type) {
            er = *nums.begin();
         }else {
            er = *nums.rbegin();
         }
         nums.erase(nums.lower_bound(er));
         sol[last] = er;
      }
      while(pref.find(mx) != pref.end()) {
         pref.erase(pref.lower_bound(b[i]));
         type = tip[i];
         i++;
      }
   }

   int j = 0;
   for(auto x : nums) {
      if(type)
         sol[last - j - 1] = x;
      else
         sol[j] = x;
      ++j;
   }

   rep(i, n)
      cout << sol[i] << " ";
}