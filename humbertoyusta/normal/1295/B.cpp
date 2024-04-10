#include<bits/stdc++.h>
#define int long long
#define ii pair<int,int>
#define f first
#define s second
#define maxn 1010
#define mod 1000000007
using namespace std;

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //freopen("a.in","r",stdin);
    int tc, n, x;
    string s;
    cin >> tc;
    while( tc-- ){
        int bal = 0;
        cin >> n >> x;
        cin >> s;

        for(auto i : s)
            if( i == '0' ) bal++;
                else bal--;
        int nbal = 0, ans = 0;

        if( bal == 0 ){ if( x == nbal ) ans = mod; }
        else{
            bool balsign = ( bal > 0 );
            bool xnsign =  ( ( x - nbal ) > 0 );
            if( ( x - nbal ) % bal == 0 && ( balsign == xnsign || x - nbal == 0 ) ){ ans++; }
        }

        for(int i=0; i<s.size()-1; i++){
            if( s[i] == '0' ) nbal++;
                else nbal--;
            if( bal == 0 ){ if( x == nbal ) ans = mod; continue; }

            bool balsign = ( bal > 0 );
            bool xnsign =  ( ( x - nbal ) > 0 );
            if( ( x - nbal ) % bal == 0 && ( balsign == xnsign || x - nbal == 0 ) ){ ans++; continue; }
        }

        if( ans >= mod ) ans = -1;
        cout << ans << '\n';
    }

    return 0;
}