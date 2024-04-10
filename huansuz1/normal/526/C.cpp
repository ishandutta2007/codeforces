#include <algorithm>
#include <iostream>
#include <string>
#include <cstdio>
#include <cmath>
#include <vector>



using namespace std;

long long n,w1,w2,r1,r2,ans;

int main(){
	cin>>n>>w1>>w2>>r1>>r2;
	ans=((n/r1)*w1)+(((n%r1)/r2)*w2);

	long long nn=n;
	for(int i=0; i<10000000; i++)  {
		
		if (n<0) break;
		long long k=(n/r2);
		long long s=i*w1;
		if (n%r2>=r1) s+=((n%r2)/r1)*w1; 
		s+=(k*w2);
		ans=max(ans,s);
		n-=r1;
	}
	n=nn;
	swap(r1,r2);
	swap(w1,w2);

	for(int i=0; i<10000000; i++)  {
		
		if (n<0) break;
		long long k=(n/r2);
		long long s=i*w1;
		if (n%r2>=r1) s+=((n%r2)/r1)*w1; 
		s+=(k*w2);
		ans=max(ans,s);
		n-=r1;
	}

	cout<<ans;
		


}