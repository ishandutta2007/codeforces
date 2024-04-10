#include<bits/stdc++.h>
#define maxn 50005
#define ll long long
using namespace std;

int n,s,e,j,ans,tc,res;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ///freopen("a.in","r",stdin);

    cin >> tc;
    while( tc-- ){
        cin >> n >> s >> e >> j;
        if( abs(e-s) % j == 0 ){
            cout << abs(e-s) / j << '\n';
            continue;
        }
        res = (1<<30);
        if( ( e - 1 ) % j == 0 ){
            ans = ( s - 1 ) / j;
            if( ( s - 1 ) % j )
                ans++;
            ans += ( e - 1 ) / j;
            res=min(res,ans);
        }
        if( ( n -  e ) % j == 0 ){
            ans = ( n - s ) / j;
            if( ( n - s ) % j )
                ans++;
            ans += ( n - e ) / j;
            res=min(res,ans);
        }
        if( res != (1<<30) )
            cout << res << '\n';
        else
            cout << "-1\n";
    }

    return 0;
}