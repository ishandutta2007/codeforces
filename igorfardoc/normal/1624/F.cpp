#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

int q(int a) {
    cout << "+ " << a << endl;
    int res;
    cin >> res;
    return res;
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
    int n;
    cin >> n;
    int l = 1;
    int r = n;
    int adding = 0;
    while(r - l > 1) {
        int mid = (l + r) / 2;
        int here = mid + adding;
        int upper = (here / n + 1) * n;
        int rs = q(upper - here);
        adding += upper - here;
        if(rs == upper / n) {
            l = mid;
        } else {
            r = mid;
        }
    }
    cout << "! " << l + adding << endl;
}