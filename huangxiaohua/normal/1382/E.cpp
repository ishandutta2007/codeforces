#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
 
int i,j,k,n,m,t,used[200500],it,a[200500],res[200500],x,y,b[200500],nmsl[200500],num[200500];
struct sb{
	int x,y;
	bool operator<(const sb a)const{return y<a.y;}
}s1,s[200500];
priority_queue<sb> q;
bool cmp(int x,int y){return (num[a[x]]==num[a[y]])?a[x]<a[y]:num[a[x]]<num[a[y]];}

int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d%d%d",&n,&x,&y);m=0;it=0;
		while(!q.empty()){q.pop();}
		for(i=1;i<=n+1;i++){
			s[i].x=i;s[i].y=0;
			used[i]=0;
			b[i]=0;res[i]=0;num[i]=0;
		}
		for(i=1;i<=n;i++){
			scanf("%d",&a[i]);used[a[i]]=1;
			s[a[i]].y++;num[a[i]]++;
		}
		for(i=1;i<=n+1;i++){if(s[i].y){q.push(s[i]);}if(!used[i]){it=i;}}
		for(i=1;i<=x;i++){
			s1=q.top();q.pop();
			s1.y--;b[s1.x]++;num[s1.x]--;
			if(s1.y){q.push(s1);}
		}
		for(i=1;i<=n;i++){
			if(b[a[i]]){res[i]=a[i];b[a[i]]--;continue;}
			else{nmsl[m]=i;m++;}
		}
		if(m){sort(nmsl,nmsl+m,cmp);}
		j=0;
		for(i=0;i<m;i++){
			res[nmsl[i]]=a[nmsl[(i+m/2)%m]];
			if(res[nmsl[i]]==a[nmsl[i]]||j+x==y){res[nmsl[i]]=it;}
			else{j++;}
		}
		if(j+x<y){puts("NO");continue;}
		puts("YES");
		for(i=1;i<=n;i++){
			printf("%d ",res[i]);
		}puts("");
	}
}