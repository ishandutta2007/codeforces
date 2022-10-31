#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,a[666];
string s;

int main(void){
    ios::sync_with_stdio(0);
    cin>>t;
    while(t--){
    	cin>>n;
    	memset(a,0,sizeof(a));
    	for(i=1;i<=n+n+1;i++){
    		cin>>s;
    		for(auto j:s)a[j]^=1;
		}
		for(char i='a';;i++)if(a[i]){
			cout<<i<<'\n';break;
		}
	}
}