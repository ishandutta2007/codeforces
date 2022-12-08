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

    int t;
    cin>>t;
    while(t--){
    	int n,m,k;
    	cin>>n>>m>>k;
    	int ma=max(n,m);
    	int mi=min(n,m);
    	if((ma%2)!=(mi%2)){ma--;k--;}
    	else if((ma%2)!=(k%2)){ma--;mi--;k-=2;}
    	if(k<ma)cout<<-1<<endl;
    	else cout<<k<<endl;

    }
   
    return 0;
 
}