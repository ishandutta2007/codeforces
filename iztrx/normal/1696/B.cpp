#include<bits/stdc++.h>
using namespace std;
#define N 1000005
#define ll long long
int T,n,i,j,ans,z,cc,a[N];
int main(){
	cin>>T;
	while(T--){
		cin>>n;ans=cc=0;
		for(i=1;i<=n;++i){
			cin>>a[i],ans+=a[i]==0;
		}
		for(i=1;i<=n;++i){
			if(a[i]&&a[i-1]==0)++cc;
		}
		if(ans==n)cout<<"0\n";
		else if(cc==1)cout<<"1\n";
		else cout<<"2\n";
	}
}