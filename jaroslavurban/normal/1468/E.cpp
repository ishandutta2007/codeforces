#include<bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

main(){
	cin.tie(0);ios::sync_with_stdio(0);
	int tc;cin>>tc;
	while(tc--){
		int a[4];
		for(int i=0;i<4;++i)cin>>a[i];
		sort(a,a+4);
		int res=0;
		do{
			res=max(res,min(a[0],a[1])*min(a[2],a[3]));
		}while(next_permutation(a,a+4));
		cout<<res<<endl;
	}
}