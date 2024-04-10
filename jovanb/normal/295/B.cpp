#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll dis[510][510];
ll ras[510][510];
stack <ll> resenja;
stack <ll> red;
bool bio[510];

int main(){
    ios_base::sync_with_stdio(false),cin.tie(0),cerr.tie(0),cout.tie(0);
    cout.precision(10);
    cout<<fixed;

    int n;
    cin >> n;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
                cin >> ras[i][j];
                dis[i][j] = ras[i][j];
        }
    }
    int x;
    for(int i=1; i<=n; i++){
        cin >> x;
        red.push(x);
    }
    while(!red.empty()){
        ll udis = 0;
        int r = red.top();
        // mozda ipak znam kolko ovo treba da ponovim lolz
        bio[r] = true;
        
            for(int i=1; i<=n; i++){
                for(int j=1; j<=n; j++){
                    if(dis[i][j] > dis[i][r]+dis[r][j]) dis[i][j] = dis[i][r]+dis[r][j];
                }
            }
        
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                if(!bio[i] || !bio[j]) continue;
                udis += dis[i][j];
            }
        }
        red.pop();
        resenja.push(udis);
    }
    while(!resenja.empty()){
        cout << resenja.top() << " ";
        resenja.pop();
    }
    return 0;
}