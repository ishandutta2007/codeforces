/*
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
*/
// lethal option

#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define fi first
#define se second
#define ii pair<int, int>
#define PI 3.141592653589793238462643383279502884
#define ll long long
#define for1(i, ff, gg) for(int i = ff; i <= gg; ++i)
#define for2(i, ff, gg) for(int i = ff; i >= gg; --i)
const ll mod = 1e9 + 7;
const int maxN = 300005;
const ll oo = 1e18 + 7;
int n, a[maxN];
int x, y, z, k;

vector<int> id;
bool ops = 0;

int prt(int x11, int y11, int x22, int y22){
    if(ops) swap(x11, y11);
    if(ops) swap(x22, y22);
    cout << "? ";
    cout << x11 << " ";
    cout << y11 << " ";
    cout << x22 << " ";
    cout << y22 << " ";
    cout << endl;
    int dumbass; cin >> dumbass;
    return (dumbass % 2);
}

int endofall(int x11, int y11, int x22, int y22){
    if(ops) swap(x11, y11);
    if(ops) swap(x22, y22);
    cout << "! ";
    cout << x11 << " ";
    cout << y11 << " ";
    cout << x22 << " ";
    cout << y22 << " ";
    cout << endl;
    exit(0);
}

void act(){
    int l = 1; int r = n;
    while(l != r){
        int mid = (l + r) / 2;
        if(prt(l, 1, mid, id[0])) r = mid;
        else l = mid + 1;
    }
    endofall(l, id[0], l, id[1]);
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for1(i, 1, n){
        x = prt(i, 1, i, n);
        if(x) id.pb(i);
    }
    if(id.size() == 0){
        for1(i, 1, n){
            x = prt(1, i, n, i);
            if(x) id.pb(i);
        }
        act();
    }
    else{
        for1(i, 1, n){
            x = prt(1, i, n, i);
            if(x) id.pb(i);
        }
        if(id.size() == 2){
            ops = 1;
            act();
        }
        if(prt(id[0], id[2], id[0], id[2]))
        endofall(id[0], id[2], id[1], id[3]);
        endofall(id[0], id[3], id[1], id[2]);
    }
}