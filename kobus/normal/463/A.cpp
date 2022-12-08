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
#define double long double



int32_t main(){
    cout.precision(12);
    cout.setf(ios::fixed);
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n,d;
    cin>>n>>d;
    int resp=-1;
    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        if(a<d && b!=0)resp=max(resp,100-b);
        if(a<=d&&b==0)resp=max(resp,0ll);
    }
    cout<<resp<<endl;


}