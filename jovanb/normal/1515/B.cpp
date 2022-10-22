#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

bool sq(int x){
    int y = sqrt(x);
    while(y*y < x) y++;
    return y*y == x;
}

bool solve(){
    int x;
    cin >> x;
    int a = x/2;
    if(sq(a) && x%2 == 0) return 1;
    a = x/4;
    if(sq(a) && x%4 == 0) return 1;
    return 0;
}

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0);
	cout.precision(10);
	cout << fixed;

    int t;
    cin >> t;
    while(t--){
        if(solve()) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}