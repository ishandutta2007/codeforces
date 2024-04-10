#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

int mora[100005];
bool sme[100005][5];
vector <int> graf[100005];
int sz[5];
int tr[5];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(10);
    cout << fixed;

    int n, m;
    cin >> n >> m;
    for(int i=1; i<=m; i++){
        int a, b;
        cin >> a >> b;
        graf[a].push_back(b);
        graf[b].push_back(a);
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=3; j++){
            sme[i][j] = 1;
        }
    }
    mora[1] = 1;
    for(auto c : graf[1]) sme[c][1] = 0;
    for(int i=1; i<=n; i++){
        if(sme[i][1]) mora[i] = 1;
    }
    for(int i=1; i<=n; i++){
        if(mora[i] == 1){
            for(auto c : graf[i]) sme[c][1] = 0;
        }
    }
    for(int i=1; i<=n; i++){
        if(mora[i] == 1 && !sme[i][1]){
            cout << -1;
            return 0;
        }
    }
    int prvi = 0;
    for(int i=2; i<=n; i++){
        if(!mora[i]){
            prvi = i;
            break;
        }
    }
    if(!prvi){
        cout << -1;
        return 0;
    }
    mora[prvi] = 2;
    for(auto c : graf[prvi]) sme[c][2] = 0;
    for(int i=1; i<=n; i++){
        if(sme[i][2]) mora[i] = 2;
    }
    for(int i=1; i<=n; i++){
        if(mora[i] == 2){
            for(auto c : graf[i]) sme[c][2] = 0;
        }
    }
    for(int i=1; i<=n; i++){
        if(mora[i] == 2 && !sme[i][2]){
            cout << -1;
            return 0;
        }
    }
    prvi = 0;
    for(int i=2; i<=n; i++){
        if(!mora[i]){
            prvi = i;
            break;
        }
    }
    if(!prvi){
        cout << -1;
        return 0;
    }
    mora[prvi] = 3;
    for(auto c : graf[prvi]) sme[c][3] = 0;
    for(int i=1; i<=n; i++){
        if(sme[i][3]) mora[i] = 3;
    }
    for(int i=1; i<=n; i++){
        if(mora[i] == 3){
            for(auto c : graf[i]) sme[c][3] = 0;
        }
    }
    for(int i=1; i<=n; i++){
        if(mora[i] == 3 && !sme[i][3]){
            cout << -1;
            return 0;
        }
    }
    for(int i=1; i<=n; i++){
        sz[mora[i]]++;
    }
    for(int i=1; i<=n; i++){
        if(!mora[i]){
            cout << -1;
            return 0;
        }
        tr[1] = tr[2] = tr[3] = 0;
        for(auto c : graf[i]){
            tr[mora[c]]++;
        }
        if(mora[i] == 1){
            if(tr[2] != sz[2] || tr[3] != sz[3] || tr[1]){
                cout << -1;
                return 0;
            }
        }
        if(mora[i] == 2){
            if(tr[1] != sz[1] || tr[3] != sz[3] || tr[2]){
                cout << -1;
                return 0;
            }
        }
        if(mora[i] == 3){
            if(tr[2] != sz[2] || tr[1] != sz[1] || tr[3]){
                cout << -1;
                return 0;
            }
        }
    }
    for(int i=1; i<=n; i++){
        cout << mora[i] << " ";
    }
    return 0;
}