#include<iostream>
#include<cstdio>
#include<vector>

using namespace std;

typedef long long llint;

llint a, b, sol;
llint x, y, z;

int main () {
    cin >> a >> b >> x >> y >> z;
    llint yell=x*2+y;
    llint blue=z*3+y;
    if (yell>a) sol+=yell-a;
    if (blue>b) sol+=blue-b;
    cout << sol;
    return 0;
}