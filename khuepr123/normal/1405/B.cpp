#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define fi first
#define se second
#define fir fi.fi
#define sec fi.se
#define endl "\n"
#define PI 3.141592653589793238462643383279502884
const ll mod = 1000000007; ll fre; ll coin; int n; ll a[200005]; ll sum;

int main(){
    ios_base::sync_with_stdio(0);
    int o; cin >> o;
    while(o--){
        cin >> n; fre = 0; coin = 0;
        for(int i = 1; i <= n; i++){
            cin >> a[i]; if(!a[i]){
                n--; i--;
            }
        }
        for(int i = 1; i <= n; i++){
            if(a[i] > 0){
                fre += a[i]; a[i] = 0;
            }
            else{
                if((fre + a[i]) <= 0){
                    a[i] = fre + a[i]; fre = 0;
                }
                else{
                    fre = fre + a[i]; a[i] = 0;
                }
            }
        }
        sum = fre;
        for(int i = 1; i <= n; i++){
            sum = sum - a[i];
        }
        sum = sum / 2;
        cout << sum << "\n";
    }
}