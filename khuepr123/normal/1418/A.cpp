#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define pb push_back
#define fi first
#define se second
#define fir fi.fi
#define sec fi.se
#define endl "\n"
#define PI 3.141592653589793238462643383279502884
const ll mod = 1e9 + 7;
const int maxN = 100005;
const ll oo = 1e18 + 7;
ll a, b, c, total, turn;
 
int main(){
    ios_base::sync_with_stdio(0);
    int o; cin >> o;
    while(o--){
        cin >> a >> b >> c; a = a - 1;
        total = (b + 1) * c - 1;
        if(total % a == 0){
            total = total / a;
        }
        else{
            total = total / a + 1;
        }
        turn = c + total;
        cout << turn << "\n";
    }
}