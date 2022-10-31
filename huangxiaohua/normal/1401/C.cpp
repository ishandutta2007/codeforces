#include<bits/stdc++.h>
using namespace std;
int i,t,n,mn,a[100500],an,no;
struct sb{
	int x;
	int y;
}s[100500];

int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);mn=1145141919;an=no=0;
		for(i=1;i<=n;i++){
			scanf("%d",&s[i].x);
			mn=min(mn,s[i].x);
		}
		for(i=1;i<=n;i++){
			if(s[i].x%mn==0){
				s[i].y=1;an++;a[an]=s[i].x;
			}
			else{
				s[i].y=0;
			}
		}
		sort(a+1,a+an+1);an=0;
		for(i=1;i<=n;i++){
			if(s[i].y==1){
				an++;s[i].x=a[an];
			}
			//printf("%d ",s[i].x);
		}
		for(i=2;i<=n;i++){
			if(s[i].x<s[i-1].x){
				no=1;break;
			}
		}
		if(no){puts("NO");}
		else{puts("YES");}
	}
}