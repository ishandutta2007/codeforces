#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector <int> graf[5000];
bool ima[5000][5000];

int main(){
    ios_base::sync_with_stdio(false),cin.tie(0),cerr.tie(0),cout.tie(0);
    cout.precision(10);
    cout<<fixed;

    int n, m, x, y;
    cin >> n >> m;
    while(m--){
        cin >> x >> y;
        graf[x].push_back(y);
        ima[x][y] = 1;
    }
    ll br=0;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(i != j){
                ll nesto=0;
                for(auto c : graf[i]){
                    if(ima[c][j]) nesto++;
                }
                br += (nesto*(nesto-1))/2;
            }

        }
    }
    cout << br;
    return 0;
}