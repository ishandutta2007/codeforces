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
int n; int rate[1005]; int infected;
int cntfec; ll sum;

int main(){
    ios_base::sync_with_stdio(0);
    int o; cin >> o;
    while(o--){
        cin >> n >> infected; cntfec = 0; sum = 0;
        for(int i = 1; i <= n; i++){
            cin >> rate[i]; sum += rate[i];
            if(infected == rate[i]){
                cntfec++;
            }
        }
        if(cntfec == n){
            cout << 0;
        }
        else{
            if(sum == n * infected || cntfec > 0){
                cout << 1;
            }
            else{
                cout << 2;
            }
        }
        cout << "\n";
    }
} // what do the disease even do. useless disease