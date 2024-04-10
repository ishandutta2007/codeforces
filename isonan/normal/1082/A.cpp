#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std;

long long n,a[100001],b[100001],t1,t2,t3,t4;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>t1>>t2>>t3>>t4;
		long long ans=1000000000ll;
		if(abs(t2-t3)%t4==0){
			cout<<(abs(t2-t3)/t4)<<endl;
			continue;
		}
		if(t3%t4==1)ans=min(ans,((t2-1+t4-1)/t4)+((t3-1)/t4));
		if(t3%t4==t1%t4)ans=min(ans,(((t1-t2+t4-1)/t4)+(t1-t3)/t4));
		if(ans==1000000000ll)puts("-1");
		else cout<<ans<<endl;
	}
}