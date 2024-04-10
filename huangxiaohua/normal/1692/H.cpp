#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,a[200500];

int main(){
	ios::sync_with_stdio(0);
	cin>>t;
	while(t--){
		int res=-1,l,r;
		map<int,int> lst,f;
		cin>>n;
		for(i=1;i<=n;i++){
			cin>>a[i];k=a[i];
			f[k]-=(i-lst[k]-1);
			f[k]=max(f[k],0);
			f[k]++;
			lst[k]=i;
			if(f[k]>res){
				res=f[k];r=i;
			}
		}
		int sb=0;
		for(l=r;;l--){
			if(a[l]==a[r])sb++;
			else sb--;
			if(sb==res)break;
		}
		cout<<a[r]<<' '<<l<<' '<<r<<'\n';
	}
}