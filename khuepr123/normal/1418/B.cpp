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
int n; int a[105]; bool chk[105]; int cnt; int b[105];
 
int main(){
    ios_base::sync_with_stdio(0);
    int o; cin >> o; int sum; int k;
    while(o--){
        cin >> n; sum = 0; k = 0;
        for(int i = 1; i <= n; i++){
            cin >> a[i];
        }
        for(int i = 1; i <= n; i++){
            cin >> chk[i];
            if(chk[i] == 0){
                cnt++; b[cnt] = a[i];
            }
        }
        sort(b + 1, b + cnt + 1);
        for(int i = 1; i <= n; i++){
            if(chk[i] == 0){
                a[i] = b[cnt]; cnt--;
            }
        }
        for(int i = 1; i <= n; i++){
            cout << a[i] << " ";
        }
        cout << "\n";
    }
}