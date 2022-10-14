#include<bits/stdc++.h>
#define maxn 200010
#define inf 1000000007
#define ii pair<int,int>
#define f first
#define s second
using namespace std;
typedef long long ll;
typedef long double ld;

int n,a[maxn];
long long ans;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for(int i=1; i<=n; i++)
        cin >> a[i];

    for(int i=n-1; i>0; i--){
        ans += min( a[i] , max( a[i+1] - 1 , 0 ) );
        a[i] = min( a[i] , max( a[i+1] - 1 , 0 ) );
    }

    cout << ans + a[n];

    return 0;
}