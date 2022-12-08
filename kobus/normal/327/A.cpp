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

int gcd(int a,int b){
    return b==0?a:gcd(b,a%b);
}

int v[112];

int32_t main(){
    cout.precision(12);
    cout.setf(ios::fixed);
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin>>n;
    int resp=0;
    for(int i=0;i<n;i++)cin>>v[i];
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            //cout<<i<<" "<<j<<endl;
            int respar=0;
            for(int k=0;k<n;k++){
                if(k>=i&&k<=j)respar+=(1-v[k]);
                else respar+=v[k];
            }
            //cout<<respar<<endl;
            resp=max(resp,respar);
        }
    }
    cout<<resp<<endl;

}