#include<bits/stdc++.h>
using namespace std;

const int mod = 1000000007;
long long ans;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int tc;
    cin >> tc;
    while( tc-- ){

        int x; string s;
        cin >> x >> s;

        ans = s.size();
        for(int i=0; i<x; i++){
            if( s.size() < x ){
                int lim = s.size();
                for(int j=1; j<=int(s[i]-'1'); j++){
                    for(int k=i+1; k<lim; k++){
                        if( s.size() == x ) break;
                            else s += s[k];
                    }
                }
            }
            ans = ( ans + ( ans + mod - ( i + 1 ) ) % mod * (long long)( s[i] - '1' ) ) % mod;
        }

        cout << ans << '\n';
    }
    return 0;
}