#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

int niz1[100005];
int niz2[100005];

int main(){
    ios_base::sync_with_stdio(false);
    cout.precision(10);
    cout<<fixed;

    int n;
    cin >> n;
    for(int i=1; i<=n; i++) cin >> niz1[i];
    for(int i=1; i<=n; i++) cin >> niz2[i];
    sort(niz1+1, niz1+1+n);
    sort(niz2+1, niz2+1+n);
    int r1=n, r=n;
    ll sum=0;
    int moves = n;
    while(moves--){
        if(niz2[r1] < niz1[r]){
            sum += niz1[r];
            r--;
        }
        else r1--;
        if(niz1[r] < niz2[r1]){
            sum -= niz2[r1];
            r1--;
        }
        else r--;
    }
    cout << sum;
    return 0;
}