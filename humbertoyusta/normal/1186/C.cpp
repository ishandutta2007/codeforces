#include<bits/stdc++.h>
#define maxn 1000010
#define inf 1000000007
#define f first
#define s second
#define lg2(x) 31 - __builtin_popcount(x)
#define db(x) cerr << #x << ": " << (x) << '\n';
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;

string a, b;
int cnt, ch, ans;

int main(){
    ios_base::sync_with_stdio(0);  cin.tie(0);
    cout.setf(ios::fixed);  cout.precision(0);

    cin >> a >> b;

    for(int i=0; i<b.size(); i++)
        if( a[i] != b[i] )
            cnt = ( cnt + 1 ) % 2;

    for(int i=1; i<b.size(); i++)
        ch = ( ch + ( b[i] != b[i-1] ) ) % 2;

    ans += ( cnt == 0 );

    for(int i=b.size(); i<a.size(); i++){
        if( a[i-b.size()] != b[0] )
            cnt = ( cnt + 1 ) % 2;
        if( a[i] != b[b.size()-1] )
            cnt = ( cnt + 1 ) % 2;
        cnt = ( cnt + ch ) % 2;
        ans += ( cnt == 0 );
    }

    cout << ans << '\n';

    return 0;
}