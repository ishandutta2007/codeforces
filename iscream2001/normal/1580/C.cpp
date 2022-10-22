#include<bits/stdc++.h>
#define LL long long
#define ULL unsigned long long
using namespace std;

//static char ss[1<<17],*A=ss,*B=ss;
//char gc(){
//    return A==B&&(B=(A=ss)+fread(ss,1,1<<17,stdin),A==B)?EOF:*A++;
//}
//int read(){
//    int f=1,c; 
//	while (c=gc(),c<48||c>57) if (c=='-') f=-1; 
//	int x=c-'0';
//    while(c=gc(),c>47&&c<58) x=x*10+c-'0'; 
//	return f>0?x:-x;
//}


const LL P=998244353;
const int INF=1e9; 
const int N=2e5+10;
void init(){
	return;
}

int n,m; 

struct node{
	int x,y;
}a[N];
int vis[N],st[N];
bool val[N][610];
vector< pair<int,int> > V[N];
int B[610][610],cnt[610];
void MAIN(){
	int u,v;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i){
		scanf("%d%d",&a[i].x,&a[i].y);
		if(a[i].x+a[i].y>600){
			vis[i]=0;st[i]=0;
		//	V[1].push_back(i);
		}
		else{
			
		}
	}
	int op,K,now=0,sum=0,res;
	for(int da=1;da<=m;++da){
		scanf("%d%d",&op,&K);
		if(op==1){
			if(a[K].x+a[K].y<=600){
				now=da%(a[K].x+a[K].y);
				if(!now) now=a[K].x+a[K].y;
				for(int j=1;j<=a[K].x;++j){
					val[K][now]=0;
					++now;if(now>a[K].x+a[K].y) now-=a[K].x+a[K].y;
				}
				for(int j=1;j<=a[K].y;++j){
					val[K][now]=1;
					++now;if(now>a[K].x+a[K].y) now-=a[K].x+a[K].y;
				}
				for(int j=1;j<=a[K].x+a[K].y;++j){
					B[a[K].x+a[K].y][j]+=val[K][j];
				}
			}
			else{
				++vis[K];
				st[K]=1;
				V[da].push_back(make_pair(K,vis[K]));
				++sum;
			}
		}
		else{
			if(a[K].x+a[K].y<=600){
				for(int j=1;j<=a[K].x+a[K].y;++j){
					B[a[K].x+a[K].y][j]-=val[K][j];
				}
			}
			else{
				++vis[K];
				if(st[K]) --sum;
				st[K]=0;
			}
		}
		res=0;
		for(int i=1;i<=600;++i){
			cnt[i]++;
			if(cnt[i]>i) cnt[i]-=i;
			res+=B[i][cnt[i]];
		}
		for(int i=0;i<V[da].size();++i){
			u=V[da][i].first;
			v=V[da][i].second;
			if(v!=vis[u]) continue;
			if(st[u]){
				sum--;
				st[u]=0;
				if(da+a[u].x<=m){
					V[da+a[u].x].push_back(make_pair(u,v));
				}
			}
			else{
				sum++;
				st[u]=1;
				if(da+a[u].y<=m){
					V[da+a[u].y].push_back(make_pair(u,v));
				}
			}
		}
		V[da].clear();
		printf("%d\n",sum+res);
	}
	return;
}

int main(){
	init();
	int ttt=1;//scanf("%d",&ttt); 
	while(ttt--) MAIN();
	return 0;
}
/*
1
6 5
11110
10011
10011
10111
11101
01111
*/