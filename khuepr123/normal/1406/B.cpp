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
ll a[maxN];

int main(){
    ios_base::sync_with_stdio(0);
    int o; cin >> o;
    while(o--){
        int n; cin >> n;ll pro; ll temp;
        for(int i = 1; i <= n; i++){
            cin >> a[i];
        }
        sort(a + 1, a + n + 1);
        if(a[n] == 0){
            cout << 0 << "\n"; continue;
        }
        if(a[n] < 0){
            pro = a[n] * a[n - 1] * a[n - 2] * a[n - 3] * a[n - 4];
            cout << pro << "\n"; continue;
        }
        if(a[n] > 0){
            pro = 0 - oo;
            temp = 1;
            for(int i = n; i > n - 1; i--){
                temp = temp * a[i];
            }
            for(int i = 1; i < 5; i++){
                temp = temp * a[i];
            }
            if(temp > pro){
                pro = temp;
            }
            temp = 1;
            for(int i = n; i > n - 3; i--){
                temp = temp * a[i];
            }
            for(int i = 1; i < 3; i++){
                temp = temp * a[i];
            }
            if(temp > pro){
                pro = temp;
            }
            temp = 1;
            for(int i = n; i > n - 5; i--){
                temp = temp * a[i];
            }
            for(int i = 1; i < 1; i++){
                temp = temp * a[i];
            }
            if(temp > pro){
                pro = temp;
            }
            cout << pro << "\n"; continue;
        }
    }
}