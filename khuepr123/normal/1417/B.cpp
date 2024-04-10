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
int n, m, k; ll b[maxN], a[maxN]; bool chk[maxN]; bool flag;

void tcin(){ // typical cin
    cin >> n >> k;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
}
void tcin2(){
    cin >> n >> m;; for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    for(int i = 1; i <= m ;i++){
        cin >> b[i];
    }
}
void typre(){ // typical reset
    for(int i = 0; i <= n + 15; i++){
        chk[i] = 0;
    }
}


int main(){
    ios_base::sync_with_stdio(0);
    int o; cin >> o;
    while(o--){
        tcin(); flag = 0;
        for(int i = 1; i <= n; i++){
            if((a[i] * 2) < k){
                cout << "0 ";
            }
            if((a[i] * 2) > k){
                cout << "1 ";
            }
            if((a[i] * 2) == k){
                cout << flag << " ";
                flag = !flag;
            }
        }
        cout << "\n";
    }
}