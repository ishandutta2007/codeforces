#include <bits/stdc++.h>
using namespace std; 
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n,t,lid=1,rid=1;
	cin>>n;
	map<int,int>id;
	char c;
	for(int i=0;i<n;i++){
		cin>>c>>t;
		if(c=='L'){
			id[t]=lid*-1;
			lid++;
		}
		else if(c=='R'){
			id[t]=rid;
			rid++;
		}
		else{
			if(id[t]<0)cout<<min(lid-1-id[t]*-1,(lid+rid-3)-(lid-1-id[t]*-1))<<endl;
			else cout<<min(rid-1-id[t],(lid+rid-3)-(rid-1-id[t]))<<endl;
		}
	}
	return 0;
}