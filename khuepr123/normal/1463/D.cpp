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
int n; int a[maxN]; bool chk[maxN];
int x; int cnt;
int vc[maxN];
int miner;
int lim;
bool checker;
int o;
int xvert;


void typre(){
    for(int i = 1; i <= n * 2; i++){
        chk[i] = 0;
    }
}

void buff(){
        cnt = n; lim = n;
        vc[0] = 0;
        while(true){
            if(cnt == 0){
                lim++; break;
            }
            while(a[lim] < vc[cnt]) cnt--;
            
            if(cnt == 0){
                lim++; break;
            }
            lim--; cnt--;
            
        }
        if(lim == n + 1){
            cout << "1\n"; checker = 1; return;
        }
        miner += (n - lim + 1);
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin >> o;
    while(o--){
        cin >> n; checker = 0;
        typre();
        miner = 0 - n;
        for(int i = 1; i <= n; i++){
            cin >> a[i];
            chk[a[i]] = 1;
        }
        cnt = 0;
        for(int i = 1; i <= n * 2; i++){
            if(chk[i] == 0){
                cnt++; vc[cnt] = i;
            }
        }
        xvert = 1;
        buff();
        if(checker) continue;
        for(int i = 1; i <= n; i++){
            a[i]  = mod -  a[i];
            vc[i] = mod - vc[i];
        }
        reverse(a  + 1, a  + n + 1);
        reverse(vc + 1, vc + n + 1);
        xvert = -1;
        buff();
        if(checker) continue;
        cout << miner + 1 << endl;
    }
}