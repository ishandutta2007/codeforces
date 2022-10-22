#include<bits/stdc++.h>
using namespace std;
int n,k;
int ans=0;
void work(){
	ans=0;
	cin>>n>>k;
	for(int i=1;i<=n;++i){
		int x;
		cin>>x;
		if(x<=k&&i>k)ans++;
	}
	cout<<ans<<endl;
}
int main(){
	int T;
	cin>>T;
	while(T--)work();
	return 0;
}