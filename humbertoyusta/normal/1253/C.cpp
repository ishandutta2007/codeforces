#include<bits/stdc++.h>
#define inf 1000000007
#define f first
#define s second
#define maxn 200010
using namespace std;
typedef pair<int,int> ii;

int a[maxn];
long long sum[maxn], sm[maxn];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    for(int i=1; i<=n; i++)
        cin >> a[i];
    sort( a + 1 , a + n + 1 );

    for(int i=1; i<=n; i++)
        sum[i] = sum[i-1] + a[i];

    long long ans = 0;
    for(int i=1; i<=n; i++){
        sm[ i % m ] += a[i];
        ans = ans + sm[ i % m ];
        cout << ans << ' ';
    }

    return 0;
}