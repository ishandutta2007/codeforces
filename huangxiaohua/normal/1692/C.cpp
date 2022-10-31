#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t;
char s[66][66];

int main(){
	cin>>t;
	while(t--){
		for(i=1;i<=8;i++)cin>>s[i]+1;
		for(i=1;i<=8;i++){
			for(j=1;j<=8;j++){
				if(s[i][j]!='#')continue;
				if(s[i-1][j-1]!='#')continue;
				if(s[i-1][j+1]!='#')continue;
				cout<<i<<' '<<j<<endl;
				goto aaa;
			}
		}
		aaa:;
	}
}