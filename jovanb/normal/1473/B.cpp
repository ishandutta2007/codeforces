#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

#define pb push_back

string lcm(string a, string b){
    int n = a.size(), m = b.size();
    int len = n*m/(__gcd(n, m));
    string res = "";
    for(int i=0; i<len; i++){
        if(a[i%n] != b[i%m]) return "-1";
        res += a[i%n];
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0);
    cout.precision(10);
    cout << fixed;

    int t;
    cin >> t;
    while(t--){
        string a, b;
        cin >> a >> b;
        cout << lcm(a, b) << "\n";
    }
    return 0;
}