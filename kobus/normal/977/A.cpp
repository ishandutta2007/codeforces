#include <bits/stdc++.h>
using namespace std;
 
#define pb push_back
#define MAXN 112
#define INF LLONG_MAX
#define double long double
#define int long long
#define pii pair<long long,long long>
#define f first
#define s second
#define mp make_pair
#define eps 1e-11
#define pi acos(-1)
#define MOD 1000000007


int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(9);
    cout.setf(ios::fixed);

    int x,n;
    cin>>x>>n;
    for(int i=0;i<n;i++){
    	if(x%10==0)x=x/10;
    	else x--;
    }
    cout<<x<<endl;
 
    
   
    return 0;
 
}