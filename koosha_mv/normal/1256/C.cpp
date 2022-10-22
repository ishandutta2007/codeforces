#include<iostream>
using namespace std;
int pl[1000];
print(int x,int n){
	for(int i=0;i<x;i++){
		cout<<n<<" ";
	}
}
int main(){
	int n,m,d,sum=0,ez,t=0;
	cin>>n>>m>>d;
	for(int i=0;i<m;i++){
		cin>>pl[i];
		sum+=pl[i]-1;
	}
	if(sum+(m+1)*d<n+1) {cout<<"NO"; return 0;}
	cout<<"YES"<<endl;ez=(sum+(m+1)*d)-n-1;
	//cout<<ez<<endl;
	int k=0,apl=0,l;
	while(t<n){
		l=min(ez,d-1);
		//cout<<d-1-l<<endl;
		for(int i=0;i<d-1-l;i++){
			cout<<'0'<<" ";}
		t+=d-1-l;
		ez-=l;
		for(int i=0;i<pl[apl];i++){
			cout<<apl+1<<" ";}
		t+=pl[apl];
		apl++;
	}
	
}