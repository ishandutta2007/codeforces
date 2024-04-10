#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

ll niz[200005];
unordered_map <ll, int> u;
int cnt;
ll bit[1000005];
vector <ll> vec;

void addbit(int x){
    while(x <= cnt){
        bit[x]++;
        x += x & -x;
    }
}

ll getbit(int x){
    ll res=0;
    while(x > 0){
        res += bit[x];
        x -= x & -x;
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0);
    cout.precision(10);
    cout<<fixed;

    int n;
    ll t;
    cin >> n >> t;
    ll sum=0;
    ll pre=0;
    for(int i=1; i<=n; i++){
        cin >> niz[i];
        sum += niz[i];
        pre += i;
        vec.push_back(sum);
        vec.push_back(sum-t);
    }
    vec.push_back(0);
    sort(vec.begin(), vec.end());
    for(auto c : vec){
        if(!u[c]) u[c] = ++cnt;
    }
    ll res=0;
    sum = 0;
    addbit(u[0]);
    for(int i=1; i<=n; i++){
        sum += niz[i];
        res += getbit(u[sum-t]);
        addbit(u[sum]);
    }
    cout << pre-res;
    return 0;
}