#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>

int n,x[300001],y[300001];
char s[500001];
struct val{
	int l,r;
	val(){l=-0x7f7f7f7f,r=0x7f7f7f7f;}
	void updl(int x){l=std::max(l,x);}
	void updr(int x){r=std::min(r,x);}
};
bool judge(int u){
	val x,y,xdy;
	x.updl(0);
	y.updl(0);
	for(int i=1;i<=n;i++){
		x.updr(u+::x[i]);
		x.updl(::x[i]-u);
		y.updr(u+::y[i]);
		y.updl(::y[i]-u);
		xdy.updr(::x[i]-::y[i]+u);
		xdy.updl(::x[i]-::y[i]-u);
	}
//	printf("%d %d %d %d %d %d %d\n",u,x.l,x.r,y.l,y.r,xdy.l,xdy.r);
	if(x.l>x.r||y.l>y.r||xdy.l>xdy.r)return 0;
	int x1=std::max(xdy.l,x.l-y.r),y1=std::min(xdy.r,x.r-y.l);
	return x1<=y1;
}
void getans(int u){
	val x,y,xdy;
	x.updl(0);
	y.updl(0);
	for(int i=1;i<=n;i++){
		x.updr(u+::x[i]);
		x.updl(::x[i]-u);
		y.updr(u+::y[i]);
		y.updl(::y[i]-u);
		xdy.updr(::x[i]-::y[i]+u);
		xdy.updl(::x[i]-::y[i]-u);
	}
	for(int i=x.l;i<=x.r;i++){
		int x1=std::max(xdy.l,i-y.r),y1=std::min(xdy.r,i-y.l);
		if(!i)y1=std::min(y1,i-1);
		if(x1<=y1){
			for(int j=y.l;j<=y.r;j++)
				if(i-j>=xdy.l&&i-j<=xdy.r&&(i||j)){
					for(int k=1;k<=i;k++)putchar('B');
					for(int k=1;k<=j;k++)putchar('N');
					exit(0);
				}
		}
	}
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%s",s+1);
		int nl=strlen(s+1);
		for(int j=1;j<=nl;j++)
			if(s[j]=='B')++x[i];
			else ++y[i];
	}
	int l=0,r=500000,mid,ans=-1;
	while(l<=r){
		mid=(l+r)>>1;
		if(judge(mid))ans=mid,r=mid-1;
		else l=mid+1;
	}
	printf("%d\n",ans);
	getans(ans);
}