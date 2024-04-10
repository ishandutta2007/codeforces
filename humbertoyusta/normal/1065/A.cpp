#include<bits/stdc++.h>
using namespace std;

long long s,a,b,c;
int tc;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ///freopen("a.in","r",stdin);

    cin >> tc;
    while( tc -- ){
        cin >> s >> a >> b >> c;
        cout << s / c + ( s / ( a * c ) ) * b << '\n';
    }


    return 0;
}