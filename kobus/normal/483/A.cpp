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

int32_t main(){
    cout.precision(12);
    cout.setf(ios::fixed);
    ios::sync_with_stdio(false);
    cin.tie(0);

    int l,r;
    cin>>l>>r;
    for(int i=l;i<=r;i++){
        for(int j=i+1;j<=r;j++){
            for(int k=j+1;k<=r;k++){
                if(i!=j && i!=k && j!=k && gcd(i,j)==1 && gcd(j,k)==1 && gcd(i,k)!=1){
                    cout<<i<<" "<<j<<" "<<k<<endl;
                    return 0;
                }
            }
        }
    }
    cout<<-1<<endl;

}