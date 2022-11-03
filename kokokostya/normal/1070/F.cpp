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

int main() {
    iostream::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

#ifdef LOCAL
    freopen("C:\\Users\\aytel\\CLionProjects\\common\\input.txt", "r", stdin);
    freopen("C:\\Users\\aytel\\CLionProjects\\common\\output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    vector< vector<int> > a(4);
    for(int i = 0; i < n; i++){
        char c1, c2;
        int val;
        cin >> c1 >> c2 >> val;
        int pos = 0;
        pos = (c1 - '0') * 2 + (c2 - '0');
        a[pos].push_back(val);
    }
    for(int i  =0; i < 4; i++)
        sort(a[i].begin(), a[i].end());
    if(a[1].size() > a[2].size())
        swap(a[1], a[2]);

    int ans = 0;
    int delta = 0;
    while(!a[3].empty()){
        ans += a[3].back();
        a[3].pop_back();
        delta++;
    }
    while(!a[1].empty()){
        ans += a[1].back();
        ans += a[2].back();
        a[1].pop_back();
        a[2].pop_back();
    }
    while(delta && (!a[0].empty() || !a[2].empty())){
        delta--;
        if(a[0].empty()){
            ans += a[2].back();
            a[2].pop_back();
            continue;
        }
        if(a[2].empty()){
            ans += a[0].back();
            a[0].pop_back();
            continue;
        }
        if(a[0].back() > a[2].back()){
            ans += a[0].back();
            a[0].pop_back();
        }
        else{
            ans += a[2].back();
            a[2].pop_back();
        }
    }
    cout << ans << '\n';

    return 0;
}