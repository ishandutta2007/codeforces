#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

int ima[200005];
int bit[200005];
map <int, int> u;

void addbit(int x, int val){
    while(x <= 200000){
        bit[x] += val;
        x += x & -x;
    }
}

int getbit(int x){
    int res = 0;
    while(x){
        res += bit[x];
        x -= x & -x;
    }
    return res;
}

pair <int, int> p[200005];

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0);
    cout.precision(10);
    cout << fixed;

    int n;
    cin >> n;
    ll diff = 0;
    vector <int> vect;
    for(int i=1; i<=n; i++){
        cin >> p[i].second >> p[i].first;
        vect.push_back(p[i].second);
    }
    sort(vect.begin(), vect.end());
    int cmpcnt = 0;
    for(auto c : vect){
        if(!u[c]) u[c] = ++cmpcnt;
    }
    for(int i=1; i<=n; i++){
        p[i].second = u[p[i].second];
    }
    sort(p+1, p+1+n);
    for(int i=1; i<=n; i++){
        if(!ima[p[i].second]){
            diff++;
            addbit(p[i].second, 1);
        }
        ima[p[i].second]++;
    }
    ll res = 0;
    for(int i=1; i<=n; i++){
        int j = i;
        while(j < n && p[i].first == p[j+1].first) j++;
        res += diff*(diff+1)/2;
        for(int k=i; k<=j; k++){
            ima[p[k].second]--;
            if(!ima[p[k].second]){
                diff--;
                addbit(p[k].second, -1);
            }
        }
        for(int k=i; k<j; k++){
            ll imaz = getbit(p[k+1].second-1) - getbit(p[k].second);
            res -= imaz*(imaz+1)/2;
        }
        ll imaz = getbit(p[i].second-1);
        res -= imaz*(imaz+1)/2;
        imaz = getbit(200000) - getbit(p[j].second);
        res -= imaz*(imaz+1)/2;
        i = j;
    }
    cout << res;
    return 0;
}