#include<bits/stdc++.h>
using namespace std;


int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t;
	cin>>t;
	while(t--){
		vector<int> v(3);
		for(int i=0;i<3;i++)cin>>v[i];
		for(int i=0;i<3;i++){
			int val=0;
			for(int j=0;j<3;j++)if(j!=i)val=max(val,v[j]);
			cout<<max(val+1-v[i],0)<<" ";
		}
		cout<<endl;
	}
}