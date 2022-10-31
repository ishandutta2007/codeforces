#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,f[200500],cl=1;
ll res;
char s[200500];

int main(){
	cin>>n>>m>>s+1;
	for(i=1;i<=n;i++){
		f[i]=f[i-1]+(s[i]!=s[i-1]);
	}
	res=1ll*n*f[n]*(m-1);
	for(i=2;i<=n;i++){
		if(i>2&&s[i]!=s[i-2]){
			cl=i-1;
		}
		if(s[i]!=s[i-1]){
			res-=f[i]-f[cl];
		}
		//printf("a%d %d %d\n",i,cl,f[i]);
	}
	cout<<res;
}