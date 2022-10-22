#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

int niz[1000005];
ll bit[1000005];
ll res[1000005];
map <int, int> u;
vector <int> vec;

int cnt;
int n;

ll getbit(int x){
    ll rs = 0;
    while(x > 0){
        rs += bit[x];
        x -= x & -x;
    }
    return rs;
}

void updbit(int x, int val){
    while(x <= n){
        bit[x] += val;
        x += x & -x;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cout.precision(10);
    cout<<fixed;

    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> niz[i];
        vec.push_back(niz[i]);
    }
    reverse(niz+1, niz+1+n);
    sort(vec.begin(), vec.end());
    for(auto c : vec){
        u[c] = ++cnt;
    }
    for(int i=1; i<=n; i++) niz[i] = u[niz[i]];
    for(int i=1; i<=n; i++){
        res[niz[i]] = getbit(niz[i]-1);
        updbit(niz[i], 1);
    }
    for(int i=1; i<=n; i++){
        bit[i] = 0;
    }
    ll sum=0;
    for(int i=1; i<=n; i++){
        sum += getbit(niz[i]-1);
        updbit(niz[i], res[niz[i]]);
    }
    cout << sum;
    return 0;
}