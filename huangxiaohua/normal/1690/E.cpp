#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define M 998244353

int i,j,k,n,m,t,a[1000500];
ll res;

int main(void){
    ios::sync_with_stdio(0);
    cin>>t;
    while(t--){
    	cin>>n>>m;
    	res=0;
    	for(i=1;i<=n;i++){
    		cin>>a[i];
    		res+=a[i]/m;a[i]%=m;
		}
		sort(a+1,a+n+1);
		i=1;j=n;
		while(i<j){
			if(a[i]+a[j]>=m){
				res+=1;i++;j--;
			}
			else i++;
		}
		cout<<res<<endl;
	}
}