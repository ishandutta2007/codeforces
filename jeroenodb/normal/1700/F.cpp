#include <bits/stdc++.h>
using namespace std;
int main(){
    long long n, c = 0, t = 0, a, v, i; cin>>n;
    int u[n], d[n];
    for(int &p: u) cin>>p;
    for(int &p: d) cin>>p;
    for(int& p : u) {
        int a; cin >> a;
        p-=a;
    }
    for(int& p : d) {
        int a; cin >> a;
        p-=a;
    }
    for(i=0; i<n; i++){
        c += u[i], t += d[i];
        if(c*t<0){
            a += v = min(abs(c), abs(t));
            if(c>0) v = -v;
            c += v, t -= v;
        }
        a += abs(c + t);
    }
    if(c!=0 or t!=0) {
        cout << "-1\n";
    }
    else cout<<a;
}