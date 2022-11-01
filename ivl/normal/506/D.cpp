#include <cstdio>
#include <vector>
#include <map>
#include <algorithm>
#define x first
#define y second

using namespace std;

int gr[100005];
int un(int a){if (gr[a] == a) return a; return gr[a] = un(gr[a]);}
void join(int a, int b){gr[un(a)] = un(b);}
void reset(int a){gr[a] = a;}

int n, m;
vector < pair < int, int > > V[100005];
int q;
vector < pair < int, int > > uv;
map < pair < int, int >, int > muv;

int out[100005];

int main(){
    for (int i = 0; i <= 100003; ++i) reset(i);
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; ++i){
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        V[c].push_back(make_pair(a, b));
    }
    scanf("%d", &q);
    for (int i = 0; i < q; ++i){
        int u, v;
        scanf("%d%d", &u, &v);
        if (u > v) swap(u, v);
        uv.push_back(make_pair(u, v));
        muv[make_pair(u, v)] = i;
    }
    for (int i = 1; i <= m; ++i){
        for (int j = 0; j < V[i].size(); ++j) join(V[i][j].x, V[i][j].y);
        if (V[i].size() > 300){
           for (int j = 0; j < uv.size(); ++j) if (un(uv[j].x) == un(uv[j].y)) ++out[j];
        }
        else {
             static vector < int > bit;
             static bool bio[100005];
             for (int j = 0; j < V[i].size(); ++j){
                 if (!bio[V[i][j].x]++) bit.push_back(V[i][j].x);
                 if (!bio[V[i][j].y]++) bit.push_back(V[i][j].y);
             }
             for (int j = 0; j < bit.size(); ++j) for (int k = 0; k < bit.size(); ++k) if (un(bit[j]) == un(bit[k]) && muv.count(make_pair(bit[j], bit[k]))) ++out[muv[make_pair(bit[j], bit[k])]];
             for (int j = 0; j < bit.size(); ++j) bio[bit[j]] = false;
             bit.clear();
        }
        for (int j = 0; j < V[i].size(); ++j){reset(V[i][j].x); reset(V[i][j].y);}
    }
    for (int i = 0; i < q; ++i) printf("%d\n", out[muv[uv[i]]]);
    return 0;
}