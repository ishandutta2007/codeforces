#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int MAXN = 505;
int odakle[MAXN+5];

int query(vector <int> x){
    cout << "? ";
    for(auto c : x) cout << c << " ";
    cout << endl;
    int g;
    cin >> g;
    return g;
}

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0);
    cout.precision(10);
    cout << fixed;

    int n, k;
    cin >> n >> k;
    queue <int> q;
    q.push(n);
    for(int i=0; i<=n; i++) odakle[i] = -1;
    odakle[n] = n;
    while(!q.empty()){
        int v = q.front();
        q.pop();
        for(int j=0; j<=k; j++){
            if(n-v < k-j || v < j) continue;
            if(odakle[(v-j) + (k-j)] == -1){
                odakle[v+k-2*j] = v;
                q.push(v+k-2*j);
            }
        }
    }
    if(odakle[0] == -1){
        cout << "-1\n";
        return 0;
    }
    set <int> van;
    set <int> u;
    int res = 0;
    for(int i=1; i<=n; i++) van.insert(i);
    int v = 0;
    while(v != n){
        int c = odakle[v];
        int x = (v+k-c)/2;
        vector <int> kveri;
        vector <int> p1, p2;
        for(int t=1; t<=x; t++){
            int g = *u.begin();
            kveri.push_back(g);
            p1.push_back(g);
            u.erase(u.begin());
        }
        for(int t=1; t<=k-x; t++){
            int g = *van.begin();
            kveri.push_back(g);
            p2.push_back(g);
            van.erase(van.begin());
        }
        for(auto t : p1) van.insert(t);
        for(auto t : p2) u.insert(t);
        res ^= query(kveri);
        v = c;
    }
    cout << "! " << res << endl;
    return 0;
}