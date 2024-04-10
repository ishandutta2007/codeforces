#include<bits/stdc++.h>
using namespace std;

int cnt1;

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string s, b;
    cin >> s;

    for(int i=0; i<s.size(); i++)
        if( s[i] == '1' ) cnt1++;

    bool flag = 0;
    for(int i=0; i<s.size(); i++){
        if( s[i] == '0' ) b += s[i];
        if( s[i] == '2' && !flag ){
            flag = 1;
            b += string( cnt1 , '1' );
        }
        if( s[i] == '2' )
            b += s[i];
    }

    if( !flag )
        b += string( cnt1 , '1' );

    cout << b << '\n';

    return 0;
}