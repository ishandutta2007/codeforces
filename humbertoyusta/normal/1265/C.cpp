#include<bits/stdc++.h>
using namespace std;

int a[2000005];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int tc;
    cin >> tc;
    while( tc-- ){

        int n;
        cin >> n;

        for(int i=1; i<=n; i++){
            cin >> a[i];
        }

        int g = 0 , s = 0 , b = 0, id = 1;
        bool flag = 0;

        while( a[id] == a[id+1] && id + 1 <= n ) id++;
        g = id;

        id += g + 1;
        while( a[id] == a[id+1] && id + 1 <= n ) id++;
        s = id - g;

        id += g + 1;
        if( id > n / 2 ){ cout << 0 << ' ' << 0 << ' ' << 0 << '\n'; continue; }

        for(int i=n/2; i>=id; i--){
            if( a[i] != a[i+1] ){
                b = i - g - s;
                flag = 1;
                break;
            }
        }

        if( !flag ){ cout << 0 << ' ' << 0 << ' ' << 0 << '\n'; continue; }
            else cout << g << ' ' << s << ' ' << b << '\n';
    }

    return 0;
}