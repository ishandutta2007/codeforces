#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,sb;
ll f[2];

int main(void){
    ios::sync_with_stdio(0);
    cin>>t;
    while(t--){
    	cin>>n;
    	f[0]=f[1]=0;sb=666;
    	while(n--){
    		cin>>i;
			f[i&1]++;
			sb=min(sb,__builtin_ffs(i));
		}
		cout<<f[0]+sb-1-(sb>1)<<'\n';
	}
}