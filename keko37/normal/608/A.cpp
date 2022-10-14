#include<iostream>

using namespace std;

int n, s, t;
int l[1005];

int main () {
    cin >> n >> s;
    for (int i=0; i<n; i++) {
        int x, y;
        cin >> x >> y;
        l[x]=max(l[x], y);
    }
    for (int i=s; i>=0; i--) {
        if (t<l[i]) t=l[i];
        t++;
    }
    cout << t-1;
    return 0;
}