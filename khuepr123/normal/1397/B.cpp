#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define fi first
#define se second
#define fir fi.fi
#define sec fi.se
const ll mod = 1000000007;
ll a[100005]; ll sum; ll por[37];
const ll mx = 10e9 * 40;

int main(){
    ios_base::sync_with_stdio(0);
    int n; cin >> n; sum = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    sort(a, a + n);
    if(n > 39){
        
        for(int i = 0; i < n; i++){
            sum = sum + a[i] - 1;
        }
        cout << sum; return 0;
    }
    for(int i = 0; i < n; i++){
        sum = sum + a[i] - 1;
    }
    ll c = 1; ll fin = sum;
    while(true){
        c++; sum = 0;
        por[0] = 1;
        for(int i = 1; i < n; i++){
            por[i] = por[i - 1] * c;
        }
        for(int i = 0; i < n; i++){
            sum = sum + abs(a[i] - por[i]);
        }
        if(sum < fin){
            fin = sum;
        }
        if(sum >= mx){
            break;
        }
    }
    cout << fin;
}