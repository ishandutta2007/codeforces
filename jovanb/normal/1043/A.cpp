#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

int main(){
    ios_base::sync_with_stdio(false);
    cout.precision(10);
    cout<<fixed;

    int n;
    cin >> n;
    int sum=0;
    int mx = 0;
    int x;
    for(int i=1; i<=n; i++){
        cin >> x;
        sum += x;
        mx = max(mx, x);
    }
    int k=mx;
    while(1){
        if(n*k-sum > sum){cout << k; return 0;}
        k++;
    }
    return 0;
}