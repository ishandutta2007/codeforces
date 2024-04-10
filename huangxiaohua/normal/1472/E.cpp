#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

struct sb{
	int x,y,id,z;
}s[500500],v[500500];

bool cmp1(sb a,sb b){
	return a.x<b.x;
}

int i,j,n,k,t,x,y,res[500500],cur;

int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(i=1;i<=n;i++){
			scanf("%d%d",&x,&y);
			s[i].x=x;s[i].y=y;s[i].id=i;
			s[i+n].x=y;s[i+n].y=x;s[i+n].id=i;
			res[i]=-1;
		}
		sort(s+1,s+n+n+1,cmp1);
		cur=0;
		v[0].y=1145141919;
		for(i=1;i<=n+n;i++){
			v[i].y=1145141919;
			if(s[i].x==s[i-1].x){s[i].z=cur;}
			else{cur++;s[i].z=cur;}
		}
		for(i=1;i<=n+n;i++){
			//printf("id%d %d %d %d\n",s[i].id,s[i].x,s[i].y,s[i].z);
			s[i].x=s[i].z;
			//printf("id%d %d %d\n",s[i].id,s[i].x,s[i].y);
			if(s[i].y<v[s[i].x].y){
				v[s[i].x].y=s[i].y;
				v[s[i].x].id=s[i].id;
			}
		}
		
		/*for(i=1;i<=n;i++){
			printf("a%d %d %d\n",i,v[i].y,v[i].id);
		}*/
		
		for(i=1;i<=n+n;i++){
			if(v[i-1].y<v[i].y){
				v[i].y=v[i-1].y;v[i].id=v[i-1].id;
			}
		}
		
		
		
		for(i=1;i<=n+n;i++){
			if(v[s[i].x-1].y<s[i].y){
				res[s[i].id]=v[s[i].x-1].id;
			}
		}
		for(i=1;i<=n;i++){
			//printf("id%d %d\n",v[i].id,v[i].y);
			printf("%d ",res[i]);
		}puts("");
	}
}