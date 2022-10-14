#include<bits/stdc++.h>
#define maxn 200010
#define inf 1000000007
#define  f first
#define s second
#define lg2(x) 31 - __builtin_clz(x)
#define db(x) cerr << #x << ": " << (x) << '\n';
#define int long long
using namespace std;
typedef long double ld;
typedef pair<int,int> ii;

int a[505], n, k;

ii guess(){
    cout << "? ";
    for(int i=1; i<k; i++)
        cout << a[i] << ' ';
    cout << a[k] << '\n';
    cout.flush();
    ii reso;
    cin >> reso.f >> reso.s;
    return reso;
}

void print(int u){
    cout << "! " << u << '\n';
    cout.flush();
    exit(0);
}

int32_t main(){
    ios_base::sync_with_stdio(0);  cin.tie(0);
    cout.setf(ios::fixed);  cout.precision(0);

    //freopen("a.in","r",stdin);

    cin >> n >> k;

    for(int i=1; i<=k; i++)
        a[i] = i;

    ii s = guess();
    int ans = 0;

    bool flag = 1;
    for(int i=1; i<=k; i++){
        a[i] = k + 1;
        ii u = guess();
        a[i] = i;
        if( u.f != s.f ) ans++;
        if( u.s <  s.s ) flag = 0;
    }

    if( flag ) print(ans);
        else print(k+1-ans);

    return 0;
}