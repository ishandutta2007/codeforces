#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <cmath>

int n,m,p,q;
int a[50001],b[50001];
double K[50001],B[50001],fin;
struct point{
	double x,y;
	int ord;
}num[100001];
bool cmp(point a,point b){return a.x<b.x||(a.x==b.x&&a.ord<b.ord);}
int ch[50001][2],size[50001],pri[50001],root;
std::pair<double,int> key[50001];
void pushup(int x){size[x]=size[ch[x][0]]+size[ch[x][1]]+1;}
void split(int now,int &x,int &y,const std::pair<double,int> &v){
	if(!now)x=y=0;
	else{
		if(key[now]<=v)x=now,split(ch[now][1],ch[now][1],y,v);
		else y=now,split(ch[now][0],x,ch[now][0],v);
		pushup(now);
	}
}
int merge(int x,int y){
	if(!x||!y)return x|y;
	if(pri[x]<pri[y]){
		ch[x][1]=merge(ch[x][1],y);
		pushup(x);
		return x;
	}
	else{
		ch[y][0]=merge(x,ch[y][0]);
		pushup(y);
		return y;
	}
}
long long calc(double mid){
//	printf("calc %Lf\n",mid);
	root=0;
	int top=0;
	for(int i=1;i<=n;i++){
		double u=std::pow(K[i],2)+1.0,v=(-K[i]*B[i]),delt=u*mid-std::pow(B[i],2);
		if(delt<0.)continue;
		double x1=(v-std::sqrt(delt))/u,x2=(v+std::sqrt(delt))/u,y1=atan2(K[i]*x1+B[i],x1),y2=atan2(K[i]*x2+B[i],x2);
		if(y1>y2)std::swap(y1,y2);
//		printf("%d %Lf %Lf %Lf %Lf\n",i,K[i],B[i],x1,x2);
		num[++top]=(point){y1,y2,i};
		num[++top]=(point){y2,y2,-i};
	}
	std::sort(num+1,num+top+1,cmp);
	long long cnt=0;
	for(int i=1;i<=top;i++)
		if(num[i].ord>0){
			int u=num[i].ord;
			size[u]=1;
			ch[u][0]=ch[u][1]=0;
			key[u]=std::make_pair(num[i].y,u);
			int t1,t2;
			split(root,t1,t2,key[u]);
			cnt+=size[t1];
			root=merge(t1,merge(u,t2));
//			printf("%Lf %d\n",num[i].y,u);
		}
		else{
			int u=-num[i].ord;
			int t1,t2,t3;
			split(root,t1,t2,std::make_pair(num[i].y,u-1));
			split(t2,t2,t3,key[u]);
			root=merge(t1,t3);
		}
//	printf("%d\n",cnt);
	return cnt;
}
void dfs(int x,int u){
	if(!x)return;
	dfs(ch[x][0],u);
	dfs(ch[x][1],u);
//	printf("%d %d\n",x,u);
	double X=(B[x]-B[u])/(K[u]-K[x]),Y=K[x]*X+B[x];
//	printf("%Lf\n",X*X+Y*Y);
	fin+=sqrt(X*X+Y*Y);
}
int main(){
	scanf("%d%d%d%d",&n,&p,&q,&m);
	for(int i=1;i<=n;i++)pri[i]=rand();
	for(int i=1;i<=n;i++){
		scanf("%d%d",a+i,b+i);
		K[i]=((double)a[i])/1000.0;
		B[i]=((double)b[i])/1000.0;
		B[i]+=K[i]*((double)p/1000.0)-((double)q/1000.0);
//		printf("%Lf %Lf\n",K[i],B[i]);
	}
	double l=0.,r=2000010000.,mid,ans;
	int p=0;
	while((r-l)/(std::max(1.,l))>=1e-6){
		mid=(l+r)/2.0;
//		printf("%.9Lf %.9Lf %.9Lf\n",l,r,mid);
		int u=calc(mid*mid);
		if(u<1ll*m)ans=mid*mid,l=mid,p=u;
		else r=mid;
	}
	if(ans==0.0){
		printf("0.0");
		return 0;
	}
	fin=1.0*(m-p)*sqrt(ans);
//	printf("%Lf\n",pow(fin,2));
	root=0;
	int top=0;
	for(int i=1;i<=n;i++){
		double u=pow(K[i],2)+1.0,v=(-K[i]*B[i]),delt=u*ans-pow(B[i],2);
		if(delt<0.)continue;
		double x1=(v-sqrt(delt))/u,x2=(v+sqrt(delt))/u,y1=atan2(K[i]*x1+B[i],x1),y2=atan2(K[i]*x2+B[i],x2);
		if(y1>y2)std::swap(y1,y2);
		num[++top]=(point){y1,y2,i};
		num[++top]=(point){y2,y2,-i};
	}
	std::sort(num+1,num+top+1,cmp);
	for(int i=1;i<=top;i++)
		if(num[i].ord>0){
			int u=num[i].ord;
			size[u]=1;
			ch[u][0]=ch[u][1]=0;
			key[u]=std::make_pair(num[i].y,u);
			int t1,t2;
			split(root,t1,t2,key[u]);
			dfs(t1,u);
			root=merge(t1,merge(u,t2));
		}
		else{
			int u=-num[i].ord;
			int t1,t2,t3;
			split(root,t1,t2,std::make_pair(num[i].y,u-1));
			split(t2,t2,t3,key[u]);
			root=merge(t1,t3);
		}
	printf("%.7lf\n",fin);
}