#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int MOD = 998244353;

int add(int a, int b){ a += b; if(a >= MOD) a -= MOD; return a; }
int mul(int a, int b){ return (1LL*a*b)%MOD; }

int fact[500005];
int invfact[500005];

int choose(int n, int k){
    int res = fact[n];
    res = mul(res, invfact[n-k]);
    res = mul(res, invfact[k]);
    return res;
}

int pw(int a, int b){
    if(b == 0) return 1;
    int res = pw(a, b/2);
    res = mul(res, res);
    if(b%2) res = mul(res, a);
    return res;
}

void solve(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector <pair <int, int>> comps;
    int tr = 0;
    int tn = n;
    int free = 0;
    int nule = 0;
    int res = 1;
    for(int i=0; i<n; i++){
        if(s[i] == '1') tr++;
        else{
            nule++;
            if(tr%2 == 0){
                free += tr;
            }
            else{
                comps.push_back({(i-1)-tr+1, i-1});
            }
            tr = 0;
        }
    }
    if(tr){
        if(tr%2 == 0) free += tr;
        else comps.push_back({(n-1)-tr+1, n-1});
    }
    if(comps.size() && comps.back().second == n-1){
        free += comps.back().second - comps.back().first;
        n--;
        comps.pop_back();
    }
    if(comps.size() && comps[0].first == 0){
        free += comps[0].second - comps[0].first;
        n--;
        comps.erase(comps.begin());
        for(int i=0; i<comps.size(); i++){
            comps[i].first--;
            comps[i].second--;
        }
    }
    int snule = nule;
    for(auto c : comps) free += c.second - c.first;
    //cout << endl;
    for(int i=0; i<comps.size(); i++){
        //      cout << comps[i].first << " hmm \n";
        if(i == 0){
            if(comps[i].first%2 == 1){
                nule--;
            }
        }
        if(i+1 < comps.size()){
            if((comps[i+1].first - comps[i].first)%2 == 0){
                nule--;
            }
        }
        else{
            if(comps[i].first%2 == n%2){
                nule--;
            }
        }
    }
    if(free == 0){
        cout << "1\n";
        return;
    }
    nule /= 2;
    free /= 2;
    int vc = comps.size();
    //cout << vc << " " << nule << " " << free << endl;
    //res = mul(res, choose(vc+nule+1-1, vc+1-1));
    //cout << res << "\n";
    //cout << vc << " " << snule << " " << free << "\n";
    res = mul(res, choose(vc+snule+1+free-vc-1, vc+snule+1-vc-1));
    cout << res << "\n";
}

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0);
    cout.precision(10);
    cout << fixed;

    fact[0] = invfact[0] = 1;
    for(int i=1; i<=300000; i++){
        fact[i] = mul(fact[i-1], i);
        invfact[i] = pw(fact[i], MOD-2);
    }
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}

/*
1
4
0110
*/

/*
1
5
01010
*/

/*
1
6
011011
*/

/*
1
7
1101010
*/

/*
1
20
10001111110110111000
*/