#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int n,m,x,y,i,j,k,t,yes;
map<int,bool> sb;
int main(){
	scanf("%d",&t);
	while(t--){
		sb.clear();yes=0;
		scanf("%d",&n);
		for(i=1;i<=n;i++){
			scanf("%d",&k);
			if(!sb[k]){sb[k]=1;}else{yes=1;}
		}
		if(yes){puts("YES");
		}else{puts("NO");
		}
	}
}