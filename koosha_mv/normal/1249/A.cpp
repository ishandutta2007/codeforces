#include<iostream>
using namespace std;
int a[120]={0};
int main(){
	int q,n,x,t;
	cin>>q;
	for(int i=0;i<q;i++){
		cin>>n;
		t=0;
		for(int i1=0;i1<110;i1++)
			a[i1]=0;
		for(int j=0;j<n;j++){
			cin>>x;
			if(a[x+1]==1 || a[x-1]==1)
				t=1;
			a[x]=1;
		}
		if(t==0)
			cout<<1<<endl;
		else
			cout<<2<<endl;
	}
}