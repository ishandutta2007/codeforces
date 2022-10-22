#include <bits/stdc++.h>
using namespace std;

int n, a, b;

void solve(int x, int y){
    for(int k=1; k<=x; k++){
        for(int i=a*(k-1)+1; i<a*k; i++){
            cout << i+1 << " ";
        }
        cout << a*(k-1)+1 << " ";
    }
    for(int k=1; k<=y; k++){
        for(int i=a*x+b*(k-1)+1; i<a*x+b*k; i++){
            cout << i+1 << " ";
        }
        cout << (a*x+1)+b*(k-1) << " ";
    }
}
int main(){
    ios_base::sync_with_stdio(false),cin.tie(0),cerr.tie(0),cout.tie(0);
    cout.precision(10);
    cout<<fixed;

    cin >> n >> a >> b;
    for(int i=0; a*i<=n; i++){
        if((n-a*i)%b == 0){
            solve(i, (n-a*i)/b);
            return 0;
        }
    }
    cout << -1;
    return 0;
}