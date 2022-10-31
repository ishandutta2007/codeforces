#include<bits/stdc++.h>
using namespace std;

int t,n,i,j,sum;

struct sb{
	int a;
	int b;
}s[10005];

int cmp(sb a,sb b){
	return a.a>b.a;
}

int main(){
	scanf("%d",&t);
	while(t--){
		sum=0;
		scanf("%d",&n);
		n*=2;
		for(i=1;i<=n;i++){
			scanf("%d",&s[i].a);
			s[i].a%=2;
			s[i].b=i;
		}
		sort(s+1,s+1+n,cmp);
		for(i=1;i<=n;i++){
			if((s[i].a+s[i+1].a)%2==0){
				printf("%d %d\n",s[i].b,s[i+1].b);sum+=2;i++;
			}
			if(sum==n-2){break;
			}
		}
	}
}