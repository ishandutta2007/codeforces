#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

int mat[3005][3005];
int desno[3005][3005];

int main(){
    ios_base::sync_with_stdio(false);
    cout.precision(10);
    cout<<fixed;

    int n, m, a, b;
    cin >> n >> m >> a >> b;
    int x, y, z;
    ll g;
    cin >> g >> x >> y >> z;
    int i1 = 1, j1 = 1;
    while(i1 <= n){
        mat[i1][j1] = g;
        g = (g*x+y)%z;
        j1++;
        if(j1 > m){
            j1 = 1;
            i1++;
        }
    }
    for(int i=1; i<=n; i++){
        deque <pair <int, int>> q;
        for(int j=1; j<=b; j++){
            while(!q.empty()){
                if(q.back().first >= mat[i][j]) q.pop_back();
                else break;
            }
            q.push_back({mat[i][j], j});
        }
        desno[i][1] = q.front().first;
        for(int l=2; l+b-1<=m; l++){
            while(!q.empty() && q.front().second < l) q.pop_front();
            while(!q.empty()){
                if(q.back().first >= mat[i][l+b-1]) q.pop_back();
                else break;
            }
            q.push_back({mat[i][l+b-1], l+b-1});
            desno[i][l] = q.front().first;
        }
    }
    ll sum = 0;
    for(int j=1; j+b-1<=m; j++){
        deque <pair <int, int>> q;
        for(int i=1; i<=a; i++){
            while(!q.empty()){
                if(q.back().first >= desno[i][j]) q.pop_back();
                else break;
            }
            q.push_back({desno[i][j], i});
        }
        sum += q.front().first;
        for(int l=2; l+a-1<=n; l++){
            while(!q.empty() && q.front().second < l) q.pop_front();
            while(!q.empty()){
                if(q.back().first >= desno[l+a-1][j]) q.pop_back();
                else break;
            }
            q.push_back({desno[l+a-1][j], l+a-1});
            sum += q.front().first;
        }
    }
    cout << sum;
    return 0;
}