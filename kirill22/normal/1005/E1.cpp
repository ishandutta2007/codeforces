#include <bits/stdc++.h>
using namespace std;
int a[200001];
map<int,long long> val;
int main(){
	int i,n,m,loc;
	cin>>n>>m;
	for(i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==m){
			loc=i;
		}
	}
	int s=1;
	long long ans=0;
	for(i=loc;i>0;i--){
		if(a[i]>m){
			s++;
		} else{
			s--;
		}
		val[s]++;
	}
	s=-1;
	for(i=loc;i<=n;i++){
		if(a[i]>m){
			s--;
		} else {
			s++;
		}
		ans+=val[s]+val[s+1];
	}
	cout<<ans;
}