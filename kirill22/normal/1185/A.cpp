#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
   vector<int> a(3);
   for(int i =0;i < 3;i++){
   	cin >> a[i];
   	
   }
   sort(a.begin(),a.end());
   int d;
   cin >> d;
   cout << max(0ll , d  - (a[1] - a[0])) + max(0ll, d- (a[2] - a[1]));
}