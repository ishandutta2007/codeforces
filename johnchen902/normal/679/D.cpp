#include <cstdio>
#include <utility>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;
int adj[400];
int d[400][400];
double solve3(int, int c2, double *p, const vector<int> &v) {
    double r[400] = {}, sum = 0;
    for(int i : v)
        if(p[i] > r[d[c2][i]]) {
            sum += p[i] - r[d[c2][i]];
            r[d[c2][i]] = p[i];
        }
    return sum;
}
double solve2(int n, const vector<int>& e) {
    if(e.size() == 1) return 1.0;

    double p[400] = {};
    for(int i : e)
        for(int j = 0; j < n; j++) 
            if(d[i][j] == 1)
                p[j] += 1.0 / adj[i];
    vector<int> v;
    for(int i = 0; i < n; i++)
        if(p[i])
            v.push_back(i);
    double ans = 1.0;
    for(int i = 0; i < n; i++)
        ans = max(ans, solve3(n, i, p, v));
    return ans / e.size();
}
double solve(int n, int c1) {
    vector<int> e[400];
    for(int i = 0; i < n; i++)
        e[d[c1][i]].push_back(i);
    double ans = 0;
    for(int i = 0; i < n; i++)
        if(!e[i].empty())
            ans += solve2(n, e[i]) * e[i].size() / n;
    return ans;
}
int main(){
    int n, m;
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++)
        fill_n(d[i], n, 99999), d[i][i] = 0;
    for(int i = 0; i < m; i++) {
        int p, q;
        scanf("%d %d", &p, &q);
        p--, q--;
        adj[p]++, adj[q]++;
        d[p][q] = d[q][p] = 1;
    }
    for(int k = 0; k < n; k++)
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                if(d[i][j] > d[i][k] + d[k][j])
                    d[i][j] = d[i][k] + d[k][j];
    double ans = 0;
    for(int c1 = 0; c1 < n; c1++)
        ans = max(ans, solve(n, c1));
    printf("%.12f\n", ans);
}