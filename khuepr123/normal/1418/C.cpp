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
const int maxN = 200005;
const ll oo = 1e18 + 7;
int n; bool a[maxN]; int dpfriend[maxN]; int dpme[maxN]; int temp1;
// dp friend show least skip if friend end at i
int main(){
    ios_base::sync_with_stdio(0);
    int o; cin >> o;
    while(o--){
        int n; cin >> n;
        for(int i = 1; i <= n; i++){
            cin >> a[i];
        }
        if(n < 4){ // obvious
            cout << a[1] << "\n"; continue;
        }
        dpfriend[1] = a[1];
        dpme[1] = n + 100;
        dpfriend[2] = a[1] + a[2];
        dpme[2] = a[1];
        for(int i = 3; i <= n; i++){
            dpme[i] = min(dpfriend[i - 1], dpfriend[i - 2]);
            dpfriend[i] = min(dpme[i - 1] + a[i], dpme[i - 2] + a[i] + a[i - 1]);
        }
        temp1 = min(dpme[n], dpfriend[n]); cout << temp1 << "\n";
    }
}