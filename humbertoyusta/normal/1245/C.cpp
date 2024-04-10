#include<bits/stdc++.h>
#define int long long
#define mod 1000000007
#define maxn 100010
#define ii pair<int,int>
#define f first
#define s second
using namespace std;

int fib[maxn], u[maxn], n[maxn], ans = 1;
string a;

main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    fib[0] = 1;
    fib[1] = 1;
    for(int i=2; i<maxn; i++)
        fib[i] = ( fib[i-1] + fib[i-2] ) % mod;

    cin >> a;

    for(int i=0; i<a.size(); i++){
        if( a[i] == 'w' || a[i] == 'm' ){ cout << 0; return 0; }
        if( a[i] == 'u' ) u[i] = u[max(0ll,i-1)] + 1;
        if( a[i] == 'n' ) n[i] = n[max(0ll,i-1)] + 1;
    }

    a = a + '$';

    for(int i=0; i<a.size()-1; i++){
        if( a[i] == 'u' && a[i+1] != 'u' ) ans = ( ans * fib[u[i]] ) % mod;
        if( a[i] == 'n' && a[i+1] != 'n' ) ans = ( ans * fib[n[i]] ) % mod;
    }

    cout << ans << '\n';

    return 0;
}