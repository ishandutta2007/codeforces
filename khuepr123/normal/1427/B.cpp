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
const int maxN = 1000005;
const ll oo = 1e18 + 7;
int n, m, k, temp, temp1, temp2; int a[maxN]; int b[maxN]; bool chk[maxN]; int coin; char c;
int tempcnt, str, cnt, arr[maxN];
int mark1, mark2;
 // 87 - 0 won; 76 - 1 lose
void typre(){ // typical reset
    for(int i = 0; i <= n + 2; i++){
        chk[i] = 0;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    int o; cin >> o;
    while(o--){
        typre(); coin = 0; tempcnt = 0; mark1 = 0; c = 0; mark2 = 0; cnt = 0; temp = 0; k = 0; n = 0;
        cin >> n >> k; chk[n + 1] = 1; for(int i = 1; i <= n; i++){
            cin >> c; if(c - 87){chk[i] = 1; tempcnt++;}
        }
        k = min(k, tempcnt);
        chk[0] = 1;
        for(int i = 1; i <= n; i++){
            if(!chk[i]){
                mark1 = i; break;
            }
        }
        if(mark1 == 0){
            if(k == 0){
                cout << "0\n";
            }
            else{
                k = k * 2 - 1; cout << k << "\n";
            }
            continue;
        }
        for(int i = n; i > 0; i--){
            if(!chk[i]){
                mark2 = i; break;
            }
        }
        for(int i = mark1; i <= mark2; i++){
            if(chk[i] == 0 && chk[i - 1] == 1){
                coin--;
            }
            if(chk[i] == 0){
                coin += 2;
            }
        }
        str = 0; cnt = 0;
        for(int i = mark1; i <= mark2; i++){
            if(chk[i]){
                str++;
            }
            else{
                if(chk[i - 1]){
                    cnt++; arr[cnt] = str; str = 0; 
                }
            }
        }
        sort(arr + 1, arr + cnt + 1);
        coin += (k * 2);
        for(int i = 1; i <= cnt; i++){
            if(k >= arr[i]){
                coin++; k -= arr[i];
            }
        }
        coin--; cout << coin << "\n";
    }
}