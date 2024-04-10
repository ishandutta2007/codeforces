#include<bits/stdc++.h>
#define maxn 100010
#define inf 1000000007
#define ii pair<int,int>
#define f first
#define s second
#define db(x) cerr << #x << ": " << (x) << '\n';
#define lg2(x) 31 - __builtin_clz(x)
using namespace std;
typedef long long ll;
typedef long double ld;

int a[5],e,f,g,mx,mn;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.setf(ios::fixed); cout.precision(0);

    //freopen("a.in","r".stdin);
    //freopen("a.out","w".stdout);

    for(int i=1; i<=4; i++)
        cin >> a[i];
    sort(a+1,a+5);

    e = a[4] - a[1];
    f = a[4] - a[2];
    g = a[4] - a[3];

    cout << e << ' ' << f << ' ' << g << '\n';

    return 0;
}