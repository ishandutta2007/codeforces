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
int n; int a[maxN]; int b[maxN]; int c[maxN]; int temp, temp2;

void tcin(){ // typical cin
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    for(int i = 1; i <= n; i++){
        cin >> b[i];
    }
    for(int i = 1; i <= n; i++){
        cin >> c[i];
    }
    
}

int main(){
    ios_base::sync_with_stdio(0);
    int o; cin >> o;
    while(o--){
        tcin();
        temp = a[1];
        if(a[2] != temp){
            temp2 = a[2];
        }
        if(b[2] != temp){
            temp2 = b[2];
        }
        if(c[2] != temp){
            temp2 = c[2];
        }
        cout << temp << " " << temp2 << " ";
        for(int i = 3; i <= n; i++){
            if(a[i] != temp && a[i] != temp2){
                temp2 = a[i];
            }
            else if(b[i] != temp && b[i] != temp2){
                temp2 = b[i];
            }
            else if(c[i] != temp && c[i] != temp2){
                temp2 = c[i];
            }
            cout << temp2 << " ";
        }
        cout << "\n";
    }
}