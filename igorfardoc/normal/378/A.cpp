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
    int a, b;
    cin >> a >> b;
    int fir = 0;
    int draw = 0;
    int sec = 0;
    for(int i = 1; i <= 6; i++) {
        int f = abs(i - a);
        int s = abs(i - b);
        if(f < s) {
            ++fir;
        } else if(s < f) {
            ++sec;
        } else {
            ++draw;
        }
    }
    cout << fir << ' ' << draw << ' ' << sec;
}