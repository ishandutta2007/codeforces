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
const int maxN = 1005;
const ll oo = 1e18 + 7;
int n, a[maxN][maxN], m;
char c;
bool chk[maxN];
void typre(){
    for(int i = 0; i <= n + 3; i++){
        chk[i] = 0;
    }
}

void couter(int i, int j){
    for(int r = 1; r <= m; r++){
        if(r % 2) cout << i;
        else cout << j;
        cout << " ";
    }
}

void hugg(int i, int j, int k){
    cout << "YES\n";
    for(int r = 0; r <= m; r++){
        if(r % 3 == 0) cout << i << " ";
        if(r % 3 == 1) cout << j << " ";
        if(r % 3 == 2) cout << k << " ";
        
    }
    cout << endl;
}

void devour(int i, int j, int k){
    cout << "YES\n";
    m = m / 2;
    m--;
    if(m % 2){
        cout << i << " ";
        couter(k, i);
    }
    else{
        cout << k << " ";
        couter(i, k);
    }
    cout << j << " " << i << " ";
    couter(j, i);
    cout << endl;
}

bool lck;

signed main(){
    ios_base::sync_with_stdio(0);
    int o; cin >> o;
    while(o--){
        cin >> n >> m;
        lck = 0;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                cin >> c;
                if(c == '*') a[i][j] = 0;
                if(c == 'a') a[i][j] = 1;
                if(c == 'b') a[i][j] = 2;
            }
        }
        if(m % 2){
            cout << "YES\n";
            cout << 2 << " ";
            couter(1, 2); cout << endl; continue;
        }
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                if(i == j) continue;
                if(a[i][j] == a[j][i]){
                    cout << "YES\n" << j << " ";
                    couter(i, j); cout << endl;
                    lck = 1;
                    break;
                }
                
            }
            if(lck) break;
        }
        if(lck) continue;
        if(n == 2 && a[1][2] != a[2][1]){
            cout << "NO\n"; continue;
        }
        if(a[1][2] == a[2][3] && a[2][3] == a[3][1]) hugg(1, 2, 3);
        else if(a[1][2] == a[2][3]) devour(1, 2, 3);
        else if(a[2][3] == a[3][1]) devour(2, 3, 1);
        else if(a[3][1] == a[1][2]) devour(3, 1, 2);
        
    }
}