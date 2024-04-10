#include <iostream>
using namespace std;

int min(long long int a, long long int b, long long int c)
{
     int m = a;
     if (b < m) m = b;
     if (c < m) m = c;

     return m;
}

int main()
{
     int x, y, z, k, i;
     long long int a = 1, b = 1, c = 1;

     cin >> x >> y >> z >> k;

     for (i = 0; i < k; i++) {
      if (a == x && b == y && c == z) break;
      if (a == x && b == y) {
           c++;
      } else if (b == y && c == z) {
           a++;
      } else if (c == z && a == x) {
           b++;
      } else if (a == x) {
           if (b < c) {
            b++;
           } else {
            c++;
           }
      } else if (b == y) {
           if (a < c) {
            a++;
           } else {
            c++;
           }
      } else if (c == z) {
           if (a < b) {
            a++;
           } else {
            b++;
           }
      } else if (min(a, b, c) == a) {
           a++;
      } else if (min(a, b, c) == b) {
           b++;
      } else if (min(a, b, c) == c) {
           c++;
      }
     }
     
     cout << a * b * c << endl;

     return 0;
}