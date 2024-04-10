#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        int i = 1;
        for(i = 0; n;)  {
            n--;
            i++; //
            while(!(i%3) || (i%10 == 3)) i++;
        }
        cout << i << '\n';
    }
}