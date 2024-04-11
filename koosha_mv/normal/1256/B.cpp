#include<iostream>
using namespace std;
int a[1009];
int main(){
	int q,n;
	cin>>q;
	for(int p=0;p<q;p++){
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		int r=1,mn=1000,am,gh=0,t=0;
		while(1){
			mn=1000;
			for(int i=gh;i<n;i++){
				if(a[i]<mn){
					mn=a[i];
					am=i;}
			}
			cout<<mn<<" ";t++;
			for(int i=gh;i<am-1;i++){
				cout<<a[i]<<" ";t++;
			}
			if(am==gh){
				gh=am+1;
				
			}
			else{
			a[am]=a[am-1];
			gh=am;
			}
			if(t==n)
				break;
		}
	}
}