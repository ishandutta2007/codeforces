#include<bits/stdc++.h>
#define maxn 300010
#define inf 1000000007
#define ii pair<int,int>
#define f first
#define s second
#define db(x) cerr << #x << ": " << (x) << '\n';
#define lg2(x) 31 - __builtin_clz(x)
using namespace std;
typedef long long ll;
typedef long double ld;

int n,m,q;
ll a[maxn],sum;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.setf(ios::fixed); cout.precision(0);

    //freopen("a.in","r",stdin);
    //freopen("a.out","w",stdout);

    cin >> n;

    for(int i=1; i<=n; i++){
        cin >> a[i];
        sum += a[i];
    }

    sort(a+1,a+n+1);
    reverse(a+1,a+n+1);

    cin >> q;

    for(int i=1; i<=q; i++){
        cin >> m;
        cout << sum - a[m] << '\n';
    }

    return 0;
}