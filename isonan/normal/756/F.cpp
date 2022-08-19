#include <cstdio>
#include <cstring>
#define int long long

const int P=1000000007;
inline int mul(const int &a,const int &b){return 1ll*a*b%P;}
inline int sub(int a,const int &b){a-=b;return (a<0)?a+P:a;}
inline int add(int a,const int &b){a+=b;return(a>=P)?a-P:a;}
int qsm(int a,int b,int P){
	int ans=1;
	while(b){
		if(b&1)ans=1ll*ans*a%P;
		a=1ll*a*a%P;
		b>>=1;
	}
	return ans;
}
char str[100001];
int stk[100001],top,nxt[100001];
struct number{
	int v,l;
	number(int a=0,int b=0){v=a,l=b;}
};
number read(int l,int r){
	number c;
	c.l=r-l+1;
	c.v=0;
	for(int j=l;j<=r;j++)c.v=(1ll*c.v*10+1ll*str[j]-1ll*'0')%P;
//	printf("%d %d %d\n",l,r,c.v);
	return c;
}
int Read(int l,int r){
	int x=0;
	for(int j=l;j<=r;j++)x=(1ll*x*10%(P-1)+1ll*(str[j]-'0'))%(P-1);
	return x;
}
number concate(number a,number b,int tem){
	if(qsm(10,a.l,P)==1)
		return (number){mul(b.v,a.v),1ll*a.l*tem%(P-1)};
//	printf("concate %d %d %d\n",a.v,b.v,tem);
//	printf("%d\n",mul(
//			mul(
//				sub(1,
//							qsm(10,1ll*a.l*tem%(P-1),P)
//					),
//				qsm(
//					sub(1,
//						qsm(10,a.l,P)
//						),
//					P-2,
//					P
//					)
//				)
//			,a.v));
	return (number){
		mul(
			mul(
				sub(1,
							qsm(10,1ll*a.l*tem%(P-1),P)
					),
				qsm(
					sub(1,
						qsm(10,a.l,P)
						),
					P-2,
					P
					)
				)
			,a.v)
		,1ll*a.l*tem%(P-1)};
}
int pre(number a,int t){
	int inv=qsm(sub(1,qsm(10,a.l,P)),P-2,P),ans=0,x=t,len=a.v;
	if(!inv)return mul(mul(len,add(len,1)),(P+1)>>1);
//	printf("pre %d %d %d %d %d %d %d\n",a.v,a.l,t,inv,x,len,mul(inv,sub(1,qsm(10,a.l,P))));
	if(a.l>1)ans=add(ans,mul(mul(sub(1,qsm(10,1ll*(x+1)*a.l%(P-1),P)),inv),qsm(10,a.l-1,P)));
	ans=add(ans,
				mul(
					sub(len,
						mul(
							sub(
								qsm(10,a.l,P),
								qsm(10,1ll*(x+1)*a.l%(P-1),P)
							),
							inv
						)
					),
					inv
				)
			);
//	printf("%d\n",ans);
	return ans;
}
number between(number a,number b,int ta,int tb){
//	printf("between %d %d %d %d %d %d\n",a.v,a.l,b.v,b.l,ta,tb);
	if(a.l==b.l){
		number v=concate((number){add(a.l==1,sub(a.v,qsm(10,a.l-1,P))),a.l},(number){sub(b.v+1,a.v),b.l},(tb+P-ta)%(P-1));
		int w=pre((number){sub(b.v,a.v),a.l},(tb+P-1-ta)%(P-1));
//		printf("%d %d %d %d\n",add(v.v,w),v.v,w,v.l);
		return (number){add(v.v,w),v.l};
	}
	int ans=0,len=0;
	ans=add(ans,between((number){qsm(10,b.l-1,P),b.l},b,qsm(10,b.l-1,P-1),tb).v);
	len=(len+1ll*b.l*(tb+P-qsm(10,b.l-1,P-1)%(P-1))%(P-1))%(P-1);
	for(int i=b.l-1;i>a.l;i--){
		ans=add(ans,mul(qsm(10,len,P),between((number){qsm(10,i-1,P),i},(number){sub(qsm(10,i,P),1),i},qsm(10,i-1,P-1),qsm(10,i,P-1)-1).v));
		len=(len+1ll*i*9*(qsm(10,i-1,P-1))%(P-1))%(P-1);
//		printf("%d\n",1ll*i*9*(qsm(10,i-1,P-1))%(P-1));
	}
	ans=add(ans,mul(qsm(10,len,P),between(a,(number){sub(qsm(10,a.l,P),1),a.l},ta,qsm(10,a.l,P-1)-1).v));
	len=(len+1ll*a.l*(qsm(10,a.l,P-1)+P-1-ta)%(P-1))%(P-1);
//	printf("%d\n",len);
	return (number){ans,len};
}
number operator+(number a,number b){return (number){add(mul(a.v,qsm(10,b.l,P)),b.v),(a.l+b.l)%(P-1)};}
number solve(int l,int r){
//	printf("solve %d %d\n",l,r);
	if(l>r)return (number){0,0};
	int p=l;
	while(p<=r&&str[p]>='0'&&str[p]<='9')++p;
	if(p>r)return read(l,r);
	if(str[p]=='+')return read(l,p-1)+solve(p+1,r);
	if(str[p]=='(')return concate(solve(p+1,nxt[p]-1),read(l,p-1),Read(l,p-1))+solve(nxt[p]+1,r);
	if(str[p]=='-'){
		int p1=p+1;
		while(p1<=r&&str[p1]>='0'&&str[p1]<='9')++p1;
		return between(read(l,p-1),read(p+1,p1-1),Read(l,p-1),Read(p+1,p1-1))+solve(p1+1,r);
	}
}
signed main(){
	scanf("%s",str+1);
	int nl=strlen(str+1);
	for(int i=1;i<=nl;i++)
		if(str[i]=='(')stk[++top]=i;
		else if(str[i]==')')nxt[stk[top--]]=i;
//	for(int i=1;i<=nl;i++)printf("%d ",nxt[i]);putchar('\n');
	printf("%lld\n",solve(1,nl).v);
}