#define _USE_MATH_DEFINES
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	int tc;cin>>tc;
	while(tc--){
		int n;cin>>n;
		int res=0,ln=0;
		int nn=n,frst=0,mul=1;
		while(nn){
			++ln;
			frst=nn;
			nn/=10;
			mul*=10;
		}
		mul/=10;
		res=9*(ln-1);
		int add=frst;
		for(int i=mul;i>=1;i/=10)if(n/i%10==frst)continue;
		else if(n/i%10>frst)break;
		else {--add;break;}
		cout<<res+add<<endl;
	}
}