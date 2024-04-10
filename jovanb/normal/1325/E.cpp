#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int N = 1000000;
const int M = 1000;
const int INF = 1000000000;

int a[N+5];
bool nprime[N+5];

vector <int> divs[N+5];
vector <int> graf[N+5];

map <int, int> edge[N+5];

int dist[N+5];
int od[N+5];

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0);
    cout.precision(10);
    cout << fixed;

    vector <int> primes, bprimes;
    for(int i=2; i<=N; i++){
        if(nprime[i]) continue;
        if(i <= M) primes.push_back(i);
        bprimes.push_back(i);
        for(int j=i; j<=N; j+=i){
            nprime[j] = 1;
            int x = j, t = 0;
            while(x%i == 0){
                x /= i;
                t++;
            }
            if(t%2) divs[j].push_back(i);
        }
    }
    bool ima2 = 0;
    int n;
    cin >> n;
    for(int i=1; i<=n; i++) cin >> a[i];
    for(int i=1; i<=n; i++){
        int x = a[i];
        if(divs[x].size() == 0){
            cout << "1\n";
            return 0;
        }
        else if(divs[x].size() == 1){
            int t = divs[x][0];
            edge[0][t]++;
            if(edge[0][t] + edge[t][0] == 1){
                graf[0].push_back(t);
                graf[t].push_back(0);
            }
            else{
                ima2 = 1;
            }
        }
        else{
            int t = divs[x][0];
            int g = divs[x][1];
            edge[t][g]++;
            if(edge[t][g] + edge[g][t] == 1){
                graf[t].push_back(g);
                graf[g].push_back(t);
            }
            else{
                ima2 = 1;
            }
        }
    }
    if(ima2){
        cout << "2\n";
        return 0;
    }
    primes.push_back(0);
    bprimes.push_back(0);
    int res = INF;
    for(auto root : primes){
        for(auto i : bprimes) dist[i] = INF, od[i] = -1;
        dist[root] = 0;
        queue <int> q;
        q.push(root);
        while(!q.empty()){
            int v = q.front();
            q.pop();
            for(auto c : graf[v]){
                if(od[v] == c) continue;
                if(dist[c] > dist[v] + 1){
                    dist[c] = dist[v] + 1;
                    od[c] = v;
                    q.push(c);
                }
                else res = min(res, dist[c] + dist[v] + 1);
            }
        }
    }
    if(res == INF) cout << "-1\n";
    else cout << res << "\n";
    return 0;
}