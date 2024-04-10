#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t;
int res[100500],a[100500];

int main() {
    ios::sync_with_stdio(0);
    cin>>t;
    while(t--){
    	cin>>n>>m;
    	for(i=1;i<=n;i++){
    		cin>>a[i];
    		res[i]=0;
		}
		k=0;
		for(i=n;i>=1;i--){
			if(k<a[i]){
				if(k<m){
					k++;res[i]=1;
				}
			}
			else res[i]=1;
		}
		for(i=1;i<=n;i++)cout<<res[i];
		cout<<'\n';
	}
}