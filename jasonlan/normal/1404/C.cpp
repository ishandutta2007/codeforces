#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=301000;
int n,q,a[maxn];
int lr[maxn],rr[maxn],ord[maxn],ans[maxn],tr[maxn];
bool cmp(int x,int y){
	if(rr[x]!=rr[y])
		return rr[x]<rr[y];
	return lr[x]<lr[y];
}
inline int read(){
    int res=0;
    char ch=getchar(),ch1=ch;
    while(!isdigit(ch))ch1=ch,ch=getchar();
    while(isdigit(ch))res=(res<<1)+(res<<3)+ch-'0',ch=getchar();
    return ch1=='-'?-res:res;
}
void modify(int p,int x){
	for(register int i=p;i<=n;i+=i&-i)
		tr[i]+=x;
}
int query(int p){
	int res=0;
	for(register int i=p;i;i-=i&-i)
		res+=tr[i];
	return res;
}
int main(){
	n=read();q=read();
	for(register int i=1;i<=n;++i)
		a[i]=i-read();
	for(register int i=1;i<=q;++i){
		lr[i]=1+read();rr[i]=n-read();
		ord[i]=i;
	}
	sort(ord+1,ord+1+q,cmp);
	for(register int i=1,j=1,p,cnt;i<=n;++i){
		if(a[i]>=0&&tr[1]>=a[i]){
			p=0;cnt=0;
			for(register int k=18;~k;--k){
				p^=1<<k;
				if(p<=i&&cnt+tr[p]>=a[i])
					cnt+=tr[p];
				else p^=1<<k;
			}
			modify(1,1);modify(p+1,-1);
		}
		while(rr[ord[j]]==i)
			ans[ord[j]]=query(lr[ord[j]]),++j;
	}
	for(register int i=1;i<=q;++i)
		printf("%d\n",ans[i]);
    return 0;
}