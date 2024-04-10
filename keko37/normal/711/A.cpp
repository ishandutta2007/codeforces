#include<iostream>

using namespace std;

int n;
char s[1005] [7];
char out[1005] [7];

int main () {
    cin >> n;
    bool naso=0;
    for (int i=0; i<n; i++) {
        for (int j=0; j<5; j++) {
            cin >> s[i] [j];
        }
        if (!naso && s[i] [0]=='O' && s[i] [1]=='O') {
            naso=1;
            out[i] [0]='+';
            out[i] [1]='+';
        }
        if (!naso && s[i] [3]=='O' && s[i] [4]=='O') {
            naso=1;
            out[i] [3]='+';
            out[i] [4]='+';
        }
        for (int j=0; j<5; j++) {
            if (out[i] [j]!='+') out[i] [j]=s[i] [j];
        }
    }
    if (naso) cout << "YES" << endl; else cout << "NO" << endl;
    if (naso) {
        for (int i=0; i<n; i++) {
            for (int j=0; j<5; j++) {
                cout << out[i] [j];
            }
            cout << endl;
        }
    }
    return 0;
}