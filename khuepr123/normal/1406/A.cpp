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
int a[105]; int b[1005];

int main(){
    ios_base::sync_with_stdio(0);
    int o; cin >> o;
    while(o--){
        for(int i = 0; i <= 1002; i++){
            b[i] = 0;
        }
        int n; cin >> n; for(int i = 1; i <= n; i++){
            cin >> a[i];
            b[a[i]]++;
        }
        int g = 2; int sum = 0;
        for(int i = 0; i <= 1005; i++){
            if(b[i] == 0){
                break;
            }
            sum++; b[i]--;
        }
        for(int i = 0; i <= 1005; i++){
            if(b[i] == 0){
                break;
            }
            sum++; b[i]--;
        }
        cout<< sum<< "\n";
    }
}