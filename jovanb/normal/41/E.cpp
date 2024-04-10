#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

vector <int> graf[105];
bool ima[105][105];
queue <pair <int, int>> q;

int main(){
    ios_base::sync_with_stdio(false);
    cout.precision(10);
    cout<<fixed;

    int n;
    cin >> n;
    for(int len=1; len<=n; len++){
        for(int i=1; i<=n; i++){
            if(i+len > n) break;
            int j = i+len;
            bool moze=1;
            for(auto c : graf[i]){
                if(ima[c][j]) {moze=0; break;}
            }
            if(moze){
                graf[i].push_back(j);
                graf[j].push_back(i);
                ima[i][j] = ima[j][i] = 1;
                q.push({i, j});
            }
        }
    }
    cout << q.size() << "\n";
    while(!q.empty()){
        cout << q.front().first << " " << q.front().second << "\n";
        q.pop();
    }
    return 0;
}