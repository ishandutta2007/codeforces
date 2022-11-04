#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

int calc(vector<int>a){
	int mn=0;
	int sm=0;
	for(int i=0;i<a.size();++i)mn=min(mn,sm+=a[i]);
	return int(a.size())/2+mn;
}

main(){
	cin.tie(0);cin.sync_with_stdio(0);
	int tc;cin>>tc;
	while(tc--){
		int n;cin>>n;
		vector<int>a(2*n,1);
		for(int i=0;i<n;++i){int aa;cin>>aa;a[aa-1]=-1;}
		int mxsuf=calc(a);
		reverse(a.begin(),a.end());
		int mxpref=calc(a);
		cout<<max({mxpref-(n-mxsuf)+1,mxsuf-(n-mxpref)+1,0})<<endl;
	}
}