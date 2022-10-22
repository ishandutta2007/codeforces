#include <iostream>

using namespace std;


int main() {

    int n, m;
    int sol = 0;

    cin >> n >> m;

    for( int i=0; i<n; i++ ) {
        for( int j=0; j<m; j++ ) {
            int a, b;
            cin >> a >> b;

            if( a or b ) sol ++;
        }
    }

    cout << sol;


    return 0;
}