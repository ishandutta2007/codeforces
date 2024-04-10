#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,t,m,a[100500],b[100500],mx;
ll res;

int main(){
	ios::sync_with_stdio(0);
	cin>>t;
	while(t--){
		cin>>n>>m;
		res=0;
		for(i=1;i<=n;i++){
			cin>>k;
			a[k]=i;
		}
		mx=0;res=0;
		for(i=1;i<=m;i++){
			cin>>k;
			if(mx<a[k]){
				res+=a[k]*2-i*2+1;
				mx=a[k];
			}
			else{
				res++;
			}
		}
		cout<<res<<'\n';
	}
}