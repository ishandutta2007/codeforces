#include<iostream>
#include<cstdio>
using namespace std;
const int maxn=4010;
int n,cnt;
bool ismag[maxn];
int queryzone(int p,int l,int r){
	printf("? %d %d\n%d\n",1,r-l+1,p);
	for(int i=l;i<=r;++i){
		if(i>l)printf(" ");
		printf("%d",i);
	}
	printf("\n");
	cout.flush();
	scanf("%d",&p);
	return p;
}
int query(int p,int q){
	printf("? %d %d\n%d\n%d\n",1,1,p,q);
	cout.flush();
	scanf("%d",&p);
	return p;
}
void Search(int p){
	int l=1,r=p-1;
	while(l<r){
		int mid=(l+r)>>1;
		if(queryzone(p,l,mid))r=mid;
		else l=mid+1;
	}
	ismag[l]=1;
}
void process(){
	scanf("%d",&n);
	cnt=0;
	for(int i=1;i<=n;++i)
		ismag[i]=0;
	for(int i=2,p0=0;i<=n;++i){
		if(!p0){
			ismag[i]=queryzone(i,1,i-1)!=0;
			if(ismag[i]){
				p0=i;
				Search(i);
			}
			else ++cnt;
		}
		else{
			ismag[i]=(query(i,p0)!=0);
			cnt+=(!ismag[i]);
		}
	}
	printf("! %d",cnt);
	for(int i=1;i<=n;++i)
		if(!ismag[i])printf(" %d",i);
	puts("");
	cout.flush();
}
int main(){
	int T;scanf("%d",&T);
	while(T--)process();
	return 0;
}