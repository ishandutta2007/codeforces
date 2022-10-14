#include <bits/stdc++.h>
#define maxn 100010
#define inf 1000000007
#define f first
#define s second
#define lg2(x) ( 31 - __builtin_clz(x) )
#define db(x) cerr << #x << ": " << (x) << "\n";
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;

string s;
int n,a,b,ans;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.setf(ios::fixed); cout.precision(0);

    //freopen("a.in","r",stdin);
    //freopen("a.out","w",stdout);

    cin >> n >> a >> b;
    cin >> s;

    reverse(s.begin(),s.end());

    for(int i=0; i<a; i++)
        if( i == b ) ans += ( s[i] == '0' );
            else ans += ( s[i] == '1' );

    cout << ans << '\n';

    return 0;
}