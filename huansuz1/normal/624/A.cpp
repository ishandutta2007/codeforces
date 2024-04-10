#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <cstring>
#include <cstdio>
#include <map>
#include <stack>
#include <queue>
#include <algorithm>

using namespace std;

double v1, v2, L, d;
int main () {
    cin >> d >> L >> v1 >> v2;
    printf("%.10lf", (L - d) / (v1+v2));
    return 0;
}