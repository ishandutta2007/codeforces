#pragma GCC optimize("-O3")
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<algorithm>
#include<cstring>
#include<map>
#include<queue>
#include<set>
#include<cmath>
#include<vector>
#include<bitset>
#define DB double
#define LL long long
#define ui unsigned int
#define ull unsigned long long
using namespace std;
  
inline int read(){
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
void Out(int x){
    if(x>9) Out(x/10);
    putchar('0'+x%10);
}
int gcd(int x,int y){
    if(!y) return x;
    return gcd(y,x%y);
}
LL qpow(LL x,LL y,LL P){
    LL re=1;
    while(y){
        if(y&1) re=re*x%P;
        x=x*x%P;y>>=1;
    }
    return re;
}
const DB eps=1e-6;
const DB PI=acos(-1);
const int N=1e5+50;
const int E=100;
int n,w,Q,tt=0;
struct date{
	int id,r;
}q[N*(E+5)];
bool operator < (date A,date B){
	if(A.r!=B.r) return A.r<B.r;
	else return A.id>B.id;
}
int a[N],nxt[N];
int st[20][N][2];
int ans[N];
int sm[N],bi[N],co[N],to[N];
void update(int x){
	if(nxt[x]==n+1||nxt[x]%E==1){
		co[x]=1;to[x]=x;
	}
	else{
		co[x]=co[nxt[x]]+1;
		to[x]=to[nxt[x]];
	}
}
int main(){
	int x;
	scanf("%d%d%d",&n,&w,&Q);
	for(int i=1;i<=n;++i){
		scanf("%d",&a[i]);
		st[0][i][0]=st[0][i][1]=a[i];
	}
	for(int i=1;i<=Q;++i){
		scanf("%d",&x);
		q[++tt].id=i-Q;
		q[tt].r=w-x;
	}
	for(int j=1;(1<<j)<=n;++j)
		for(int i=1;i+(1<<j)<=n+1;++i){
			st[j][i][0]=min(st[j-1][i][0],st[j-1][i+(1<<j-1)][0]);
			st[j][i][1]=max(st[j-1][i][1],st[j-1][i+(1<<j-1)][1]);
		}
	int mn,mx;
	for(int i=n;i>=1;--i){
		nxt[i]=i+1;
		sm[i]=bi[i]=a[i];
		update(i);
		//cout<<to[i]<<" "<<co[i]<<endl;
		mn=a[i];mx=a[i];
		for(int j=i+1;j<=n&&(j-1)%E;++j){
			mn=min(mn,a[j]);mx=max(mx,a[j]);
			//cout<<"pl "<<i<<" "<<mx-mn<<" "<<mx<<" "<<mn<<endl;
			q[++tt].id=i;
			q[tt].r=mx-mn;
		}
	}
	sort(q+1,q+1+tt);
	int R,k;
	for(int i=1;i<=tt;++i){
		if(q[i].id<=0){
			int cst=-1;x=1;
			while(x<=n){
				//cout<<x<<" "<<q[i].r<<endl;
				cst+=co[x];
				x=to[x];
				//cout<<"now "<<x<<" "<<cst<<" "<<q[i].id<<endl;
				mn=sm[x];
				mx=bi[x];
				//cout<<mn<<" "<<mx<<endl;
				R=x;
				k=0;
				while(x+(1<<k)<=n+1&&max(mx,st[k][x][1])-min(mn,st[k][x][0])<=q[i].r){
					++k;
					mx=max(mx,st[k][x][1]);
					mn=min(mn,st[k][x][0]);
				} 
				mn=sm[x];
				mx=bi[x];
				//cout<<mn<<" "<<mx<<endl;
				//cout<<k<<endl;
				for(;k>=0;--k){
					//cout<<k<<" "<<R<<" "<<st[k][R][1]<<" "<<st[k][R][0]<<endl;
					if(R+(1<<k)<=n+1&&max(mx,st[k][R][1])-min(mn,st[k][R][0])<=q[i].r){
						mx=max(mx,st[k][R][1]);
						mn=min(mn,st[k][R][0]);
						R+=(1<<k);
						
					}
				}
				//cout<<R<<endl;
				x=R;
			}
			ans[q[i].id+Q]=cst;
		}
		else{
			//cout<<"add "<<q[i].id<<" "<<q[i].r<<endl;
			x=q[i].id;
			nxt[x]++;
			while(1){
				update(x);
				if(x%E==1) break;
				--x;
			}
		}
	}
	for(int i=1;i<=Q;++i) printf("%d\n",ans[i]);
}
/*

*/