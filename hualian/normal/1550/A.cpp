#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;cin>>t;
	while(t--){
		int x;cin>>x;int ans=0;
		for(int i=1;;i+=2){
			x-=i;ans++;
			if(x<=0)break;
		}
		cout<<ans<<endl;
	}
	return 0;
}