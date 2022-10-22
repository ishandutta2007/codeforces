#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define fi first
#define se second
#define fir fi.fi
#define sec fi.se
#define endl "\n"
#define PI 3.141592653589793238462643383279502884
const ll mod = 1000000007; int a, b, c;

int main(){
    ios_base::sync_with_stdio(0);
    int o; cin >> o;
    while(o--){
        cin >> a >> b;
        c = abs(a - b) + 9; c = c / 10;
        cout << c << "\n";
    }
}