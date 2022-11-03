#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAXN = 100002;
const int MAXLOG = 20;


void solve(int test, istream& in, ostream& out){

    int n, k;
    int i;
    ll sum = 0;
    cin >> n >> k;
    for(i = 0; i < n; i++){
        if(sum + 5 * (i + 1) > 240 - k){
            out << i << endl;
            return;
        }
        sum += 5 * (i + 1);
    }
    out << i << endl;
}

int main(){
    solve(1, cin, cout);
    return 0;
}