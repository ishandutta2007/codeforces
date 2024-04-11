#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define f first
#define s second
#define int long long
typedef long long ll;
typedef pair<int,int> pii;
typedef long double ld;
#define MAXN 512345
#define INF LLONG_MAX
#define MOD 32416187567
#define cte 10002
#define MAX ULLONG_MAX

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(1);
    cout.setf(ios::fixed);
    
    int k,n,s,p;
    cin>>k>>n>>s>>p;

    int spp=(n+s-1)/s;

    //cout<<spp<<endl;

    cout<<(spp*k+p-1)/(p)<<endl;

    return 0;

}