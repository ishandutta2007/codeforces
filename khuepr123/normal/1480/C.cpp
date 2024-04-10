#include<bits/stdc++.h>
using namespace std;
 
#define sadasdads long long
#define pb push_back
#define fi first
#define se second
#define fir fi.fi
#define sec fi.se
#define PI 3.141592653589793238462643383279502884
#define ll long long
const ll mod = 1e9 + 7;
const int maxN = 100005;
const ll oo = 1e18 + 7;
int n, a[maxN];
bool chk[maxN];
void typre(){
    for(int i = 0; i <= n + 3; i++){
        chk[i] = 0;
    }
}
 
int x, y;
 
signed main(){
    ios_base::sync_with_stdio(0);
    cin >> n;
    int l = 1; int r = n;
    while((r - l) > 10){
        int mid = (l + r) / 2;
        cout << "? " << mid << endl;
        cin >> x;
        cout << "? " << mid + 1 << endl;
        cin >> y;
        if(x > y) l = mid;
        else r = mid + 1;
    }
    int arr[maxN];
    for(int i = l; i <= r; i++){
        cout << "? " << i << endl;
        cin >> x;
        arr[i] = x;
    }
    for(int i = l + 1; i <= r - 1; i++){
        if(arr[i] < arr[i + 1] && arr[i] < arr[i - 1]){
            cout << "! " << i << endl;
            return 0;
        }
    }
    if(l == 1 && arr[1] < arr[2]) cout << "! " << 1 << endl;
    else if(r == n && arr[n] < arr[n - 1]) cout << "! " << n << endl;
    else if(l == 1 && r == 1) cout << "! " << 1 << endl;
}