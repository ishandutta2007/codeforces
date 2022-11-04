#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
#define int ll

const int N=200100;
int a[N];
main(){
	cin.tie(0);cin.sync_with_stdio(0);
	int n;cin>>n;
	int res=0;
	for(int i=1;i<=n;++i)cin>>a[i];
	for(int i=0;i<=n;++i)a[i+1]+=a[i];
	set<int>got;
	int prev=0;
	for(int i=0;i<=n;++i){
		if(got.count(a[i]-a[prev])){
			++res;got.clear();got.insert(0);prev=i-1;
		}got.insert(a[i]-a[prev]);
	}
	cout<<res<<endl;
}