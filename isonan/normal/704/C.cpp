#include <cstdio>
#include <vector>
#include <cstring>

const int P=1000000007;
inline int mul(const int &a,const int &b){return 1ll*a*b%P;}
inline int add(int a,const int &b){a+=b;return(a>=P)?a-P:a;}
inline int sub(int a,const int &b){a-=b;return (a<0)?a+P:a;}
int head[100001],nxt[200001],b[200001],k,n,m,d[100001],top,nod[100001],Pow[100001],f[100001][2][2];
int ans,len;
std::vector<int>var[100001],con[100001];
bool vis[100001];
inline void push(const int &s,const int &t){nxt[++k]=head[s],head[s]=k,b[k]=t,++d[t];}
inline int abs(const int &x){return x<0?-x:x;}
void find(int x,int f,int orig){
	nod[++top]=x;
	vis[x]=1;
	for(int i=head[x];i;i=nxt[i])
		if(b[i]!=f&&b[i]!=orig)return find(b[i],x,orig);
}
bool iss(int x,int y){
	for(int i=0;i<var[x].size();i++)
		for(int j=0;j<var[y].size();j++)
			if(abs(var[x][i])==abs(var[y][j]))return (var[x][i]/var[y][j])==1;
}
int main(){
	scanf("%d%d",&n,&m);
	Pow[0]=1;
	for(int i=1;i<=m;i++)Pow[i]=mul(Pow[i-1],2);
	for(int i=1,tem,tem2;i<=n;i++){
		scanf("%d",&tem);
		for(int j=1;j<=tem;j++){
			scanf("%d",&tem2);
			var[i].push_back(tem2);
			con[abs(tem2)].push_back(i);
		}
	}
	for(int i=1;i<=m;i++)
		if(con[i].size()==2){
			if(con[i][0]==con[i][1]){
				int odd,L=1;
				if(var[con[i][0]][0]+var[con[i][0]][1]==0)odd=2;
				else odd=1;
				ans=add(mul(ans,sub(Pow[L],odd)),mul(sub(Pow[len],ans),odd));
				len+=L;
				vis[con[i][0]]=1;
			}
			else push(con[i][0],con[i][1]),push(con[i][1],con[i][0]);
		}
	for(int i=1;i<=n;i++)
		if(!vis[i]&&d[i]==1){
			top=0;
			find(i,0,i);
				memset(f[1],0,sizeof f[1]);
			f[1][0][0]=1;
			int L=top-1;
			if(var[i].size()==2)f[1][1][1]=1,++L;
			for(int j=2;j<=top;j++){
				if(iss(nod[j-1],nod[j])){
					f[j][0][0]=add(f[j-1][0][1],f[j-1][0][0]);
					f[j][1][0]=add(f[j-1][1][1],f[j-1][1][0]);
					f[j][0][1]=add(f[j-1][1][1],f[j-1][0][0]);
					f[j][1][1]=add(f[j-1][0][1],f[j-1][1][0]);
				}
				else{
					f[j][0][0]=add(f[j-1][0][1],f[j-1][1][0]);
					f[j][1][0]=add(f[j-1][1][1],f[j-1][0][0]);
					f[j][0][1]=add(f[j-1][1][1],f[j-1][1][0]);
					f[j][1][1]=add(f[j-1][0][1],f[j-1][0][0]);
				}
//				printf("%d %d %d %d %d\n",iss(nod[j-1],nod[j]),f[j][0][0],f[j][0][1],f[j][1][0],f[j][1][1]);
			}
			if(var[nod[top]].size()==2)f[top][1][1]=add(mul(f[top][1][1],2),f[top][0][0]),f[top][0][1]=add(mul(f[top][0][1],2),f[top][1][0]),++L;
			int odd=add(f[top][1][0],f[top][1][1]);
//			for(int i=1;i<=top;i++)printf("%d ",nod[i]);
//			printf("%d\n",odd);
			ans=add(mul(ans,sub(Pow[L],odd)),mul(sub(Pow[len],ans),odd));
			len+=L;
		}
	for(int i=1;i<=n;i++)
		if(!vis[i]){
			top=0;
			find(i,0,i);
			int odd=0;
			if(top==1){
				if(var[i].size()==1)odd=1;
				else odd=3,++top;
			}
			else if(top==2){
				for(int x=0;x<var[i].size();x++)
					for(int y=0;y<var[nod[2]].size();y++)
						if(abs(var[i][x])==abs(var[nod[2]][y])){
							if((var[i][x]/var[nod[2]][y])==-1)++odd;
						}
			}
			else
			for(int bit=0;bit<2;bit++){
				memset(f[1],0,sizeof f[1]);
				f[1][bit][bit]=1;
				for(int j=2;j<=top;j++){
					if(iss(nod[j-1],nod[j])){
						f[j][0][0]=add(f[j-1][0][1],f[j-1][0][0]);
						f[j][1][0]=add(f[j-1][1][1],f[j-1][1][0]);
						f[j][0][1]=add(f[j-1][1][1],f[j-1][0][0]);
						f[j][1][1]=add(f[j-1][0][1],f[j-1][1][0]);
					}
					else{
						f[j][0][0]=add(f[j-1][0][1],f[j-1][1][0]);
						f[j][1][0]=add(f[j-1][1][1],f[j-1][0][0]);
						f[j][0][1]=add(f[j-1][1][1],f[j-1][1][0]);
						f[j][1][1]=add(f[j-1][0][1],f[j-1][0][0]);
					}
				}
				if(iss(nod[1],nod[top])==bit)odd=add(odd,add(f[top][1][1],f[top][0][0]));
				else odd=add(odd,add(f[top][1][0],f[top][1][1]));
			}
//				for(int i=1;i<=top;i++)printf("%d ",nod[i]);
//				printf("%d\n",odd);
				ans=add(mul(ans,sub(Pow[top],odd)),mul(sub(Pow[len],ans),odd));
				len+=top;
		}
	ans=mul(ans,Pow[m-len]);
	printf("%d\n",ans);
}