#include <bits/stdc++.h>
using namespace std;

int n;

const int INF = 1005;

int cap[205][205];
int pcap[205][205];
int par[205];
int a[205];
int b[205];

int treba[205][205];

int flow(){
    for(int i=1; i<=2*n+1; i++) par[i] = -1;
    queue <pair <int, int>> q;
    q.push({INF, 0});
    par[0] = 0;
    while(!q.empty()){
        int v = q.front().second;
        int cflow = q.front().first;
        q.pop();
        for(int i=0; i<=2*n+1; i++){
            if(cap[v][i] && par[i] == -1){
                int nflow = cflow;
                par[i] = v;
                nflow = min(nflow, cap[v][i]);
                if(i == 2*n+1) return nflow;
                q.push({nflow, i});
            }
        }
    }
    return 0;
}

int maxflow(){
    int sum = 0;
    int new_flow;
    while((new_flow = flow())){
        sum += new_flow;
        //cout << "Naso " << new_flow << "\n";
        int v = 2*n+1;
        while(v){
            //cout << v << " ";
            cap[par[v]][v] -= new_flow;
            cap[v][par[v]] += new_flow;
            v = par[v];
        }
        //cout << "\n";
    }
    return sum;
}

int main(){

    int m;
    cin >> n >> m;
    int sum = 0;
    for(int i=1; i<=n; i++){
        cin >> a[i];
        sum += a[i];
        cap[0][i] = a[i];
        pcap[i][n+i] = cap[i][n+i] = INF;
    }
    for(int i=1; i<=n; i++){
        cin >> b[i];
        sum -= b[i];
        cap[n+i][2*n+1] = b[i];
    }
    if(sum){
        cout << "NO";
        return 0;
    }
    for(int i=1; i<=n; i++) sum += a[i];
    for(int i=1; i<=m; i++){
        int a, b;
        cin >> a >> b;
        cap[a][n+b] = pcap[a][n+b] = INF;
        cap[b][n+a] = pcap[b][n+a] = INF;
    }
    int r = maxflow();
    if(r != sum){
        cout << "NO";
        return 0;
    }
    cout << "YES\n";
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cout << pcap[i][n+j] - cap[i][n+j] << " ";
        }
        cout << "\n";
    }
    return 0;
}