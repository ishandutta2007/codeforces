#include <cstdio>
#include <set>
#include <vector>
#include <cmath>
#define x first
#define y second

using namespace std;

int n, m;

set < pair < int, int > > S;
vector < pair < int, int > > v;

double dis(pair < int, int > a, pair < int, int > b){
       return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

int main(){
    scanf("%d%d", &n, &m);
    for (int i = 0; i < 3; ++i) for (int j = 0; j < 3; ++j){
        if (i <= n && j <= m) S.insert(make_pair(i, j));
        if (n - i >= 0 && j <= m) S.insert(make_pair(n - i, j));
        if (i <= n && m - j >= 0) S.insert(make_pair(i, m - j));
        if (n - i >= 0 && m - j >= 0) S.insert(make_pair(n - i, m - j));
    }
    for (set < pair < int, int > >::iterator it = S.begin(); it != S.end(); ++it) v.push_back(*it);
    vector < pair < int, int > > sol;
    double r = -1;
    for (int i = 0; i < v.size(); ++i)
    for (int j = 0; j < v.size(); ++j) if (i != j)
    for (int k = 0; k < v.size(); ++k) if (i != k && j != k)
    for (int l = 0; l < v.size(); ++l) if (i != l && j != l && k != l){
        double cr = dis(v[i], v[j]) + dis(v[j], v[k]) + dis(v[k], v[l]);
        if (cr > r){r = cr; sol.clear(); sol.push_back(v[i]); sol.push_back(v[j]); sol.push_back(v[k]); sol.push_back(v[l]);}
    }
    for (int i = 0; i < sol.size(); ++i){
        printf("%d %d\n", sol[i].x, sol[i].y);
    }
    return 0;
}