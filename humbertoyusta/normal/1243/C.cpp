#include<bits/stdc++.h>
#define maxn 1000005
#define int long long
#define ii pair<int,int>
#define f first
#define s second
#define db(x) cerr<<#x<<": "<<(x)<<'\n';
using namespace std;
typedef long long ll;


main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    long long n, N;
    vector<long long> v;
    cin >> n;
    N = n;

    for(long long i=2; i*i<=n; i++){
        if( n % i == 0 ){
            v.push_back(i);
            while( n % i == 0 )
                n /= i;
        }
    }
    if( n > 1 ){
        if( v.empty() ){
            v.push_back(n);
        }
        else if( v[v.size()-1] != n ){
            v.push_back(n);
        }
    }

    if( v.size() == 1 ){ cout << v[0] << '\n'; return 0; }
    cout << 1 << '\n'; return 0;

    return 0;
}