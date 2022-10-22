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
const int maxN = 1000005;
const ll oo = 1e18 + 7;
int l, r, k, h, x, pre[maxN][10], val[maxN];


int f(int i){
    h = 1;
    while(i){
        x = i % 10; i = i / 10;
        if(x) h *= x;
    }
    return h;
}

signed main(){
    ios_base::sync_with_stdio(0);
    for(int i = 0; i <= 9; i++){
        val[i] = i;
        pre[0][i] = 0;
    }
    for(int i = 10; i <= maxN; i++){
        val[i] = val[f(i)];
    }
    
    for(int i = 1; i <= maxN; i++){
        for(int j = 0; j <= 9; j++){
            pre[i][j] = pre[i - 1][j];
        }
        pre[i][val[i]]++;
    }
    int o; cin >> o;
    while(o--){
        cin >> l >> r >> k;
        cout << pre[r][k] - pre[l - 1][k] << endl;
    }
}