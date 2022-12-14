#include<bits/stdc++.h>
using namespace std;
#define mod 998244353
#define ll long long
#define N 1000005
#define pb push_back
#define db double
#define ls (k<<1)
#define rs (k<<1|1)
#define fl cout.flush();
int n,T,a[N],i,now,ans,j,l,r,mid;
int main(){
	cin>>n;
	l=2;r=n;a[0]=a[n+1]=1e9;
	if(n<=100){
		for(i=1;i<=n;++i)cout<<"? "<<i<<"\n",cin>>a[i],fl
		for(i=1;i<=n;++i)if(a[i]<a[i+1]&&a[i]<a[i-1])return cout<<"! "<<i,0;
	}
	cout<<"? 1\n";fl
	cin>>a[1];
	cout<<"? 2\n";fl
	cin>>a[2];
	if(a[1]<a[2])return cout<<"! 1",0;
	while(l<r){
		mid=r-(r-l>>1);
		cout<<"? "<<mid<<"\n";fl
		cin>>now;
		if(now>a[l])r=mid-1;
		else{
			a[mid]=now;
			if(!a[mid-1]){
				cout<<"? "<<mid-1<<"\n";fl
				cin>>a[mid-1];
			}
			if(a[mid-1]<a[mid])r=mid-1;
			else l=mid;
		}
	}
	cout<<"! "<<l;
	return 0;
}