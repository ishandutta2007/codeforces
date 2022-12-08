#include <bits/stdc++.h>
 
using namespace std;
#define pb push_back
#define mp make_pair
#define s second
#define int long long
typedef long long ll;
typedef pair<int,int>pii;
#define MAXN 2123456
#define INF numeric_limits<ll>::max()
#define MOD 1000000007
#define eps 1e-15
#define eeps
#define cood long double


int32_t main(){
    cout.precision(12);
    cout.setf(ios::fixed);
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin>>t;
    while(t--){   
        int s,a,b,c;
        cin>>s>>a>>b>>c;
        int bars1=s/c;
        int bars2=b*(bars1/a);
        cout<<bars1+bars2<<endl;
    }

}