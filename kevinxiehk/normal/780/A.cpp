#include<iostream>
using namespace std;
bool brainsocks[100002];
int main(){
	int n,cnt=0,t,max=1;
	cin>>n;
	for(int i=1;i<=n*2;i++){
		cin>>t;
		cnt++;
		if(brainsocks[t]==true)cnt-=2;
		else brainsocks[t]=true;
		if(cnt>max)max=cnt;
	} 
	cout<<max<<endl;
	return 0;
}