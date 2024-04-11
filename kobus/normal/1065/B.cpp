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

int min(int n,int m){
    if(m>=(n+1)/2)return 0;
    else if(m==0)return n;
    else{
        return n-2*m;
    }
}

int32_t main(){
    cout.precision(12);
    cout.setf(ios::fixed);
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n,m;
    cin>>n>>m;
    if(m==0){
        cout<<n<<" "<<n<<endl;
        return 0;
    }

    cout<<min(n,m)<<" ";
    int resp=0;
    for(int i=1;i<=n;i++){
        int maxi=(i*(i-1))/2;
        if(m<=maxi && min(i,m)==0)resp=max(resp,n-i);
    }
    cout<<resp<<endl;
}