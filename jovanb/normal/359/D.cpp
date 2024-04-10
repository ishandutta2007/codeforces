#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;

int seg[1200005];
int niz[300005];

int n;

void napravi(int l, int r, int node){
    if(l == r){
        seg[node] = niz[l];
        return;
    }
    int mid = (l+r)/2;
    napravi(l, mid, 2*node+1);
    napravi(mid+1, r, 2*node+2);
    seg[node] = __gcd(seg[2*node+1], seg[2*node+2]);
}

int kveri(int l, int r, int trl, int trr, int node){
    if(trl <= l && r <= trr){
        return seg[node];
    }
    int nzd=0;
    int mid = (l+r)/2;
    if(mid >= trl) nzd = kveri(l, mid, trl, trr, 2*node+1);
    if(mid < trr){
        if(!nzd) nzd = kveri(mid+1, r, trl, trr, 2*node+2);
        else nzd = __gcd(nzd, kveri(mid+1, r, trl, trr, 2*node+2));
    }
    return nzd;
}

int checc(int sajz){
    priority_queue <pair <int, int>> pq;
    for(int i=1; i<=sajz; i++){
        pq.push({-niz[i], i});
    }
    int ukup=0;
    int l = 1, r = sajz;
    while(r <= n){
        while(pq.top().second < l) pq.pop();
        int treba = -pq.top().first;
        if(kveri(1, n, l, r, 0) == treba) ukup++;
        l++;
        r++;
        pq.push({-niz[r], r});
    }
    return ukup;
}

int main(){
    ios_base::sync_with_stdio(false),cin.tie(0),cerr.tie(0),cout.tie(0);
    cout.precision(10);
    cout<<fixed;

    cin >> n;
    for(int i=1; i<=n; i++) cin >> niz[i];
    napravi(1, n, 0);
    int l=1, r=n;
    int maxres=0;
    while(l <= r){
        int mid = (l+r)/2;
        if(checc(mid)){
            maxres = max(maxres, mid);
            l = mid+1;
        }
        else r = mid-1;
    }
    priority_queue <pair <int, int>> pq;
    for(int i=1; i<=maxres; i++){
        pq.push({-niz[i], i});
    }
    vector <int> vec;
    l = 1, r = maxres;
    while(r <= n){
        while(pq.top().second < l) pq.pop();
        int treba = -pq.top().first;
        if(kveri(1, n, l, r, 0) == treba) vec.push_back(l);
        l++;
        r++;
        pq.push({-niz[r], r});
    }
    cout << vec.size() << " ";
    cout << maxres-1 << "\n";
    for(auto c : vec) cout << c << " ";
    return 0;
}