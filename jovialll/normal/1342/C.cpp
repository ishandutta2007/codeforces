#include<bits/stdc++.h>
using namespace std;
#define int long long
int t,a,b,q,f,s[100005];
inline int cal(int x){
	return s[f]*(x/f)+s[x%f];
}
int x,y,i;
signed main(){
	cin>>t;
	while(t--){
		cin>>a>>b>>q;
		f=a*b;
		for(i=1;i<=f;++i){
			s[i]=s[i-1]+((i%a)%b!=(i%b)%a);
		}
		while(q--){
			cin>>x>>y;
			cout<<cal(y)-cal(x-1)<<" ";
		}
		cout<<"\n";
	}
	return 0;
}