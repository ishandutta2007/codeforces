#include <iostream>
using namespace std;

int main() {
   int n, a, b;
   cin >> n >> a >> b;

   a = a + b - 1;
   a = ((a) % n + n) % n;

   cout << a + 1;

}