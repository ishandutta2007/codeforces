#include<bits/stdc++.h>
#define maxn 200010
#define inf 1000000007
#define ii pair<int,int>
#define f first
#define s second
#define db(x) cerr << #x << ": " << (x) << '\n';
#define lg2(x) 31 - __builtin_clz(x)
using namespace std;
typedef long long ll;
typedef long double ld;

int n,b,a;
bool arr[maxn];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.setf(ios::fixed); cout.precision(0);

    //freopen("a.in","r",stdin);
    //freopen("a.out","w".stdout);

    cin >> n >> b >> a;

    for(int i=1; i<=n; i++)
        cin >> arr[i];

    int cb = b , ca = a;
    for(int i=1; i<=n; i++){
        if( arr[i] ){
            if( ca < a && cb ){ cb--; ca++; continue; }
            if( ca ){ ca--; continue; }
            cout << i-1; return 0;
        }
        else{
            if( ca ){ ca--; continue; }
            if( cb ){ cb--; continue; }
            cout << i-1; return 0;
        }
        return 0;
    }

    cout << n << '\n';

    return 0;
}