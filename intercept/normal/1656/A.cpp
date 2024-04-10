#include<bits/stdc++.h>
using namespace std;
int n;
void work(){
	cin>>n;
	int ma=-2e9,mi=2e9,p1=0,p2=0;
	for(int i=1;i<=n;++i){
		int x;
		cin>>x;
		if(x>ma)ma=x,p1=i;
		if(x<mi)mi=x,p2=i;
	}
	cout<<p1<<" "<<p2<<endl;
}
int main(){
	int T;
	cin>>T;
	while(T--)work();
	return 0;
}