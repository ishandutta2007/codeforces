#include<iostream>
#include<algorithm>
using namespace std;
int a[100002],b[100002];
int main(){
	int n,x,y,p1=0,p2=0,t=0;
	cin>>n>>x;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		cin>>b[i];
	}
	p2=0;p1=n-1;
	sort(a,a+n);
	sort(b,b+n);
	while(p2<n && p1>=0){
		if(a[p1]+b[p2]>=x){
			p1--;
			t++;
			p2++;
		}
		else{
			p2++;
		}
	}
	cout<<1<<" "<<t;
}