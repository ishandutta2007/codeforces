#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int t,n,i,r,a,sb[100500],two,four,j;
char b,jb[66];
int main(){
    scanf("%d\n",&n);
    for(i=1;i<=n;i++){
    	scanf("%d",&a);
    	sb[a]++;
    	if(sb[a]%4==0){four++;two--;continue;}
    	if(sb[a]%2==0){two++;}
	}
	
	scanf("%d\n",&t);
	for(i=1;i<=t;i++){
		gets(jb);
		sscanf(jb,"%c%d",&b,&a);
		fflush(stdout);
		if(b=='+'){
			sb[a]++;
			if(sb[a]%4==0){four++;two--;goto aaa;}
			if(sb[a]%2==0){two++;}
    		
		}
		if(b=='-'){
			if(sb[a]%4==0){four--;two++;sb[a]--;goto aaa;}
			if(sb[a]%2==0){two--;}sb[a]--;
		}
		aaa:if(four>=1&&two>=2||four>=2){puts("YES");}
		else{puts("NO");}
		//for(j=1;j<=10;j++){printf("%d %d %d\n",sb[j],two,four);}
	}
}