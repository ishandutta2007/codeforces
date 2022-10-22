#include<bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define fi first
#define se second
#define fir fi.fi
#define sec fi.se
#define endl "\n"
#define PI 3.141592653589793238462643383279502884
#define ll long long
const ll mod = 1e9 + 7;
const int maxN = 500005;
const ll oo = 1e18 + 7;
int n, a[maxN];
bool chk[maxN];
int arr[maxN];
int rail[maxN];
void typre(){
    for(int i = 0; i <= n + 3; i++){
        chk[i] = 0;
    }
}
bool lck;

signed main(){
    ios_base::sync_with_stdio(0);
    int o; cin >> o;
    while(o--){
        cin >> n; lck = 1;
        for(int i = 1; i <= n * 2; i++){
            cin >> a[i];
        }
        sort(a + 1, a + (n * 2 + 1));
        for(int i = 1; i <= n * 2; i+=2){
            if(a[i] != a[i + 1] || a[i] % 2 == 1) lck = 0;
            a[i] /= 2;
            arr[(i + 1) / 2] = a[i];
        }
        if(lck){}
        else{ cout << "NO\n"; continue;}
        lck = 1;
        if((arr[n] % n) != 0) lck = 0;
        rail[n] = arr[n] / n;
        for(int i = n - 1; i > 0; i--){
            if((arr[i + 1] - arr[i]) % i != 0) lck = 0;
            rail[i] = (arr[i + 1] - arr[i]) / i;
            rail[i] = rail[i + 1] - rail[i];
            if(rail[i] <= 0) lck = 0;
            if(rail[i] >= rail[i + 1]) lck = 0;
        }
        if(lck){ cout << "YES\n"; continue;}
        else   { cout <<  "NO\n"; continue;}
    }
}