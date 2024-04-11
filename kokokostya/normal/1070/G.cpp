#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>
#include <string>
#include <cstdio>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <stack>
#include <bitset>
#include <cmath>
#include <iomanip>
#include <functional>
#include <cstring>
#include <cassert>
#include <numeric>

//#define FAST_ALLOCATOR_MEMORY 2e8
//#include "optimization.h"

using namespace std;

typedef long long ll;
typedef long double ld;
const ll md = (ll)1e9 + 7, inf = (ll)1e18;

vector< pair<int, int> > b;

void doit(vector<int> &x, vector<int>& a, int to, vector<int> &order, vector<int>& lst, bool& ok){
    while(!x.empty()){
        int v = x.back();
        x.pop_back();
        int now = b[v].second;
        int pos = b[v].first;
        bool gd = 1;

        while(pos < to){
            pos++;
            now += a[pos];
            gd &= (now >= 0);
        }
        while(pos > to){
            pos--;
            now += a[pos];
            gd &= (now >= 0);
        }

        if(gd){
            pos = b[v].first;
            while(pos < to){
                pos++;
                a[pos] = 0;
            }
            while(pos > to){
                pos--;
                a[pos] = 0;
            }
            order.push_back(v);

        }
        else{
            lst.push_back(v);
            if(x.empty())
                ok = 0;
        }

    }

}

vector<int> tr(vector<int> x, vector<int> y, vector<int> a, int to){
    vector<int> order, lst;

    bool ok = 1;
    doit(x, a, to, order, lst, ok);
    doit(y, a, to, order, lst, ok);
    if(!ok)
        return {};

    while(!lst.empty()){
        order.push_back(lst.back());
        lst.pop_back();
    }
    return order;



}

int main() {
    iostream::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

#ifdef LOCAL
    freopen("C:\\Users\\aytel\\CLionProjects\\common\\input.txt", "r", stdin);
    freopen("C:\\Users\\aytel\\CLionProjects\\common\\output.txt", "w", stdout);
#endif
    int n, m;
    cin >> n >> m;
    b.resize(m);
    for(int i = 0; i < m; i++){
        cin >> b[i].first >> b[i].second;
        b[i].first--;
    }
    vector<int> a(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];

    for(int to = 0; to < n; to++){
        vector<int> l, r;
        for(int i = 0; i < m; i++){
            if(b[i].first <= to)
                l.push_back(i);
            else
                r.push_back(i);
        }
        sort(l.begin(), l.end(), [&](int x, int y){return b[x].first < b[y].first;});
        sort(r.begin(), r.end(), [&](int x, int y){return b[x].first > b[y].first;});

        if(!tr(l, r, a, to).empty()){
            cout << to + 1 << '\n';
            for(int i : tr(l, r, a, to)){
                cout << i + 1 << ' ';
            }
            return 0;
        }

        if(!tr(r, l, a, to).empty()){
            cout << to + 1 << '\n';
            for(int i : tr(r, l, a, to)){
                cout << i + 1 << ' ';
            }
            return 0;
        }

    }
    cout << -1 << '\n';

    return 0;
}