#include <bits/stdc++.h>
#define va first
#define vb second
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

string s;
ll ans;
int arr[1010100], cur, p;
int pfx[1010100];
int main() {
    cin >> s;

    int i=0;
    while (s[i]=='o') ++i;

    for (; i<s.size(); i++) {
        if ((cur==0 && s[i]=='o') ||
            (cur==1 && s[i]=='v')) {

            cur = 1-cur;
            ++p;
        }

        arr[p]++;
    }
//
//    for (int j=0; j<=p; j++) {
//        cout << arr[j] << ' ';
//    }

    for (i=0; i<=p; i+=2) {
        arr[i]--;
        pfx[i]=pfx[i-2]+arr[i];
    }

//    for (int j=0; j<=p; j++) {
//        cout << arr[j] << ' ';
//    }
//
//    cout << i;

    for (int j=1; j<=p; j+=2) {
        ans += (ll)arr[j]*pfx[j-1]*(pfx[i-2]-pfx[j-1]);
    }

    cout << ans;
}