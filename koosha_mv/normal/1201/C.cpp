#include<iostream>
#include<algorithm>
using namespace std;
long long a[200009],l;
int main(){
	long long t=1,n,k,p1;
	cin>>n>>k;
	for(long long i=0;i<n;i++) cin>>a[i];
	p1=n/2;
	sort(a,a+n);
	while(k>0){
		if(t==n/2+1){cout<<a[p1]+k/t;break;}
		l=min(k,(a[p1+1]-a[p1])*t);
		a[p1]+=l/t;
		k-=l;
		t++;
		p1++;
		if(k==0){
			cout<<a[p1-1];
			break;
		}
		
	}
}