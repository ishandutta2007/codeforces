#include<bits/stdc++.h>
using namespace std;
int i,j,k,n,m,l,r,a[110];
int T;
int main(){
	cin>>T;
	while(T--){
		cin>>n>>l>>r>>k;
		for(i=1;i<=n;i++)cin>>a[i];
		sort(a+1,a+1+n);
		int b=0;
		for(i=1;i<=n;i++){
			if(a[i]>=l){
				if(a[i]>r)continue;
				if(k>=a[i])k-=a[i],++b;
//				break;
			}
		}cout<<b<<endl;
	}
	return 0;
}