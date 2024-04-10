#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,n,k,t,sb,x,y,z;

int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d%d%d",&x,&y,&z);
		sb=1;
		while((x%2)==0){
			sb*=2;x/=2;
		}
		while((y%2)==0){
			sb*=2;y/=2;
		}
		if(sb>=z){puts("YES");
		}else{puts("NO");
		}
	}
}