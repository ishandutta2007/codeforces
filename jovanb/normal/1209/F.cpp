#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int MOD = 1000000007;

int add(int a, int b){ a += b; if(a >= MOD) a -= MOD; return a; }
int mul(int a, int b){ return (1LL*a*b)%MOD; }

const int N = 1200000;

vector <pair <int, int>> graf[N+5];

int val[N+5];
int comp[N+5];
int dist[N+5];

int tjm;

void dodaj(int a, int b, int i){
    int x = i;
    int lst = b;
    while(x >= 10){
        tjm++;
        graf[tjm].push_back({lst, x%10});
        x /= 10;
        lst = tjm;
    }
    graf[a].push_back({lst, x});
}

vector <int> vec[N+5];

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0);
    cout.precision(10);
    cout << fixed;

    int n, m;
    cin >> n >> m;
    tjm = n;
    for(int i=1; i<=m; i++){
        int a, b;
        cin >> a >> b;
        dodaj(a, b, i);
        dodaj(b, a, i);
    }
    queue <int> q;
    q.push(1);
    while(!q.empty()){
        int v = q.front();
        q.pop();
        vec[dist[v]].push_back(v);
        for(auto pr : graf[v]){
            int c = pr.first;
            if(c != 1 && !dist[c]){
                dist[c] = dist[v] + 1;
                q.push(c);
            }
        }
    }
    for(int i=0; i<=N; i++){
        if(vec[i+1].empty()) break;
        vector <tuple <int, int, int, int>> vc;
        for(auto v : vec[i]){
            for(auto pr : graf[v]){
                int c = pr.first;
                int x = pr.second;
                if(dist[c] <= dist[v]) continue;
                vc.push_back({comp[v], x, c, add(mul(10, val[v]), x)});
            }
        }
        sort(vc.begin(), vc.end());
        reverse(vc.begin(), vc.end());
        int tgm = N;
        for(int j=0; j<vc.size(); j++){
            if(j == 0 || get<0>(vc[j]) != get<0>(vc[j-1]) || get<1>(vc[j]) != get<1>(vc[j-1])) tgm--;
            int v = get<2>(vc[j]);
            int nv = get<3>(vc[j]);
            comp[v] = tgm;
            val[v] = nv;
        }
    }
    for(int i=2; i<=n; i++) cout << val[i] << "\n";
    return 0;
}