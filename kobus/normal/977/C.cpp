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

    int n,k;
    cin>>n>>k;
    vector<int> v;
    for(int i=0;i<n;i++){
    	int x;
    	cin>>x;
    	v.pb(x);
    }
    sort(v.begin(),v.end());
    if(k==0){
    	if(v[0]==1)cout<<-1<<endl;
    	else cout<<1<<endl;
    	return 0;
    }
    if(k==n){
    	cout<<v[n-1]<<endl;
    	return 0;
    }
    if(v[k-1]==v[k])cout<<-1<<endl;
    else cout<<v[k-1]<<endl;
   
    return 0;
 
}