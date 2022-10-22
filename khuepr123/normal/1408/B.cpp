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
int n, m, k; ll b[maxN], a[maxN]; bool chk[maxN]; int cnt;

void tcin(){ // typical cin
    cin >> n >> k;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
}
void typre(){ // typical reset
    for(int i = 0; i <= 102; i++){
        chk[i] = 0;
    }
}


int main(){
    ios_base::sync_with_stdio(0);
    int o; cin >> o;
    while(o--){
        tcin(); typre(); cnt = 0;
        for(int i = 1; i <= n; i++){
            if(chk[a[i]] == 0){
                chk[a[i]] = 1; cnt++;
            }
        }
        if(cnt == 1){cout << "1\n"; continue;}
        k--;cnt--; cnt = cnt + k - 1;
        if(k == 0){cout << "-1\n"; continue;}
        cnt = cnt / k; cout << cnt << '\n';
    }
}