#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false),cin.tie(0),cerr.tie(0),cout.tie(0);
    cout.precision(10);
    cout<<fixed;

    int n, k;
    cin >> n >> k;
    if(k%2 != 0){
        if(k < n-2){
            cout << "YES\n";
            for(int i=1; i<=n; i++) cout << ".";
            cout << "\n";
            int mid = n/2+1;
            int l = mid-k/2;
            int r = mid+k/2;
            for(int i=1; i<l; i++) cout << ".";
            for(int i=l; i<=r; i++) cout << "#";
            for(int i=r+1; i<=n; i++) cout << ".";
            cout << "\n";
            for(int i=1; i<=n; i++) cout << ".";
            cout << "\n";
            for(int i=1; i<=n; i++) cout << ".";
            cout << "\n";
            return 0;
        }
        if(k > n-2){
            cout << "YES\n";
            for(int i=1; i<=n; i++) cout << ".";
            cout << "\n";
            cout << ".";
            for(int i=2; i<n; i++) cout << "#";
            cout << ".";
            cout << "\n";
            k -= (n-2);
            k /= 2;
            cout << ".";
            for(int i=2; i<=1+k; i++) cout << "#";
            int r = n;
            r -= k;
            for(int i=2+k; i<r; i++) cout << ".";
            for(int i=r; i<n; i++) cout << "#";
            cout << ".";
            cout << "\n";
            for(int i=1; i<=n; i++) cout << ".";
            return 0;
        }
        cout << "YES\n";
        for(int i=1; i<=n; i++) cout << ".";
        cout << "\n";
        cout << ".";
        for(int i=2; i<=1+k; i++) cout << "#";
        for(int i=k+2; i<=n; i++) cout << ".";
        cout << "\n";
        for(int i=1; i<=n; i++) cout << ".";
        cout << "\n";
        for(int i=1; i<=n; i++) cout << ".";
        return 0;
    }
    k /= 2;
    cout << "YES\n";
    for(int i=1; i<=n; i++) cout << ".";
    cout << "\n";
    cout << ".";
    for(int i=2; i<=1+k; i++) cout << "#";
    for(int i=k+2; i<=n; i++) cout << ".";
    cout << "\n";
    cout << ".";
    for(int i=2; i<=1+k; i++) cout << "#";
    for(int i=k+2; i<=n; i++) cout << ".";
    cout << "\n";
    for(int i=1; i<=n; i++) cout << ".";
    return 0;
}