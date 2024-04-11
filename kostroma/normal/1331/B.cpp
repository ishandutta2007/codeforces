#include<iostream>
using namespace std;
int main() {
int a;
cin >> a;
for (int x = 2; x < a; ++x) {
if (a % x == 0) {
int p = a / x;
bool f = true;
for (int j = 2; j < p; ++j) {
if (p % j == 0) {
f = false;
break;
}
}
if (f) {
cout << x << p << endl;
return 0;
}
}
}
return 0;
}