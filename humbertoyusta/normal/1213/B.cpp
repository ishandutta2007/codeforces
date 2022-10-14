#include<bits/stdc++.h>
#define maxn 150010
#define inf 1000000007
#define ii pair<int,int>
#define lg2(x) 31 - __builtin_clz(x)
#define db(x) cerr << #x << ": " << (x) << '\n';
using namespace std;
typedef long long ll;

int n, ans, mn, tc, a[maxn];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> tc;
    while( tc-- ){

        cin >> n;
        ans = 0;

        for(int i=1; i<=n; i++)
            cin >> a[i];

        mn = 1000000007;
        for(int i=n; i>0; i--){
            if( a[i] <= mn ) mn = a[i];
                else ans++;
        }

        cout << ans << '\n';
    }

    return 0;
}