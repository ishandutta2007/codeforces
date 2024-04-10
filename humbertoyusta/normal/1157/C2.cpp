#include<bits/stdc++.h>
#define inf 1000000007
#define f first
#define s second
using namespace std;
typedef pair<int,int> ii;

int a[200005];

int stl(int lef,int rit){
    int res = 0;
    if( lef > rit ) return 0;
    if( a[lef] > a[lef-1] ) return 1 + stl(lef+1,rit);
    return 0;
}

int str(int rit,int lef){
    int res = 0;
    if( lef > rit ) return 0;
    if( a[rit] > a[rit+1] ) return 1 + str(rit-1,lef);
    return 0;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;

    for(int i=1; i<=n; i++)
        cin >> a[i];

    int l = 1, r = n, mx = 0;
    string ans;

    while( l <= r ){
        if( a[l] < a[r] && mx < a[l] ){ ans += "L"; mx = max( mx , a[l] ); l++; continue; }
        if( a[r] < a[l] && mx < a[r] ){ ans += "R"; mx = max( mx , a[r] ); r--; continue; }
        if( ( stl(l+1,r) >= str(r-1,l) && mx < a[l] ) || ( mx < a[l] && mx >= a[r] ) ){
                for(int i=0; i<=stl(l+1,r); i++)
                    ans += "L";
        }
        else
            if( mx < a[r] )
                for(int i=0; i<=str(r-1,l); i++)
                    ans += "R";
        break;
    }

    cout << ans.size() << '\n';
    for( auto i : ans )
        cout << i;
    cout << '\n';

    return 0;
}