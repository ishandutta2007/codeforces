#include <bits/stdc++.h>
using namespace std;
int i,j,k,n,m,t;
string s;
int main(){
	scanf("%d",&t);
	while(t--){
		while(1){
			for(i=1;i<=8;i++){
				for(j=1;j<=8;j++){
					printf("%d %d\n",i,(i&1)?j:9-j);
					cin>>s;
					if(s=="Done"){goto aaa;}
				}
			}
		}aaa:;
	}
}