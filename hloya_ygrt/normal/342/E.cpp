#include <iostream>
#include <fstream>
// #include <bits/stdc++.h>
#include <sstream>
#include <list>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <deque>
#include <utility>
#include <queue>
#include <set>
#include <map>
#include <assert.h>
#include <bitset>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
#include <iomanip>
#include <ctime>
#include <iterator>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <complex>
 
#define f first
#define s second
#define ll long long
#define ld long double
#define pb push_back
#define files1 freopen("input.txt","r",stdin)
#define files2 freopen("output.txt","w",stdout)
#define files files1;files2
#define mp make_pair
#define fast_io ios_base::sync_with_stdio(0);cin.tie(0)
#define vi vector<int>
#define pii pair<int,int>
#define endl '\n'

using namespace std;
 
void bad(string mes = "Impossible"){cout << mes;exit(0);}
template<typename ... T> void shit(T& ... x){}
template<typename ... T> void dec(T& ... x){shit(--x...);}
template<typename ... T> void inc(T& ... x){shit(++x...);}

template<typename T>
string bin(T x, int st = 2){
    string ans = "";
    while (x > 0){
        ans += char('0' + x % st);
        x /= st;
    }
    reverse(ans.begin(), ans.end());
    return ans.empty() ? "0" : ans;
}

template<typename T>
T input(){
    T ans = 0, m = 1;
    char c = ' ';
    while (!((c >= '0' && c <= '9') || c == '-'))
        c = getchar();
    if (c == '-')
        m = -1, c = getchar();
    while (c >= '0' && c <= '9'){
        ans = ans * 10 + (c - '0'), c = getchar();
    }
    return ans * m;
}

template<typename T>
void read(T& a) {
    a = input<T>();
}

template<typename T>
void read(T& a, T& b) {
    read(a), read(b);
}

template<typename T>
void read(T& a, T& b, T& c) {
    read(a, b), read(c);
}

template<typename T>
void read(T& a, T& b, T& c, T& d) {
    read(a, b), read(c, d);
}
 
const int inf = 1e9;
const double eps = 1e-9;
const int maxn = 1e5 + 1, base = 1e8;
const int sigm = 26;
const ll llinf = 1e18 + 1;

template<typename T>
T binpow(T n, T s)
{
    if (s <= 0)
        return 1LL;
    if (s % 2 == 0){
        T b = binpow(n, s / 2);
        return ( 1LL * b * b ) % base;
    } else {
        return (1LL* binpow(n, s - 1) * n) % base;
    }
}

vector<int> g[maxn];
bool deleted[maxn];

int sizeOfTree[maxn];

void getTreeSizes(int v, int p = -1) {
    sizeOfTree[v] = 1;
    for (int to:g[v]) {
        if (to != p && !deleted[to]) {
            getTreeSizes(to, v);
            sizeOfTree[v] += sizeOfTree[to];
        }
    }
}

void fixCentroid(int& root, int v, int p, int& centroid) {
    int maximalSon = 0;
    for (int to:g[v]) {
        if (to != p && !deleted[to]) {
            fixCentroid(root, to, v, centroid);
            maximalSon = max(maximalSon, sizeOfTree[to]);
        }
    }

    int N = sizeOfTree[root];
    if (maximalSon <= N / 2 && N - sizeOfTree[v] <= N / 2)
        centroid = v;
}

int cntLayers = 0;
set<pair<int, int> > blackInLayer[maxn], whiteInLayer[maxn]; // pair( dist, vertex)

vector<pair<int, int> > layers[maxn]; // pair( layer, dist)

void fixingWays(int v, int p, int& l, int depth = 0) {
    layers[v].push_back(make_pair(l, depth));
    blackInLayer[l].insert(make_pair(depth, v));

    for (int to:g[v]) {
        if (to != p && !deleted[to]) {
            fixingWays(to, v, l, depth + 1);
        }
    }
}

void buildingDfs(int start) {
    getTreeSizes(start);

    int centroid = -1;
    fixCentroid(start, start, -1, centroid);
    assert(centroid != -1);

    int curLayer = cntLayers++;
    fixingWays(centroid, -1, curLayer);

    deleted[centroid] = 1;
    for (int next:g[centroid])
        if (!deleted[next])
            buildingDfs(next);
}

void buildCentroid(int& n) {
    for (int i = 0; i < n; i++)
        deleted[i] = 0;
    buildingDfs(0);
}

int color[maxn];

int main()
{
    int n, q;
    // files1;
    // read(n);
    //for CF
    read(n, q);

    for (int i = 1; i < n; i++) {
        int from, to;
        read(from, to);
        dec(from, to);

        g[from].push_back(to);
        g[to]  .push_back(from);
    }

    for (int i = 0; i < n; i++)
        color[i] = 1;
    buildCentroid(n);

    // q = input<int>();
    // return 0;
    for (int i = 0; i <= q; i++) {
        int type, vertex;
        if (i) 
        read(type, vertex);
        // FOR CF
        {
        if (i == 0)
            type = 1, vertex = 1;

        type--;
        }
        vertex--;

        if (type == 0) {
            for (int j = 0; j < layers[vertex].size(); j++) {
                int curLayer = layers[vertex][j].first,
                    depth    = layers[vertex][j].second;

                pair<int, int> data = make_pair(depth, vertex);

                if (color[vertex] == 0) {
                    whiteInLayer[curLayer].erase(data);
                    blackInLayer[curLayer].insert(data);
                } else {
                    blackInLayer[curLayer].erase(data);
                    whiteInLayer[curLayer].insert(data);
                }
            }
            color[vertex] ^= 1;
        } else {
            int answer = inf;
            for (int j = 0; j < layers[vertex].size(); j++) {
                int curLayer = layers[vertex][j].first,
                    depth    = layers[vertex][j].second;

                if (!whiteInLayer[curLayer].empty())
                    answer = min(answer, depth + 
                        (*whiteInLayer[curLayer].begin()).first);
            }
            printf("%d\n", answer); 
        }
    }
    return 0;
}