#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

int deg[100005];

int main(){
    ios_base::sync_with_stdio(false);
    cout.precision(10);
    cout<<fixed;

    int n;
    cin >> n;
    for(int i=1; i<n; i++){
        int a, b;
        cin >> a >> b;
        deg[a]++;
        deg[b]++;
    }
    for(int i=1; i<=n; i++){
        if(deg[i] == 2){
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
    return 0;
}