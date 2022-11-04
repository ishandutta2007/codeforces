#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int N=200100,inf=1e9;
int a[N];
int n;

main(){
	cin.tie(0);cin.sync_with_stdio(0);
	int tt;cin>>tt;
	while(tt--){
		cin>>n;
		for(int i=0;i<n;++i)cin>>a[i];
		int nodes=1,children=0;
		int res=0;
		for(int i=0;i<n-1;++i){ // check this
			if(a[i]>a[i+1]&&!--nodes){
				++res;
				nodes=children;
				children=0;
			}
			++children;
		}
		cout<<res+!!(n>1)<<endl;
	}
}