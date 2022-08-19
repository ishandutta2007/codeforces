#include <cstdio>
#include <vector>
#include <algorithm>

int t,n,p[201],pos[201];
std::vector<int>tem,now;
bool vis[201];
char get(){
	char ch=getchar();
	while(ch!='<'&&ch!='>')ch=getchar();
	return ch;
}
bool comp(int i,int j){
	printf("? %d %d\n",i,j);
	fflush(stdout);
	return get()=='>';
//	return p[i]>p[j];
}
int alt(int x){return x>n?x-n:x+n;}
int main(){
	scanf("%d",&t);
	for(int fd=1;fd<=t;fd++){
		scanf("%d",&n);
//		for(int i=1;i<=(n<<1);i++)scanf("%d",p+i),pos[p[i]]=i;
//		for(int i=1;i<=(n<<1);i++)printf("%d ",pos[i]);putchar('\n');
		for(int i=1;i<=(n<<1);i++)vis[i]=0;
		tem.clear();
		now.clear();
		for(int i=1,tem;i<=n;i++)vis[tem=(comp(i,i+n)?i+n:i)]=1,::tem.push_back(tem);
		int v=tem[0],v1=-1;
		for(int i=1;i<n;i++)if(comp(tem[i],v))v=tem[i];
		for(int i=0;i<n;i++)
			if(v!=tem[i]){
				if(!~v1)v1=alt(tem[i]);
				else if(comp(v1,alt(tem[i])))v1=alt(tem[i]);
			}
		tem.clear();
		if(comp(v,v1)){
			for(int i=1;i<=(n<<1);i++)if(i!=alt(v)&&i!=v)tem.push_back(i);
			std::sort(tem.begin(),tem.end(),comp);
		}
		printf("!\n");
		fflush(stdout);
	}
}