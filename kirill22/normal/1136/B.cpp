#include <bits/stdc++.h>
using namespace std;
#define ld long double
#define ll long long
int main() {
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);
   int n,k;
   cin >> n >> k;
   int x=max(0,min(k-1,n-k));
   int z=max(k-1,n-k);
   cout << 2*x+z+n+n+1;
}