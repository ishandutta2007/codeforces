#include<bits/stdc++.h>
using namespace std;
int n,m;
void work(){
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			int x;
			cin>>x;
			cout<<(x+(x%2!=(i+j)%2))<<" ";
		}
		cout<<endl;
	}
}
int main(){
	int T;
	cin>>T;
	while(T--)work();
	return 0;
}