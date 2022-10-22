#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define fi first
#define se second
#define fir fi.fi
#define sec fi.se
#define endl "\n"
#define PI 3.141592653589793238462643383279502884
const ll mod = 1000000007; int n, k; string s; int inival; bool chk; bool x; int v; int cnt66, cnt6;

int main(){
    ios_base::sync_with_stdio(0);
    int o; cin >> o;
    while(o--){
        cin >> n >> k >> s; x = 0; v = k / 2; cnt66 = 0; cnt6 = 0;
        for(int i = 0; i < k; i++){
            chk = 0; 
            if(x == 1){
                break;
            }
            inival = 63;
            for(int j = i; j < n; j+=k){
                if(s[j] - 63){
                    if(!chk){
                        chk = 1; inival = s[j];
                    }
                    else{
                        if(inival - s[j]){
                            x = 1;
                        }
                    }
                }
            }
            for(int j = i; j < n; j+=k){
                s[j] = inival;
            }
        }
        for(int i = 0; i < k; i++){
            if(s[i] == 63){
                cnt6++;
            }
            if(s[i] == 49){
                cnt66++; // 1 count
                cnt6++; // 1 and ? count
            }
        }
        if(v < cnt66 || v > cnt6){
            x = 1;
        }
        if(x){
            cout << "NO";
        }
        else{
            cout << "YES";
        }
        cout << "\n";
    }
}