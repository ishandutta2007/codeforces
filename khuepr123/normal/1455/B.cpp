#include<bits/stdc++.h>
using namespace std;

#define sadasdads long long
#define pb push_back
#define fi first
#define se second
#define fir fi.fi
#define sec fi.se
#define endl "\n"
#define PI 3.141592653589793238462643383279502884
#define ll long long
const ll mod = 1e9 + 7;
const int maxN = 100005;
const ll oo = 1e18 + 7;
int n; int a[maxN]; bool chk[maxN];
int x;

void typre(){
    for(int i = 0; i <= n + 2; i++){
        chk[i] = 0;
    }
}
int arr[100];
int aa, bb;

signed main(){
    ios_base::sync_with_stdio(0);
    arr[1] = 1;
    arr[2] = 3;
    arr[3] = 2;
    arr[4] = 3;
    arr[5] = 4;
    int o; cin >> o;
    while(o--){
        cin >> n;
        if(n < 0){
            cout << arr[n] << endl;
        }
        else{
            x = sqrt(n * 8);
            x = x / 2 - 1;
            
            while(!(x * (x + 1) / 2 < n && (x + 1) * (x + 2) / 2 >= n)) x++;
            aa = x * (x + 1) / 2;
            bb = (x + 1) * (x + 2) / 2;
            if(bb == n) cout << x + 1 << endl;
            else if(bb - n == 1) cout << x + 2 << endl;
            else if(bb - n <= n + 1) cout << x + 1 << endl;
            else cout << x + 2 << endl;
        }
    }
}