#include <cstdio>
#include <algorithm>

int t,n,l[100001],r[100001],c[100001];
int mx;
int main(){
	scanf("%d",&t);
	for(int fd=1;fd<=t;++fd){
		scanf("%d",&n);
		int nl=0,nr=0,mx=0;
		long long ans=0;
		for(int i=1;i<=n;++i){
			scanf("%d%d%d",l+i,r+i,c+i);
			if(i==1)nl=nr=mx=i;
			else{
				if(l[i]<l[nl]||(l[i]==l[nl]&&c[i]<c[nl]))nl=i;
				if(r[i]>r[nr]||(r[i]==r[nr]&&c[i]<c[nr]))nr=i;
				if(l[mx]!=l[nl]||r[mx]!=r[nr])mx=0;
				if(l[i]==l[nl]&&r[i]==r[nr]&&(!mx||c[i]<c[mx]))mx=i;
			}
			int tem=0x7f7f7f7f;
			tem=c[nl]+c[nr];
			if(l[mx]==l[nl]&&r[mx]==r[nr])tem=std::min(tem,c[mx]);
			printf("%d\n",tem);
		}
	}
}