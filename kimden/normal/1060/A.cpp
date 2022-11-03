#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;


int main()
{
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    string s;
    cin >> s;
    int x = 0;
    for(int i = 0; i < n; ++i){
        if(s[i] == '8'){
            ++x;
        }
    }
    cout << min(x, n / 11) << endl;



    return 0;
}