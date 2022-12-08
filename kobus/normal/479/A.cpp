#include <bits/stdc++.h>
 
using namespace std;
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define int long long
typedef long long ll;
typedef pair<int,int>pii;
#define MAXN 212345
#define INF numeric_limits<ll>::max()
#define MOD 998244353
#define eps 1e-15
#define eeps
#define cood long double

int v[112];

int32_t main(){
    cout.precision(12);
    cout.setf(ios::fixed);
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a,b,c;
    cin>>a>>b>>c;
    int resp=a*b*c;
    resp=max(resp,(a+b)*c);
    resp=max(resp,(c+b)*a);
    resp=max(resp,a+b+c);
    resp=max(resp,(a*b)+c);
    resp=max(resp,(c*b)+a);
    cout<<resp<<endl;


}