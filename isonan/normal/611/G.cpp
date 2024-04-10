#include <cstdio>
#define int long long

const int P=1000000007;
inline int mul(const int &a,const int &b){return 1ll*a*b%P;}
inline int add(int a,const int &b){a+=b;return(a>=P)?a-P:a;}
inline int sub(int a,const int &b){a-=b;return (a<0)?a+P:a;}
struct point{int x,y;}num[500001];
int n;
long long S;
long long tem,cnt,ans;
long long Sx,Sy;
long long abs(long long x){return x<0ll?(-x):x;}
long long cross(long long x1,long long y1,long long x2,long long y2){return abs(x1*y2-x2*y1);}
long long cro(long long x1,long long y1,long long x2,long long y2){
	x1=(x1%P+P)%P;y1=(y1%P+P)%P;x2=(x2%P+P)%P;y2=(y2%P+P)%P;
	return sub(mul(x1,y2),mul(x2,y1));
}
long long tri(point a,point b,point c){
	b.x-=a.x,b.y-=a.y,c.x-=a.x,c.y-=a.y;
	return cross(b.x,b.y,c.x,c.y);
}
inline int nxt(const int &i){return (i==n)?1:(i+1);}
inline int pre(const int &i){return (i==1)?n:(i-1);}
signed main(){
	scanf("%I64d",&n);
	for(int i=1;i<=n;i++)scanf("%I64d%I64d",&num[i].x,&num[i].y);
	Sx=num[1].x+num[2].x,Sy=num[1].y+num[2].y;
	for(int i=2;i<n;i++)S+=tri(num[1],num[i],num[i+1]);
	for(int i=1,j=2,tot=0;i<=n;i++){
		if(nxt(j)==i||j==i)j=nxt(i),Sx=num[i].x+num[j].x,Sy=num[i].y+num[j].y,tot=0,tem=0;
		while(tem<((S+1ll)>>1ll)){
			tem+=tri(num[i],num[j],num[nxt(j)]);
			(cnt+=tem)%=P;
			Sx+=num[nxt(j)].x;
			Sy+=num[nxt(j)].y;
			j=nxt(j),++tot;
		}
		(cnt+=P-(tem%P))%=P;
		tem-=tri(num[i],num[pre(j)],num[j]);
		Sx-=num[j].x;
		Sy-=num[j].y;
		j=pre(j);
		--tot;
		(ans+=1ll*tot*(S%P)%P+P-(2ll*cnt%P))%=P;
		(cnt+=P-cro(num[i].x+P-num[nxt(i)].x,num[i].y+P-num[nxt(i)].y,Sx%P+P+P-num[i].x-1ll*num[nxt(i)].x*(tot+1)%P,Sy%P+P+P-num[i].y-1ll*num[nxt(i)].y*(tot+1)%P))%=P;
		tem-=tri(num[i],num[nxt(i)],num[j]);
		Sx-=num[i].x;
		Sy-=num[i].y;
		if(tot)--tot;
	}
	printf("%I64d\n",ans%P);
}