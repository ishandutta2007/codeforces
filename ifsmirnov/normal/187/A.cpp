#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <string>
using namespace std;
#define forn(i, n) for (int i = 0; i < (int)(n); i++)
const int maxn = 200500;

int n, a[maxn], b[maxn];
int pb[maxn];

int main()
{
    scanf("%d", &n);
    forn(i, n) scanf("%d", &a[i]), --a[i];
    forn(i, n) scanf("%d", &b[i]), --b[i];
    forn(i, n) pb[b[i]] = i;
    forn(i, n-1) if (pb[a[i]] > pb[a[i+1]]) {cout << n-i-1 << endl;return 0;}
    cout << 0 << endl;
    
    return 0;
}