#include<bits/stdc++.h>
#define ull unsigned long long
#define For(i,a,b) for(int i=a,i##end=b;i<=i##end;i++)
#define Rof(i,a,b) for(int i=a,i##end=b;i>=i##end;i--)
#define rep(i,  b) for(int i=1,i##end=b;i<=i##end;i++)
using namespace std;
const int N=1e5+9;
//char buf[(1<<21)+5],*p1,*p2;
//#define getchar() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++)
void chmx(int &x,int y){(x<y)&&(x=y);}
void chmn(int &x,int y){(x>y)&&(x=y);}
int read(){
	int f=0,x=0;
	char ch=getchar();
	while(!isdigit(ch)){f|=(ch=='-');ch=getchar();}
	while(isdigit(ch)){x=x*10+ch-'0';ch=getchar();}
	return f?-x:x;
}
int n,a[N],b[N],len;
vector<int>had[N];
struct node{
	ull h[2];
	node operator*(const node&x)const{
		node y;
		For(i,0,1)y.h[i]=h[i]*x.h[i];
		return y;
	}
	node operator+(const node&x)const{
		return node{h[0]+x.h[0],h[1]+x.h[1]};
	}
	node operator-(const node&x)const{
		return node{1ull*h[0]-x.h[0],1ull*h[1]-x.h[1]};
	}
	bool operator==(const node&x)const{
		return h[0]==x.h[0]&&h[1]==x.h[1];
	}
}A[N],P[N];
node get(int l,int r){return A[r]-A[l-1]*P[r-l+1];}
struct edge{
	int pre,to;
}e[100*N];int last[N],cnt;
void add(int x,int y){
	e[++cnt].pre=last[x];
	e[cnt].to=y;
	last[x]=cnt;
}
int sta[N],top;
signed main(){
//	printf("%.5lf\n",(&pppp-&ppp)/1024.0/1024.0);
	n=read();rep(i,n)a[i]=b[i]=read();
	P[1].h[0]=131;P[1].h[1]=114514123;
	P[0].h[0]=1;P[0].h[1]=1;
	For(i,2,n)P[i]=P[i-1]*P[1];
	sort(b+1,b+1+n);len=unique(b+1,b+1+n)-b-1;
	rep(i,n)a[i]=lower_bound(b+1,b+1+len,a[i])-b;
	rep(i,n)had[a[i]].push_back(i);
	rep(i,n){
		A[i].h[0]=A[i].h[1]=a[i];
		A[i]=A[i-1]*P[1]+A[i];
	}
	rep(i,len){
		for(int x=0;x<had[i].size();x++)
		for(int y=x+1;y<had[i].size();y++){
			int L=had[i][y]-had[i][x]-1;
			if(had[i][y]+L>n)continue;
			if(get(had[i][x],had[i][x]+L)==get(had[i][y],had[i][y]+L))
				add(L+1,had[i][x]);
		}
	}
	int now=1;
	rep(x,n/2){
		top=0;
		for(int i=last[x];i;i=e[i].pre)sta[++top]=e[i].to;
		sort(sta+1,sta+1+top);
		rep(i,top)if(sta[i]>=now)now=sta[i]+x;
	}
	cout<<n-now+1<<endl;
	For(i,now,n)printf("%d ",b[a[i]]);
	return 0;
}