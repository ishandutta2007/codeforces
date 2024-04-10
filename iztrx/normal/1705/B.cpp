#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define N 1000005
int T,n,x,i,qwq,a[N];
ll sum;
int main(){
	ios::sync_with_stdio(0); 
	cin>>T;
	while(T--){
		cin>>n;x=0;qwq=0;
		for(i=1;i<=n;++i){
			cin>>a[i];
			if(!x&&a[i])x=i;
		}sum=0;
		if(!x)x=n;
		for(i=x;i<n;++i){
			sum+=a[i];
			if(!a[i])++sum;
		}
		cout<<sum<<"\n";
	}
}