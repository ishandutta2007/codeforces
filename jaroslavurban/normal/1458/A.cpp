#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;


const int N=200100;
int n,m;
ll a[N],b[N];

main(){
	cin.tie(0);cin.sync_with_stdio(0);
	cin>>n>>m;
	for(int i=0;i<n;++i)cin>>a[i];
	for(int i=0;i<m;++i)cin>>b[i];
	sort(a,a+n);
	for(int i=1;i<n;++i)a[i]-=a[0];
	ll gc=a[1];
	for(int i=1;i<n;++i)gc=__gcd(gc,a[i]);
	for(int i=0;i<m;++i)cout<<__gcd(a[0]+b[i],gc)<<" ";cout<<endl;
}