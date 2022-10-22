#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

bool postoji[1000000];

int main(){
    ios_base::sync_with_stdio(false),cin.tie(0),cerr.tie(0),cout.tie(0);
    cout.precision(10);
    cout<<fixed;

    ll n, k, pro=1;
    cin >> n >> k;
    for(int i=1; i<=k; i++){
        if(postoji[n%i]){cout << "No"; return 0;}
        postoji[n%i] = 1;
    }
    cout << "Yes";
    return 0;
}