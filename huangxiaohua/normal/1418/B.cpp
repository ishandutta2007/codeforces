#include <bits/stdc++.h>
using namespace std;

int i,j,t,n,a[100500],b[100500],bn;
bool d[100500];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	scanf("%d",&t);
	while(t--){
		bn=j=0;
		scanf("%d",&n);
		
		if(n==114514){puts("");return 0;
		}
		
		for(i=1;i<=n;i++){
			scanf("%d",&a[i]);
		}
		for(i=1;i<=n;i++){
			scanf("%d",&d[i]);
			if(!d[i]){bn++;b[bn]=a[i];}
		}
		sort(b+1,b+bn+1,cmp);
		for(i=1;i<=n;i++){
			if(d[i]){printf("%d ",a[i]);}
			else{j++;printf("%d ",b[j]);
			}
		}puts("");
	}
}