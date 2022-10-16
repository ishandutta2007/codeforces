#include <bits/stdc++.h>

#define dbg(x) cerr<<#x": "<<x<<endl
#define dbg_p(x) cerr<<#x": "<<x.first<<","<<x.second<<endl
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!"<<endl

#define st first
#define nd second

using namespace std;

int n, k;

template<class T>
ostream& operator<<(ostream& out, multiset<T> v) {
    out << v.size() << '\n';
    for(auto e : v) out << e << ' ';
    return out;
}

template<class T>
ostream& operator<<(ostream& out, vector<T> v) {
    out << v.size() << '\n';
    for(auto e : v) out << e << ' ';
    return out;
}

template<class T1, class T2>
ostream& operator<<(ostream& out, pair<T1, T2> p) {
    return out << '(' << p.st << ' ' << p.nd << ')';  
}

int ok[5][5], use[5];
multiset <int> v[5][5];

vector <int> cc;
void dfs(int node) {
    use[node] = 1;
    cc.push_back(node);
    for(int i = 1; i <= 4; i++)
        if(v[node][i].size() > 1 || (ok[node][i] && v[node][i].size() == 1))
            if(!use[i])
                dfs(i);
}


bool eulerian() {
    int ans = 0;
    if(cc.size() < 4)
        return true;
    for(auto i : cc) {
        int nr = 0;
        for(int j = 1; j <= 4; j++)
            if(i != j && v[i][j].size() > 0)
                nr += v[i][j].size() + (1 - ok[i][j]);
        ans += (nr % 2);
    }
    return (ans == 0) || (ans == 2);
}


int sum(multiset<int> &s) {
    int ans = 0;
    for(auto i : s)
        ans += i;
    return ans;
}

int val() {
    int ans = 0;
    for(auto i : cc) 
        for(int j = i; j <= 4; j++) {
            ans += sum(v[i][j]);
            if(!ok[i][j] && v[i][j].size() > 0 && i != j)
                ans -= *v[i][j].begin();
        }
    return ans;

}

int main() {
    ios_base::sync_with_stdio(false);
    int x,y,z, sum = 0;
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        cin>>x>>y>>z;
        sum += y;
        v[x][z].insert(y);
        if(z != x)
            v[z][x].insert(y);
    }
    vector <pair<int,int> > edges;
    
    for(int i = 1; i <= 4; i++)
        for(int j = i + 1; j <= 4; j++)
            edges.push_back({i, j});

    // dbg(edges);

    int ans = 0;
    for (int msk = 0; msk < (1<<edges.size()); msk++) {
        // dbg(msk);
        memset(ok, 0, sizeof ok);
        memset(use, 0, sizeof use);
        for(int i = 0; i < edges.size(); i++)
            if(msk & (1 << i))
                ok[edges[i].st][edges[i].nd] = ok[edges[i].nd][edges[i].st] = 1;
                // am muchia edges[i] luata din nou;
        for(int i = 1; i <= 4; i++) {
            if(use[i]) continue;
            cc.clear();
            dfs(i); // despart in componente conexe
            
            // dbg(cc);
            // pt fiecare c.c. vad daca e euleriana
            if(eulerian()) 
                ans = max(ans, val());
                // dbg(val());
            
                // daca este, updatez raspunsul
        }
    }

    // if(n == 56) {
    //     cout << sum << '\n';
    //     cout << edges << '\n';
    //     cout << (v[1][3]) << '\n';
    //     cout << (v[2][3]) << '\n';
    //     cout << (v[3][4]) << '\n';
    // }
    dbg(sum);
    cout << ans << '\n';
}