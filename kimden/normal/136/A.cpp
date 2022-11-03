#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

int a[100];
int main() {
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    int b;
    for(int i = 0; i < n; i++){
        cin >> b;
        a[b - 1] = i;
    }
    for(int i = 0; i < n; i++){
        if(i){
            cout << " ";
        }
        cout << a[i] + 1;
    }
    return 0;
}