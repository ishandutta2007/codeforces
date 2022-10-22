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
const int maxN = 300005;
const ll oo = 1e18 + 7;
int n; int a[maxN]; bool chk[maxN];
int kzdf[maxN]; bool lockfirst;
int limnum;

void typre(){
    for(int i = 0; i <= n + 2; i++){
        chk[i] = 0;
    }
}


signed main(){
    ios_base::sync_with_stdio(0);
    int o; cin >> o;
    while(o--){
        cin >> n;
        for(int i = 1; i <= n; i++){
            cin >> a[i];
            kzdf[i] = a[i];
        }
        //if found a permutation then stating from it cout all of the remaining
        sort(kzdf + 1, kzdf + n + 1); lockfirst = 1;
        for(int i = 1; i <= n; i++){
            if(kzdf[i] - i){
                lockfirst = 0; cout << 0; break;
            }
        }
        if(lockfirst) cout << 1;
        // first permutation killed
        for(int i = 1; i < n; i++){
            a[i] = min(a[i], a[i + 1]);
        }
        n--;
        // start a new problem :D
        for(int i = 1; i <= n; i++){
            kzdf[i] = a[i];
        }
        sort(kzdf + 1, kzdf + n + 1); lockfirst = 1;
        // from 1 to n;
        // find maximum permutation
        kzdf[n + 1] = n + 2;
        
        for(int i = 1; i <= n + 1; i++){
            if(kzdf[i] - i){limnum = i - 1; break;}
        }
        for(int i = 0; i < n - limnum; i++) cout << 0;
        for(int i = 0; i < limnum; i++) cout << 1;
        cout << endl;
    }
}