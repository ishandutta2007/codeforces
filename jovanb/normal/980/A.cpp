#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios_base::sync_with_stdio(false),cin.tie(0),cerr.tie(0),cout.tie(0);
    cout.precision(10);
    cout<<fixed;

    string s;
    cin >> s;
    int n = s.size();
    int x1=0, x2;
    for(int i=0; i<n; i++) if(s[i] == 'o') x1++;
    x2 = n-x1;
    if(x1 == 0) cout << "YES";
    else if(x2%(x1) == 0) cout << "YES";
    else cout << "NO";
    return 0;
}