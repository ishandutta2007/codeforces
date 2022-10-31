#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,a[1005000];
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>t;
	while(t--){
		cin>>n;
		memset(a,0,n*4+50);
		for(i=n-1;i>=0;i--){
			if(a[i])continue;
			for(k=1;k*k<i;k++);
			k*=k;
			//printf("NMSL%d %d\n",i,k);
			for(j=max(k-i,0);j<=min(n-1,k);j++){
				if(a[j])break;
				a[j]=k-j;
			}
		}
		for(i=0;i<n;i++){
			cout<<a[i]<<' ';
		}
		cout<<'\n';
	}
}