#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+10,mo=1e9+7;
struct pi{int x,a,b;}now;
vector<pi> w[N];
int n,m;
int sig[N],tag[N],cnt=1;
ll f[N][2][2];
ll g[2],g1[2];
void move(ll &a,ll b){
	a=(a+b)%mo;
}
int si(int x){
	return x<0?-1:1;
}
int fnex(int x,int la){
	for (auto i:w[x]){
		if (i.x!=la){
			now=i;
			return i.x;
		}
		else la=0;
	}
	return 0;
}
void update(){
	g1[0]%=mo,g1[1]%=mo;
	ll x1=g[1]*g1[0]+g[0]*g1[1],x2=g[0]*g1[0]+g[1]*g1[1];
	g[1]=x1%mo;
	g[0]=x2%mo;
}
vector<int> h;
int main(){
	g[0]=1;
	cin>>m>>n;
	for (int i=1;i<=m;i++){
		int ty,x,y;
		scanf("%d%d",&ty,&x);
		if (ty==1)sig[x*si(x)]++,cnt+=(si(x)==-1);
		else {
			scanf("%d",&y);
			if (x*si(x)==y*si(y)){
				tag[x*si(x)]=1;
				if (si(x)==si(y)){
					g1[0]=g1[1]=1;
					update();
				}
				else {
					g1[0]=0,g1[1]=2;
					update();
				}
//				sig[x*si(x)]++;
//				cnt+=(si(x)==-1)+(si(y)==-1);
				continue;
			}
			w[x*si(x)].push_back((pi){y*si(y),si(x),si(y)});
			w[y*si(y)].push_back((pi){x*si(x),si(y),si(x)});
		}
	}
	for (int i=1;i<=n;i++){
		if (tag[i])continue;
		if (w[i].empty()){
			g1[0]=g1[1]=0;
			g1[0]++,g1[sig[i]&1]++;
			update();
			tag[i]=1;
			continue;
		}
		if (w[i].size()==1){
			f[i][0][0]=1;
			f[i][sig[i]][1]=1;
			for (int x=fnex(i,0),z=i,y;;y=z,z=x,x=fnex(x,y)){
				tag[z]=1;
				int p1=(-now.a+1)/2,p2=(-now.b+1)/2;
				if (!x){
					g1[0]=f[z][0][0]+f[z][sig[z]][1];
					g1[1]=f[z][1][0]+f[z][sig[z]^1][1];
					update();
					break;
				}
				for (int a=0;a<=1;a++)
				for (int b=0;b<=1;b++)
				for (int c=0;c<=1;c++){
					move(f[x][a^((b^p1)|(c^p2))][c],f[z][a][b]);
				}
			}
		}
	}
	for (int i=1;i<=n;i++){
		if (tag[i])continue;
		h.clear();
		for (int x=fnex(i,0),z=i,y;;y=z,z=x,x=fnex(x,y)){
			h.push_back(z);
			tag[z]=1;
			if (x==i)break;
		}
		g1[0]=g1[1]=0;
		for (int p0=0;p0<=1;p0++){
			for (auto x:h)memset(f[x],0,sizeof f[x]);
			f[i][0][p0]=1;
			for (int x=fnex(i,0),z=i,y;;y=z,z=x,x=fnex(x,y)){
				int p1=(-now.a+1)/2,p2=(-now.b+1)/2;
				if (x==i){
//					g1[0]=g1[1]=0;
					for (int a=0;a<=1;a++)
					for (int b=0;b<=1;b++)
						move(g1[a^((b^p1)|(p0^p2))],f[z][a][b]);
//					update();
					break;
				}
				for (int a=0;a<=1;a++)
				for (int b=0;b<=1;b++)
				for (int c=0;c<=1;c++){
					move(f[x][a^((b^p1)|(c^p2))][c],f[z][a][b]);
				}
			}			
		}
		update();
	}
	cout<<g[cnt&1]<<endl;
}