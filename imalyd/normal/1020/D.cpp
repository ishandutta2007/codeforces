#include<bits/stdc++.h>
using namespace std;
int n,n2;
int geta(int v){int a;printf("? %d\n",v+1),fflush(stdout);scanf("%d",&a);return a;}
int getb(int v){return geta(v)-geta(v+n2);}
int main(){
	scanf("%d",&n),n2=n>>1;
	if(n&3){printf("! -1");return 0;}
	//for(int i=0;i<n2;i++)printf("%d\n",getb(i));
	int l=0,r=n2,lb=getb(0);
	if(!lb){printf("! 1");return 0;}
	int f=lb>0;
	while(1){
		int mid=(l+r)>>1,b=getb(mid);
		if(!b){printf("! %d",mid+1),fflush(stdout);return 0;}//printf("> %d %d %d\n",b,f,lb);
		//printf("~ %d %d %d\n",l,r,mid);
		if((b<0&&f)||(b>0&&!f))r=mid-1;else l=mid+1;
		//printf("? %d %d %d\n",l,r,mid);
	}
	return 0;
}