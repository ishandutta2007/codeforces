// 479 A
#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

int main()
{
//    ios_base::sync_with_stdio(0);
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    int a,b,c;
    cin >> a >> b >> c;
    cout << max(max(max(a+b*c, a*b*c), max(a*(b+c), a+b+c)), max((a+b)*c, a*b+c));
    return 0;
}