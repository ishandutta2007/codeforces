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
char c; int od = 0;int ev = 0;
 
int n; int a[200005];
int main(){
    ios_base::sync_with_stdio(0);
    int o; cin >> o;
    while(o--){
        cin >> n;
        for(int i = 1; i <= n; i++){
            cin >> c; a[i] = c % 2;
        }
        for(int i = 1; i <= n; i+=2){
            if(a[i] == 1){
                od = 1; break;
            }
        }
        for(int i = 2; i <= n; i+=2){
            if(a[i] == 0){
                ev = 1; break;
            }
        }
        
        if(n % 2){
            if(od == 1){
                cout << 1;
            }
            else{
                cout << 2;
            }
        }
        else{
            if(ev == 1){
                cout << 2;
            }
            else{
                cout << 1;
            }
        }
        cout <<  "\n";
        od = 0; ev = 0;
    }
}