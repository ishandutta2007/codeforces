#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

vector <int> graf[100005];
int a[100005];
int b[100005];
int indeg[100005];

int main(){
    ios_base::sync_with_stdio(false);
    cout.precision(10);
    cout<<fixed;

    int n, m;
    cin >> n >> m;
    for(int i=1; i<=m; i++){
        cin >> a[i] >> b[i];
        graf[a[i]].push_back(b[i]);
        indeg[b[i]]++;
    }
    queue <int> q;
    for(int i=1; i<=n; i++){
        if(indeg[i] == 0) q.push(i);
    }
    int g = 0;
    while(!q.empty()){
        int v = q.front();
        g++;
        q.pop();
        for(auto c : graf[v]){
            indeg[c]--;
            if(!indeg[c]) q.push(c);
        }
    }
    if(g == n){
        cout << "1\n";
        for(int i=1; i<=m; i++) cout << "1 ";
        return 0;
    }
    cout << "2\n";
    for(int i=1; i<=m; i++){
        if(a[i] > b[i]) cout << "1 ";
        else cout << "2 ";
    }
    return 0;
}