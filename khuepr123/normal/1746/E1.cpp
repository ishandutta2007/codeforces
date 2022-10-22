/*
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
*/
// lethal option

#include<bits/stdc++.h>
using namespace std;

#define all(flg) flg.begin(), flg.end()
#define int long long
#define pb push_back
#define fi first
#define se second
#define eb emplace_back
#define ii pair<int, int>
#define vi vector<int>
#define PI 3.141592653589793238462643383279502884
#define ll long long
#define ld long double
#define for1(i, ff, gg) for(int i = ff; i <= gg; ++i)
#define for2(i, ff, gg) for(int i = ff; i >= gg; --i)
#define flex(i, ff, gg) for(int i = ff; i < gg; ++i)
const ll mod = 1e9 + 7;
const int maxN = 300005;
const ll oo = 1e18 + 7;
int n, a[maxN];
int x, y, z, k;

vi v[3];

bool qry(vi &cac){
    cout << "? ";
    cout << cac.size() << endl;
    for(int cc : cac) cout << cc << " ";
    cout << endl;
    string s; cin >> s;
    return (s[0] == 'Y');
}


bool simp_qry(int cac){
    vi cu; cu.pb(cac);
    return qry(cu);
}

void guess(int x){
    cout << "! " << x << endl;
    string s; cin >> s;
    if(s[1] == ')') exit(0);
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    vi vc;
    for1(i, 1, n) vc.pb(i);
    while(vc.size() > 3){
        v[1].clear();
        v[2].clear();
        flex(i, 0, vc.size()){
            for1(j, 1, 2) if(i & j) v[j].pb(vc[i]);
        }
        for1(j, 1, 2) if(!qry(v[j])){
            v[j].clear();
            flex(i, 0, vc.size()) if((i & j) == 0) v[j].pb(vc[i]);
        }
        vc.clear();
        vc.insert(vc.end(), all(v[1]));
        vc.insert(vc.end(), all(v[2]));
        sort(all(vc));
        vc.resize(unique(all(vc)) - vc.begin());
    }
    bool f = 0;
    for(int &cc : vc){
        if(simp_qry(cc)){
            swap(cc, vc.back());
            break;
        }
        else if(simp_qry(cc)){
            swap(cc, vc.back());
            break;
        }
        else{
            swap(cc, vc.back()); f = 1;
            break;
        }
    }
    if(f) vc.pop_back();
    if(vc.size() <= 2) for(int cc : vc) guess(cc);
    guess(vc.back()); vc.pop_back();
    if(simp_qry(vc[0])) guess(vc[0]);
    else guess(vc[1]);
}