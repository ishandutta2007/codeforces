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

void typre(){
    for(int i = 0; i <= n + 2; i++){
        chk[i] = 0;
    }
}


signed main(){
    ios_base::sync_with_stdio(0);
    int o; cin >> o;
    while(o--){
        cin >> n; int k; cin  >> k;
        for(int i = 1; i <= k; i++){
            cout << "a";
        }
        for(int i = k + 1; i <= n; i++){
            int xx = (i - k) % 3;
            if(xx == 1) cout << "b";
            if(xx == 2) cout << "c";
            if(xx == 0) cout << "a";
        }
        cout << endl;
    }
}