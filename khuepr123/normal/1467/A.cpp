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
int n, a[maxN];
bool chk[maxN];
void typre(){
    for(int i = 0; i <= n + 3; i++){
        chk[i] = 0;
    }
}

signed main(){
    ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while(t--){
        cin >> n;
        if(n == 1){
            cout << "9\n"; continue;
        }
        if(n == 2){
            cout << "98\n"; continue;
        }
        cout << 98;
        n -= 2;
        int guide = 9;
        while(n--){
            cout << guide;
            guide++;
            if(guide > 9) guide -= 10;
            
        } cout << endl;
    }
}