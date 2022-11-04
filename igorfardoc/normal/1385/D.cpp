#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
string s;

int rec(int l, int r, char c) {
    if(l == r) {
        return s[l] != c;
    }
    int mid = (l + r) / 2;
    int am = 0;
    for(int i = l; i <= mid; i++) {
        am += (s[i] != c);
    }
    am += rec(mid + 1, r, c + 1);
    int res = am;
    am = 0;
    for(int i = mid + 1; i <= r; i++) {
        am += (s[i] != c);
    }
    am += rec(l, mid, c + 1);
    return min(am, res);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #ifdef _FILE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        cin >> s;
        cout << rec(0, n - 1, 'a') << '\n';
    }
}