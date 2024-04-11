#include<iostream>
using namespace std;
int a[300009];
int main(){
	int s,t,mxtool=0,n,k,p1=0,p2=0,t0=0;
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	while(p2<=n){
		//cout<<p1<<" "<<p2<<" "<<t0<<endl;
		if(t0<=k){
			if(p2-p1>mxtool){
				mxtool=p2-p1;
				s=p1,t=p2;
			}
			t0+=a[p2]*-1+1;
			p2++;
		}
		else{
			t0-=a[p1]*-1+1;
			p1++;
		}
	}
	cout<<mxtool<<endl;
	for(int i=0;i<n;i++){
		if(i>=s && i<t)
			cout<<1<<" ";
		else
			cout<<a[i]<<" ";
	}
}