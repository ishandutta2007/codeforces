#include<bits/stdc++.h>
#define ii pair<int,int>
#define f first
#define s second
using namespace std;

int pot[11], q, n;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    pot[0] = 1;
    for(int i=1; i<10; i++)
        pot[i] = pot[i-1] * 10;

    cin >> q;
    while( q-- ){
        cin >> n;
        int m = n;
        int sum = 0, u = 0, osm = 0;
        while( osm <= n ){
            u++;
            sum += int(log10(u)) + 1;
            osm += sum;
            if( m - sum >= 0 ) m -= sum;
        }
        if( m == 0 ){ cout << ( u - 1 ) % 10 << '\n'; continue; }
        bool flag = 0;
        for(int i=1; i<=u; i++){
            if( m <= int(log10(i)) + 1 ){
                m = int(log10(i)) + 1 - m + 1;
                cout << i % pot[m] / pot[m-1] << '\n';
                flag = 1;
                break;
            }
            m -= int(log10(i)) + 1;
        }
    }

    return 0;
}