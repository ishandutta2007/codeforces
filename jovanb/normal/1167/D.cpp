#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

int main(){
    ios_base::sync_with_stdio(false);
    cout.precision(10);
    cout<<fixed;

    int n;
    cin >> n;
    string s;
    cin >> s;
    int b = 0;
    for(int i=0; i<n; i++){
        if(s[i] == ')') b--;
        cout << b%2;
        if(s[i] == '(') b++;
    }
    return 0;
}