#include<iostream>
#include<algorithm>
using namespace std;
long long a[100002],sa=0;
int main(){
	long long n,x1,x2;
	cin>>n;
	cin>>x2;
	for(long long i=0;i<n-1;i++){
		cin>>x1;
		a[sa]=abs(x1-x2);
		sa++;
		x2=x1;
	}
//	for(long long i=0;i<sa;i++){
//		cout<<a[i]<<" ";
//	}
//	cout<<endl;
	for(long long i=0;i<sa;i+=2){
		a[i]=a[i]*-1;}
//	for(long long i=0;i<sa;i++)
//		cout<<a[i]<<" ";
	long long p1=0,p2=0,sum=0,mx=0,am;
	while(p2<sa && p1<sa){
	//	cout<<p1<<" "<<p2<<" "<<sum<<endl;
		if(sum>=0){
			mx=max(mx,sum);
			sum+=a[p2];
			p2++;
			mx=max(mx,sum);
		}
		else{
			p1=p2;
			sum=0;
		}
	}
	am=mx;
	for(long long i=0;i<sa;i++){
		a[i]=a[i]*-1;}
	//for(long long i=0;i<sa;i++)
	//	cout<<a[i]<<" ";
	p1=0,p2=0,sum=0,mx=0;
	while(p2<sa && p1<sa){
	//	cout<<p1<<" "<<p2<<" "<<sum<<endl;
		if(sum>=0){
			mx=max(mx,sum);
			sum+=a[p2];
			p2++;
			mx=max(mx,sum);
		}
		else{
			p1=p2;
			sum=0;
		}
	}
	cout<<max(am,mx);
}