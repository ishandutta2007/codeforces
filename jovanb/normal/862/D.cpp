#include <bits/stdc++.h>
using namespace std;

int query(string s){
    cout << "? " << s << endl;
    int x;
    cin >> x;
    return x;
}

int pos0, pos1;
int g = 0;
int n;

void resi(int l, int r){
    string s = "";
    if(l > r) return;
    //cout << "debug " << l << " " << r << endl;
    int mid = (l+r)/2;
    if(l == r) mid = r;
    for(int i=1; i<l; i++){
        s += '1';
    }
    for(int i=l; i<=mid; i++) s += '0';
    for(int i=mid+1; i<=n; i++){
        s += '1';
    }
    int x = query(s);
    int m = g-x;
    if(m == mid-l+1){
        //cout << "case1\n";
        pos0 = l;
        resi(mid+1, r);
        return;
    }
    if(m == -mid+l-1){
        //cout << "case2\n";
        pos1 = l;
        resi(mid+1, r);
        return;
    }
    resi(l, mid);
}

int main(){

    cin >> n;
    string s = "";
    for(int i=1; i<=n; i++){
        s += '1';
    }
    g = query(s);
    resi(1, n);
    cout << "! " << pos0 << " " << pos1 << endl;
    return 0;
}