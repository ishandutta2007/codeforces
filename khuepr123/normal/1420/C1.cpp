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
int n; ll a[300005]; bool flag; int start = 1; ll sum; int z;

int main(){
    ios_base::sync_with_stdio(0);
    int o; cin >> o;
    while(o--){
        cin >> n >> z; flag = 1; // 0 mean down; 1 mean up
        sum = 0;
        for(int i = 1; i <= n; i++){
            cin >> a[i];
        }
        a[n + 1] = 0;
        for(int i = 1; i <= n; i++){
            if(flag){
                if(a[i] > a[i - 1] && a[i] > a[i + 1]){
                    sum = sum + a[i]; flag = 0;
                }
            }
            else{
                if(a[i] < a[i - 1] && a[i] < a[i + 1]){
                    sum = sum - a[i]; flag = 1;
                }
            }
        }
        cout << sum << '\n';
    }
}