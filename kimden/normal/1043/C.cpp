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
    string s;
    cin >> s;
    int n = s.length();
    for(int i = 0; i < n; ++i){
        if((i == n - 1 && s[i] == 'a') || (i != n - 1 && s[i] != s[i + 1])){
            cout << 1 << " ";
        }else{
            cout << 0 << " ";
        }
    }
    cout << endl;




}