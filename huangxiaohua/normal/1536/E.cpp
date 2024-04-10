#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define M 1000000007
int i,j,k,n,m,t,l,r,cur,a[200500],zero;
char s[2050][2050];
ll res;
int main(){
	ios::sync_with_stdio(0);
	cin>>t;
	while(t--){
		cin>>n>>m;
		res=1;zero=0;
		for(i=1;i<=n;i++){
			cin>>s[i]+1;
			for(j=1;j<=m;j++){
				if(s[i][j]=='#'){res=res*2%M;}
				if(s[i][j]=='0'){zero=1;}
			}
		}
		res=(res+M-1+zero)%M;
		cout<<res<<endl;
	}
}