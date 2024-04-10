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
#define tf3 ins(i, g, 0); ins(i + 1, g, 1); ins(i + 1, g + 1, 2);
#define tf2 ins(i + 1, g, 0); ins(i + 1, g + 1, 1); ins(i, g + 1, 2);
#define tf1 ins(i + 1, g + 1, 0); ins(i, g + 1, 1); ins(i, g, 2);
#define tf4 ins(i, g + 1, 0); ins(i, g, 1); ins(i + 1, g, 2);

int n, m; bool a[105][105]; char c;
vector<pair<int, int>> vp[5]; int j;

void ins(int i, int g, int pos){
    vp[pos].pb(pair<int, int>(i, g));
    a[i][g] = (!a[i][g]);
}



void exec(int i, int g){
    if(a[i][g] || a[i + 1][g] || a[i + 1][g + 1] || a[i][g + 1]){
        if(a[i][g] && a[i + 1][g] && a[i + 1][g + 1] && a[i][g + 1]){
            tf1
            tf2
            tf3
            tf4
            return;
        }
        if(a[i][g]){
            tf1
        }
        if(a[i + 1][g] && a[i + 1][g + 1] && a[i][g + 1]){
            tf2
            return;
        }
        if(a[i + 1][g] && a[i][g + 1]){
            tf1
            tf3
            return;
        }
        if(a[i + 1][g] && a[i + 1][g + 1]){
            tf1
            tf4
            return;
        }
        if(a[i + 1][g + 1] && a[i][g + 1]){
            tf3
            tf4
            return;
        }
        if(a[i][g + 1]){
            tf1
            tf2
            tf4
            return;
        }
        if(a[i + 1][g + 1]){
            tf1
            tf2
            tf3
            return;
        }
        if(a[i + 1][g]){
            tf2
            tf3
            tf4
            return;
        }
        
    }
}

signed main(){
    ios_base::sync_with_stdio(0);
    int o; cin >> o;
    while(o--){
        cin >> n >> m;
        vp[0].clear();
        vp[1].clear();
        bool choke = 0;;
        vp[2].clear();
        vp[3].clear();
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                cin >> c; if(c == 49) a[i][j] = 1;
                else a[i][j] = 0;
            }
        }
        for(int i = n - 1; i > 1; i--){
            for(j = 1; j < m; j++){
                ins(i, j, 0);
                ins(i, j + 1, 1);
                if(a[i + 1][j] == 1){
                    ins(i + 1, j, 2);
                }
                else{
                    ins(i + 1, j + 1, 2);
                }
                if(a[i + 1][j] == 1) cout << "BUG";
            }
            // i and m - 1
            if(a[i + 1][m - 1]){
                ins(i, m - 1, 0);
                ins(i, m, 1);
                ins(i + 1, m - 1, 2);
            }
            if(a[i + 1][m]){
                ins(i, m - 1, 0);
                ins(i, m, 1);
                ins(i + 1, m, 2);
            }
        }
        // only i = 1, 2 remain;
        // square i, i + 1 and j, j + 1;
        // consider i = 1 and j = m - 1;
        if(m % 2 == 1){
            if(a[1][m]){
                ins(1, m - 1, 0);
                ins(2, m - 1, 1);
                ins(1, m, 2);
                
            }
            if(a[2][m]){
                ins(1, m - 1, 0);
                ins(2, m - 1, 1);
                ins(2, m, 2);
            }
            m--; choke = 1;
        }
        for(int j = 1; j <= m; j += 2){
            exec(1, j);
        }
        if(choke) m++;
        cout << vp[0].size() << endl;
        for(int i = 0; i < vp[0].size(); i++){
            for(int k = 0; k < 3; k++){
                cout << vp[k][i].fi << " " << vp[k][i].se << " ";
            }
            cout << endl;
        }
    }
}