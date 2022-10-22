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
int n; int a[50004]; bool x;

int main(){
    ios_base::sync_with_stdio(0);
    int o; cin >> o;
    while(o--){
        cin >> n; x = 0; 
        for(int i = 1; i <= n; i++){
            cin >> a[i];
        }
        for(int i = 2; i <= n; i++){
            if(a[i] >= a[i - 1]){
                x = 1; break;
            }
        }
        if(x){
            cout << "YES";
        }
        else{
            cout << "NO";
        }
        cout << "\n";
    }
}