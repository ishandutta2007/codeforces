#include<bits/stdc++.h>
using namespace std;
int n,i,j,t,k,m,res,sb[2],l,r;

int main(){
	scanf("%d",&n);
	while(n--){
		scanf("%d%d%d",&t,&k,&m);
		sb[0]=sb[1]=k;
		while(m--){
			scanf("%d%d",&l,&r);
			if((sb[1]>=l&&sb[1]<=r)||(sb[0]>=l&&sb[0]<=r)){sb[1]=max(sb[1],r);
			sb[0]=min(sb[0],l);
			}
			
		}
		printf("%d\n",sb[1]-sb[0]+1);
	}
}