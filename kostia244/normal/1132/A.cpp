#include<bits/stdc++.h>
#define ll long long
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define __V vector
#define vi __V<ll>
#define pi pair<ll, ll>
using namespace std;

int a, b, c, d;

int main()
{
    cin >> a >> b >> c >> d;
    cout << (a == d && (a != 0 || c == 0));
    return 0;
}