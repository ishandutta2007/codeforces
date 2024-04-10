#include <cstdio>
#include <algorithm>

int cnt;
bool query(int x){
//	++cnt;
	printf("? %d\n",x);
	fflush(stdout);
//	return 0;
	char ch=getchar();
	while(ch!='N'&&ch!='Y')ch=getchar();
	return ch=='Y';
}
void clr(){
	puts("R");
	fflush(stdout);
}
int n,k;
bool cando[1025];
int main(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)cando[i]=1;
	int len=std::max(k>>1,1);
	for(int i=1;i<n/len;i++)
		for(int j=0;j<i&&j+i<n/len;j++){
			for(int blk=j;blk<n/len;blk+=i)
				for(int l=1;l<=len;l++)
					if(query(blk*len+l))cando[blk*len+l]=0;
			clr();
		}
	int ans=0;
	for(int i=1;i<=n;i++)ans+=cando[i];
	printf("! %d\n",ans);
	fflush(stdout);
}