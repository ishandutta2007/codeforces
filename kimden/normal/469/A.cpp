#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

bool a[1000];

int main() {
    ios_base::sync_with_stdio(false);
    int n;
    int p,b;
    cin >> n;
    for(int i = 0; i < 2; i++){
        cin >> p;
        for(int j = 0; j < p; j++){
            cin >> b;
            a[b-1] = true;
        }
    }
    for(int i = 0; i < n; i++){
        if(!a[i]){
            cout << "Oh, my keyboard!";
            return 0;
        }
    }
    cout << "I become the guy.";
    return 0;
}