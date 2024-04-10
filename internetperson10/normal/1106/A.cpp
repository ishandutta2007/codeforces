#include <iostream>

using namespace std;

char m[510][510];
int main() {
    int n, c=0;
    cin >> n;
    for(int a=1; a<=n; a++) {
        for(int b=1; b<=n; b++)
            cin >> m[a][b];
    }
    for(int a=2; a<n; a++) {
        for(int b=2; b<n; b++) {
            if(m[a][b]==m[a+1][b+1] && m[a+1][b+1]==m[a-1][b-1] && m[a-1][b-1]==m[a-1][b+1] && m[a-1][b+1]==m[a+1][b-1] && m[a+1][b-1]=='X')
                c++;
        }
    }
    cout << c;
}