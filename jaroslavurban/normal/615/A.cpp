#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int N=110;
int done[N];
int n,m;

main(){
	cin.tie(0);cin.sync_with_stdio(0);
	cin>>n>>m;
	for(int i=0;i<n;++i){
		int mi;cin>>mi;
		for(int j=0;j<mi;++j)
			{int tmp;cin>>tmp;done[tmp]=true;}
	}
	for(int i=1;i<=m;++i)if(!done[i]){cout<<"NO\n";return 0;}
	cout<<"YES\n";
}