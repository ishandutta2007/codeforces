#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,res,t,x,y,sb1,sb2;

int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&x,&y);
		sb1=2*(min(x,y));
		sb2=abs(x-y)*2-1;
		sb2=max(sb2,0);
		printf("%d\n",sb1+sb2);
	}
}