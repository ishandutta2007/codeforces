#include<bits/stdc++.h>
using namespace std;
long long lft,rit,x,Testing,l,r,ans1,ans2,ans3,mid,n;
long long ask(long long l,long long r){
	cout<<"? "<<l<<" "<<r<<endl;
	cin>>x;
	return x;
}
long long calc(long long x){
	return x*(x-1)/2;
}
int main(){
	cin>>Testing;
	for (;Testing;Testing--){
		cin>>n;
		l=1;r=n;ans1=0;ans2=0;ans3=0;
		while (l<=r){
			mid=(l+r)/2;
			if (ask(1,mid)==0) {
				ans1=mid;l=mid+1;
			}
		else r=mid-1;
		}
	rit=ask(ans1,n);lft=ask(ans1+1,n);
	ans2=ans1+rit-lft+1;
	//cout<<"------"<<ans2<<" "<<ans1<<" "<<lft<<" "<<rit<<"-----\n";
	rit=ask(ans2,n);lft=ask(ans2+1,n);
	ans3=ans2+rit-lft;
	  cout<<"! "<<ans1<<" "<<ans2<<" "<<ans3<<endl;
	}
return 0;
}