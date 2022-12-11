#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define mp make_pair
#define pb push_back

using namespace std;

struct edge
{
    int i, j;
    int len;
    bool operator<(const edge& other)
    {
        return len > other.len;
    }
    edge() {}
    edge(int i, int j, int len) : i(i), j(j), len(len) {}
};

int dist2(int ax, int ay, int bx, int by)
{
    return (ax - bx) * (ax - bx) + (ay - by) * (ay - by);
}

int main()
{

    int n;
    cin >> n;
    vector<int> x(n), y(n);
    vector<edge> edges(n * (n - 1) / 2);
    for (int i = 0; i < n; ++i) {
        cin >> x[i] >> y[i];
    }
    
    int pos = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            edges[pos++] = {i, j, dist2(x[i], y[i], x[j], y[j])};
        }
    }
    
    sort(all(edges));
    
    vector<vector<unsigned int> > g(n, vector<unsigned int>((n + 31) / 32));
    
    for (edge& e : edges) {
        for (int k = 0; k < (n + 31) / 32; ++k) {
            if (g[e.i][k] & g[e.j][k]) {
                cout << fixed;
                cout.precision(12);
                //cout << e.i << " " << e.j << " " << k << "\n";
                cout << sqrt(e.len * 1.0) / 2 << "\n";
                return 0;
            }
        }
        g[e.i][e.j / 32] |= (1 << (e.j % 32));
        g[e.j][e.i / 32] |= (1 << (e.i % 32));
        //cout << e.i << " " << e.j << "\n";
    }

}