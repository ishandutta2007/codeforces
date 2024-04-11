#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <string>
#include <sstream>
#include <complex>
#include <vector>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
using namespace std;
typedef long long unsigned int ll;

int par[200500];
int rank1[200500];

void init(int n)
{
    for(int i = 0; i < n; i++){
        par[i] = i;
        rank1[i] = 0;
    }
}

int find(int x)
{
    if(par[x] == x){
        return x;
    } else {
        return par[x] = find(par[x]);
    }
}

void unite(int x, int y)
{
    x = find(x);
    y = find(y);
    if(x == y){
        return ;
    }
    if(rank1[x] , rank1[y]){
        par[x] = y;
    } else {
        par[y] = x;
        if(rank1[x] == rank1[y]){
            rank1[x]++;
        }
    }
}

bool same(int x, int y)
{
    return find(x) == find(y);
}

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))

int main() {
    //cout.precision(10);
    int n, m, q;
    cin >> n >> m >> q;
    if(q == 0){
        cout << n + m - 1 << endl;
        return 0;
    }
    init(m + 1);
    vector<pair<int, int> > normal(q);
    vector<pair<int, int> > reverse(q);
    for(int i = 0; i < q; i++){
        int in1, in2;
        cin >> in1 >> in2;
        normal[i].first = in1;
        normal[i].second = in2;
        reverse[i].first = in2;
        reverse[i].second = in1;
    }
    sort(normal.begin(), normal.end());
    sort(reverse.begin(), reverse.end());
    for(int i = 0; i < q - 1; i++){
        if(normal[i].first == normal[i + 1].first){
            unite(normal[i].second, normal[i + 1].second);
        }
    }
    int ans1 = -1;
    for(int i = 1; i <= m; i++){
        int a = find(i);
    }
    for(int i = 1; i <= m; i++){
        if(i == find(i)){
            ans1++;
        }
    }
    int vacant = n - 1;
    for(int i = 0; i < q - 1; i++){
        if(normal[i].first != normal[i + 1].first){
            vacant--;
        }
    }
    ans1 = ans1 + vacant;
    init(n + 1);
    for(int i = 0; i < q - 1; i++){
        if(reverse[i].first == reverse[i + 1].first){
            unite(reverse[i].second, reverse[i + 1].second);
        }
    }
    int ans2 = -1;
    for(int i = 1; i <= n; i++){
        int a = find(i);
    }
    for(int i = 1; i <= n; i++){
        if(i == find(i)){
            ans2++;
        }
    }
    vacant = m - 1;
    for(int i = 0; i < q - 1; i++){
        if(reverse[i].first != reverse[i + 1].first){
            vacant--;
        }
    }
    ans2 += vacant;
    cout << min(ans1, ans2) << endl;
    return 0;
}