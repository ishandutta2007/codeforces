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
int a[3];

int main(){
    ios_base::sync_with_stdio(0);
    int o; cin >> o;
    while(o--){
        cin >> a[0] >> a[1] >> a[2];
        sort(a,a + 3);
        if(a[1] != a[2]){
            cout << "NO";
        }
        else{
            cout << "YES" << "\n";
            cout << a[1] << " " << a[0] << " " << a[0];
        }
        cout << "\n";
    }
}