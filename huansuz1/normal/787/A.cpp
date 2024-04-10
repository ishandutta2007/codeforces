 #include <algorithm>
 #include <iostream>
 #include <cstring>
 #include <cstdlib>
 #include <string>
 #include <cstdio>
 #include <cmath>
 #include <map>
 #include <queue>
 #define ll long long
 using namespace std;
 ll x , y , a , b , c , d , ans;

 int main () {
 cin >> a >> b >> c >> d;
 ans = 1000000000;
 if (d == b) { cout<< d; return 0; }
 x = b;
 y = d;
 if (x > d and x - d > c and (x - d) % c == 0) ans = min( x , ans);
 if (y > b and y - b > a and (y - b) % a == 0) ans = min( y , ans); 
 for (int i = 1; i<=c + a; i++)
 {
  x = x + a;
  y = y + c;
  if (x == d) ans = min( x , ans);
  if (y == b) ans = min( y , ans);  
  if (x > d and x - d >= c and (x - d) % c == 0) ans = min( x , ans); 
  if (y > b and y - b >= a and (y - b) % a == 0) ans = min( y , ans); 

 }
 if (ans == 1000000000)cout << -1; else cout<<ans;
 return 0;
 }