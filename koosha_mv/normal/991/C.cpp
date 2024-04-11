#include<iostream>
using namespace std;
long long n,l,r,mid,m,s;
int main(){
	cin>>n;
	l=1;r=n;
	while(l<r){
		mid=(l+r)/2;
		m=n;
		s=0;
		while(m&&s+m>=n/2){
			if(m<=mid){
				s+=m;
				break;
			}
			s+=mid;
			m-=mid;
			m-=m/10;
		}
		if(s*2>=n)
			r=mid;
		else
			l=mid+1;
	}
	cout<<r;
}