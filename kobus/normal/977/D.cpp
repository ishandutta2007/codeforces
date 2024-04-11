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

    int n;
    cin>>n;
    vector<pair<pii,int>> v;
    for(int i=0;i<n;i++){
    	int x;
    	cin>>x;
    	pair<pii,int> pp;
    	pp.s=x;
    	while(x%2==0){
    		x=x/2;
    		pp.f.f++;
    	}
    	while(x%3==0){
    		x=x/3;
    		pp.f.s--;
    	}
    	v.pb(pp);
    }
    sort(v.begin(),v.end());
    for(auto x:v)cout<<x.s<<" ";
    cout<<endl;
   
    return 0;
 
}