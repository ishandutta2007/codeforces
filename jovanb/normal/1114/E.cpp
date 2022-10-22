#include <bits/stdc++.h>
using namespace std;

bool veci(int x){
    cout << "> " << x << endl;
    bool r;
    cin >> r;
    return r;
}

int val(int x){
    cout << "? " << x << endl;
    int r;
    cin >> r;
    return r;
}

int niz[100005];
vector <int> vec;

mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

int main(){

    int n;
    cin >> n;
    int ima = 60;
    int l = 0, r = 1000000000, res = 0;
    while(l <= r){
        int mid = (l+r)/2;
        ima--;
        if(veci(mid)){
            res = mid+1;
            l = mid+1;
        }
        else r = mid-1;
    }
    vec.push_back(res);
    while(ima--){
        int i = rnd()%n+1;
        vec.push_back(val(i));
    }
    sort(vec.begin(), vec.end());
    int b = 0;
    niz[++b] = vec[0];
    int m = vec.size();
    for(int i=1; i<m; i++){
        if(vec[i] != vec[i-1]) niz[++b] = vec[i];
    }
    int nzd = 0;
    for(int i=2; i<=b; i++){
        nzd = __gcd(nzd, niz[i] - niz[i-1]);
    }
    int prvi = niz[b] - (n-1)*nzd;
    cout << "! " << prvi << " " << nzd << endl;
    return 0;
}