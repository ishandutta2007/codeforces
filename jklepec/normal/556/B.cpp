#include <iostream>
using namespace std;

const int MaxN = 1010;

int a[MaxN];

int main() {

    int n;
    cin >> n;
    for( int i=0; i<n; i++ )
        cin >> a[i];
    bool moze = false;
    for( int i=0; i<n; i++ ) {

        bool current = true;

        for( int j=0; j<n; j++ )
            if( ( a[j] + n + ( i * (j%2 ? -1 : 1 ) ) ) % n != j  )
                current = false;

        if (current) moze = true;
    }
    cout << (moze ? "yes" : "no" ) << endl;
    return 0;
}