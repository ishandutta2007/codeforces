#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,a,b,c,d;
int main(){
	//ios::sync_with_stdio(0);
	cin>>t;
	while(t--){
		cin>>a>>b;
		k=abs(a-c)+abs(b-d);
		if(k&1){
			cout<<-1<<' '<<"-1\n";
			continue;
		}
		for(i=0;i<=50;i++){
			for(j=0;j<=50;j++){
				if((abs(i-a)+abs(j-b))!=(k/2))continue;
				if((abs(i-c)+abs(j-d))!=(k/2))continue;
				printf("%d %d\n",i,j);
				goto aaa;
			}
		}
		return 1;
		aaa:;
	}
}