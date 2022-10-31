#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define M 998244353

int i,j,k,n,m,t,p[1000500],res;
char s[1005000];

int main(void){
    ios::sync_with_stdio(0);
    cin>>t;
    while(t--){
    	cin>>n>>m>>s+1;
    	res=0;
    	for(i=1;i<=n;i++){
    		p[i]=p[i-1]+(s[i]=='B');
		}
		for(i=m;i<=n;i++)res=max(res,p[i]-p[i-m]);
		cout<<m-res<<endl;
	}
}