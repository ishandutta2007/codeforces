#include <bits/stdc++.h>
#define maxn 200010
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
int n,a[maxn];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.setf(ios::fixed); cout.precision(0);

    //freopen("a.in","r",stdin);
    //freopen("a.out","w",stdout);

    cin >> n;

    for(int i=1; i<=n; i++)
        cin >> a[i];

    sort( a + 1 , a + n + 1 );

    int day = 0;
    for(int i=1; i<=n; i++)
        if( a[i] >= day + 1 )
            day++;

    cout << day << '\n';

    return 0;
}