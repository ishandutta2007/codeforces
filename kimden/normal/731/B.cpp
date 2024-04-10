#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

int rot(char a, char b){
    int aa = a - 'a';
    int bb = b - 'a';
    return min((aa - bb + 26) % 26, (bb - aa + 26) % 26);
}

int a[200001];

int main() {
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    int carry = 0;
    for(int i = 0; i < n; ++i){
        cin >> a[i];
        if(a[i] < carry){
            cout << "NO";
            return 0;
        }
        a[i] -= carry;
        a[i] %= 2;
        carry = a[i];
    }
    if(carry){
        cout << "NO";
        return 0;
    }
    cout << "YES";
    return 0;
}