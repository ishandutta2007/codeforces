#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;

int n, x, y;


int querybit(int b){
    vector<int> v;
    for(int i = 1; i <= n; ++i){
        if(i & b){
            v.push_back(i);
        }
    }
    if(v.size() == 0){
        return 0;
    }
    cout << "? " << v.size();
    for(int i = 0; i < v.size(); ++i){
        cout << " " << v[i];
    }
    cout << endl;
    int p;
    cin >> p;
    if(v.size() % 2 == 0){
        p ^= x;
    }
    if(p == x){
        return 0;
    }
    return 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> x >> y;
    int div = 1;
    int xr = 0;
    int sth = 0;
    for(int i = 1; i <= 1024; i <<= 1){
        if(querybit(i)){
            xr |= i;
            sth = i;
        }
    }
    vector<int> q;
    for(int i = 1; i <= n; ++i){
        if((i & sth) == 0){
            q.push_back(i);
        }
    }
    int l = 0;
    int r = -1 + (int)q.size();
    int mid;
    vector<int> o;
    int res;
    while(r > l){
        mid = (l + r) >> 1;
        cout << "? " << (mid - l + 1);
        for(int i = l; i <= mid; ++i){
            cout << " " << q[i];
        }
        cout << endl;
        cin >> res;
        if((mid - l + 1) % 2 == 0){
            res ^= x;
        }
        if(res == y){
            r = mid;
        }else{
            l = mid + 1;
        }
    }
    cout << "! " << q[l] << " " << (q[l] ^ xr) << endl;
    return 0;
}