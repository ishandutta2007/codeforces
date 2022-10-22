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
int n, m, k, temp, temp1, temp2; int a[maxN]; int b[maxN]; bool chk[maxN];
char c[maxN];

void typre(){ // typical reset
    for(int i = 0; i <= n + 15; i++){
        chk[i] = 0;
    }
}

signed main(){
    ios_base::sync_with_stdio(0);
    int o; cin >> o;
    while(o--){
        string s; cin >> s;
        cout << s[0];
        for(int i = 1; i < s.size() - 1; i+=2){
            cout << s[i];
        }
        cout << s[s.size()-1] << "\n";
    }
}