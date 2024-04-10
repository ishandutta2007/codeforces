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
int n; char c[305][305]; 

void maker(int rem){
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if((i + j) % 3 == rem){
                if(c[i][j] == 'X') cout << 'O';
                else cout << '.';
            }
            else cout << c[i][j];
            }
        cout << endl;
    }
}

int counter(int rem){
    int cnter = 0;;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if((i + j) % 3 == rem){
                if(c[i][j] == 'X') cnter++;
            }
        }
    }
    return cnter;
}

signed main(){
    ios_base::sync_with_stdio(0);
    int o; cin >> o;
    while(o--){
        cin >> n;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++) cin >> c[i][j];
        }
        
        if(counter(0) <= counter(1) && counter(0) <= counter(2)) maker(0);
        else if(counter(1) <= counter(2)) maker(1);
        else maker(2);
        //cout << counter(0) << " " << counter(1) << " " << counter(2) << "\n";
    }
}