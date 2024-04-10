#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

int deg[100005];
int niz[100005];
vector <pair <int, int>> graf[100005];
unordered_map <int, int> ind;
int res[100005];
int cnt;
bool visited[100005];

int n;

void toposort(){
    queue <int> q;
    for(int i=1; i<=n; i++){
        if(deg[i] == 1) q.push(i);
    }
    while(!q.empty()){
        int v = q.front();
        q.pop();
        if(visited[v]) continue;
        if(deg[v] == 0){cout << "NO"; exit(0);}
        cnt++;
        for(auto par : graf[v]){
            int c = par.first;
            if(visited[c]) continue;
            visited[c] = 1;
            visited[v] = 1;
            int x = par.second;
            res[v] = x;
            res[c] = x;
            if(c != v) cnt++;
            for(auto r : graf[v]){
                int rr = r.first;
                deg[rr]--;
                if(deg[rr] == 1) q.push(rr);
            }
            for(auto r : graf[c]){
                int rr = r.first;
                deg[rr]--;
                if(deg[rr] == 1) q.push(rr);
            }
            break;
        }
    }
    if(cnt < n){cout << "NO"; exit(0);}
}

int main(){
    ios_base::sync_with_stdio(false);
    cout.precision(10);
    cout<<fixed;

    int a, b;
    cin >> n >> a >> b;
    for(int i=1; i<=n; i++){
        cin >> niz[i];
        ind[niz[i]] = i;
    }
    if(a == b){
        for(int i=1; i<=n; i++){
            if(!ind[a-niz[i]]){cout << "NO"; return 0;}
        }
        cout << "YES\n";
        for(int i=1; i<=n; i++) cout << "1 ";
        return 0;
    }
    for(int i=1; i<=n; i++){
        if(ind[a-niz[i]]){
            deg[i]++;
            graf[i].push_back({ind[a-niz[i]], 1});
        }
        if(ind[b-niz[i]]){
            deg[i]++;
            graf[i].push_back({ind[b-niz[i]], 2});
        }
    }
    toposort();
    cout << "YES\n";
    for(int i=1; i<=n; i++) cout << res[i]-1 << " ";
    return 0;
}