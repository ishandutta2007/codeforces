#include<bits/stdc++.h>
#define R register int 
using namespace std;
int n,k,a[111000],s,ans[111000];
int main()
{
	cin>>n>>k;
	for(R i=1;i<=n;i++){
		cin>>a[i];
		s+=a[i];
	}
	if(s%k!=0){
		cout<<"No";
		return 0;
	}
	int t=s/k;
	int cnt=0;
	for(R i=1;i<=n;){
		int sum=0,tmp=0;
		while(sum<t){
			sum+=a[i];
			i++;
			tmp++;}
		if(sum!=t){
			cout<<"No";
			return 0;
		}
		ans[++cnt]=tmp;
	}
	cout<<"Yes"<<endl;
	for(R i=1;i<=cnt;i++)
		cout<<ans[i]<<' ';
	return 0;
}