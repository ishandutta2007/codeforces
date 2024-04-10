#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;



int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #ifdef _FILE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int n;
    cin >> n;
    int now = 1;
    int adding = 2;
    int ans = 0;
    while(n >= now) {
        n -= now;
        ++ans;
        now += adding;
        ++adding;
    }
    cout << ans;
}