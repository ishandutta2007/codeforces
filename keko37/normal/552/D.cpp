#include<iostream>

using namespace std;

int n;
int l[2005];
int p[2005];
int sol;

bool naistom (int x1, int y1, int x2, int y2, int x3, int y3) {
    return (x2-x1)*(y3-y1)==(y2-y1)*(x3-x1);
}

int main () {
    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> l[i] >> p[i];
    }
    if (n<3) {
        cout << 0;
        return 0;
    }
    for (int i=0; i<n-2; i++) {
        for (int j=i+1; j<n-1; j++) {
            for (int k=j+1; k<n; k++) {
                if (!naistom(l[i], p[i], l[j], p[j], l[k], p[k])) sol++;
            }
        }
    }
    cout << sol;
    return 0;
}