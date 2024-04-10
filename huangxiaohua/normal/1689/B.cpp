#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,a[10050],b[10050],res[10050];

int main(void){
    ios::sync_with_stdio(0);
    cin>>t;
    while(t--){
    	cin>>n;
    	for(i=1;i<=n;i++){
    		cin>>a[i];
    		b[i]=0;
		}
		if(n==1){
			cout<<"-1\n";
			continue;
		}
		for(i=1;i<n;i++){
			for(j=1;;j++){
				if(j==a[i]||b[j])continue;
				b[j]=1;
				res[i]=j;break;
			}
		}
		for(i=1;;i++){
			if(!b[i]){
				res[n]=i;break;
			}
		}
		if(a[n]==res[n])swap(res[n-1],res[n]);
		for(i=1;i<=n;i++)cout<<res[i]<<' ';
		cout<<'\n';
	}
}