#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<int> f(int x){
    vector<int>a;
    for(int i = 1; i*i<=x; i++){
        if(x%i==0){
            a.push_back(i);
            a.push_back(x/i);
        }
    }
    return a;
}
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--){
        int x,y;
        cin >> x >> y;
        set<int>s;
        for(int nxt: f(__gcd(x-2,y))){
            s.insert(nxt);
        }
        for(int nxt: f(__gcd(x,y-2))){
            s.insert(nxt);
        }
        for(int nxt: f(__gcd(x-1,y-1))){
            s.insert(nxt);
        }
        for(int nxt: f(__gcd(__gcd(x-2,y-1),x))){
            s.insert(nxt);
        }
        for(int nxt: f(__gcd(__gcd(y-2,x-1),y))){
            s.insert(nxt);
        }
        cout << s.size() << " ";
        for(int nxt: s){
            cout << nxt << " ";
        }
        cout << "\n";
    }
    return 0;
}