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
    int sa, sb;
    cin >> sa >> sb;
    int x = max(sa, sb);
    int a, b;
    for(int i=1; i<n; i++){
        cin >> a >> b;
        if(a < b) swap(a, b);
        if(a <= x) x = a;
        else if(b <= x) x = b;
        else {
            cout << "no";
            return 0;
        }
    }
    cout << "yes";
    return 0;
}