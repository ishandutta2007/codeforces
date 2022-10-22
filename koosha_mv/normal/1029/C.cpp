#include<iostream>
using namespace std;
int a[300099][2];
int f(int x){
	if(x<0)
		return 0;
	return x;}
int main(){
	int jx=0,jy=0,mxx,mxx2=-1,mny,mny2=1e9+100,n,x,y;cin>>n;
	cin>>x>>y;
	mxx=x,mny=y,a[0][0]==x,a[0][1]=y;	
	for(int i=1;i<n;i++){
		cin>>x>>y;
		a[i][0]==x,a[i][1]=y;	
		if(x>mxx)
			mxx2=mxx,mxx=x,jx=i;
		else
			mxx2=max(mxx2,x);
		if(y<mny)
			mny2=min(mny2,mny),mny=y,jy=i;
		else
			mny2=min(mny2,y);
	}
	//cout<<mny2<<" "<<mxx<<"  "<<mny<<" "<<mxx2<<endl;
	if(jx==jy){
		cout<<f(mny2-mxx2);
		//cout<<10;
		return 0;}
	if(mxx==mxx2){
		cout<<f(mny2-mxx);
		return 0;//cout<<100;
	}
	if(mny==mny2){
		cout<<f(mny-mxx2);//cout<<1000;
		return 0;
	}
	cout<<f(max(mny2-mxx,mny-mxx2));
}