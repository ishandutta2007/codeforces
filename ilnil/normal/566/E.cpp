#include<bits/stdc++.h>
#define fo(i,a,b)for(int i=a,_e=b;i<=_e;++i)
#define ll long long
using namespace std;
const int N=1005,mo=1e9+7,mul=1e6+7;
int n,k,x,es;
vector<int>e2[N];
bitset<N>a[N],aa,t,t2,son[N];
map<int,int>wz;
int v[N];
bool is[N][N],in[N],yes[N];
struct edge{int x,y;}e[N];
inline void link(int x,int y){
	if(x>y)swap(x,y);
	if(!is[x][y])is[x][y]=1,e[++es]=(edge){x,y},e2[x].push_back(y),e2[y].push_back(x),in[x]=in[y]=1;
}
inline void link2(int x,int y){
	if(x>y)swap(x,y);
	if(!is[x][y])is[x][y]=1,e[++es]=(edge){x,y};
}
int main(){
	ios::sync_with_stdio(false);
	cin>>n;
	fo(i,1,n){
		cin>>k;
		fo(j,1,k)cin>>x,a[i][x]=1;
	}
	if(n==2){
		printf("1 2");
		return 0;
	}
	fo(i,1,n)fo(j,i+1,n){
		aa=a[i]&a[j];
		if(aa.count()==2){
			int x=aa._Find_first(),y=aa._Find_next(x);
			link(x,y);
		}
	}
	if(!es)fo(i,2,n)link2(1,i);else
	if(es==1){
		int x=e[1].x,y=e[1].y;
		fo(i,1,n)if(a[i].count()!=n){
			fo(j,1,n)if(a[i][j]){
				if(j!=x&&j!=y)link2(x,j);
			}else link2(y,j);
			break;
		}
	}else{
		v[0]=1;
		fo(i,1,n)v[i]=(ll)v[i-1]*mul%mo;
		fo(i,1,n)if(in[i]){
			int x=v[i];
			for(int j:e2[i])x=(x+v[j])%mo;
			wz[x]=i;
			t[i]=1;
		}else t2[i]=1;
		fo(i,1,n)son[i]=t2;
		fo(i,1,n){
			aa=a[i]&t;
			int x=0;
			fo(j,1,n)if(aa[j])x=(x+v[j])%mo;
			int w=wz[x];
			if(w)
				son[w]&=a[i],yes[w]=1;
		}
		fo(i,1,n)if(e2[i].size()==1)
			son[e2[i][0]]&=~son[i];
		fo(i,1,n)if(in[i]&&yes[i]){
			fo(j,1,n)if(i!=j&&son[i][j])
				link2(i,j);
		}
	}
	fo(i,1,es)printf("%d %d\n",e[i].x,e[i].y);
}