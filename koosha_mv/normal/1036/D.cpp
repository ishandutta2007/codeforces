#include<iostream>
using namespace std;
long long a[300009],b[300009];
int main(){
	long long n,m,sum1=0,sum2=0;cin>>n;
	for(long long i=0;i<n;i++){
		 scanf ("%ld",&a[i]);sum1+=a[i];}
	cin>>m;
	for(long long i=0;i<m;i++){
		 scanf ("%ld",&b[i]);sum2+=b[i];}
	if(sum1!=sum2){cout<<-1;return 0;}
	long long segment=0,s1=0,s2=0,p1=1,p2=1;sum1=a[0],sum2=b[0];
	while(s1<n){
		//cout<<s1<<" "<<p1<<" &&&& "<<s2<<" "<<p2<<" SUM1: "<<sum1<<" SUM2: "<<sum2<<endl;
		if(sum1==sum2 && sum1!=0){
			segment++;
			s1=p1,s2=p2,sum1=0,sum2=0;
		}
		else{
			if(sum1<sum2){
				sum1+=a[p1],p1++;
			}
			else{
				sum2+=b[p2],p2++;
			}
		}
	}
	cout<<segment;
}