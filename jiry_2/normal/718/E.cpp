#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
#include<vector>
using namespace std;
struct bian{
	int next,point;
}b[210000];
int p[110000],d[110000],pd[110000],dis[10][10],bo[110000],n,w[110000],num[8][256],len;
int D[8][256][8][256]; 
char ch[110000];
int ans;
long long way;
vector<int>go[11000];
queue<int>Q;
void ade(int k1,int k2){
	b[++len]=(bian){p[k1],k2}; p[k1]=len;
}
void add(int k1,int k2){
	ade(k1,k2); ade(k2,k1);
}
void solve(int s){
	memset(dis[s],0x3f,sizeof dis[s]);
	memset(d,0x3f,sizeof d);
	for (int i=1;i<=n;i++)
		if (w[i]==s) Q.push(i),d[i]=0;
	dis[s][s]=0;
	while (!Q.empty()){
		int k=Q.front(); Q.pop();
		for (int i=p[k];i;i=b[i].next){
			int j=b[i].point;
			if (d[k]+1<d[j]){
				d[j]=d[k]+1; Q.push(j);
			}
		}
		if (dis[s][w[k]]>d[k]){
			dis[s][w[k]]=d[k];
			for (int i=0;i<go[w[k]].size();i++){
				int j=go[w[k]][i];
				if (d[k]+1<d[j]){
					d[j]=d[k]+1; Q.push(j);
				}
			}
		}
	}
	for (int i=1;i<=n;i++) if (d[i]!=dis[s][w[i]]) bo[i]|=(1<<s);
}
void update(int k1,int k2){
	if (k1>ans){
		ans=k1; way=k2;
	} else if (k1==ans)
		way+=k2;
}
int getdis(int k1,int k2){
	if (k1==k2) return 0;
	if (w[k1]==w[k2]) return 1;
	int k=D[w[k1]][bo[k1]][w[k2]][bo[k2]];
	return min(k,abs(k1-k2));
}
int main(){
	scanf("%d",&n);
	scanf("%s",ch+1);
	for (int i=1;i<n;i++) add(i,i+1);
	for (int i=1;i<=n;i++){
		w[i]=ch[i]-'a';
		go[w[i]].push_back(i);
	}
	for (int i=0;i<8;i++) solve(i);
	for (int i=1;i<=n;i++) num[w[i]][bo[i]]++;
	ans=0; way=0;
	//cout<<bo[6]<<endl;
//	for (int i=0;i<5;i++){
//		for (int j=0;j<5;j++) cout<<dis[i][j]<<" "; cout<<endl;}
	memset(D,0x3f,sizeof D);
	for (int i=0;i<8;i++)
		for (int j=0;j<256;j++)
			for (int a=0;a<8;a++)
				for (int b=0;b<256;b++)
					for (int c=0;c<8;c++)
						D[i][j][a][b]=min(D[i][j][a][b],dis[i][c]+dis[c][a]+1+((j&(1<<c))>0)+((b&(1<<c))>0));
	for (int now=1;now<=n;now++){
		for (int i=max(1,now-15);i<=min(n,now+15);i++){
			int k=getdis(i,now); update(k,1);
		//	if (k==2) cout<<"fa "<<now<<" "<<i<<" "<<k<<" "<<1<<endl;
			num[w[i]][bo[i]]--;
		}
		for (int i=0;i<8;i++)
			for (int j=0;j<256;j++)
				if (num[i][j]){
					int k=D[w[now]][bo[now]][i][j];
					update(k,num[i][j]);
				//	cout<<"fa "<<w[now]<<" "<<bo[now]<<" "<<i<<" "<<j<<" "<<k<<" "<<num[i][j]<<endl;
				}
		for (int i=max(1,now-15);i<=min(n,now+15);i++){
			num[w[i]][bo[i]]++;
		}
	}
	printf("%d %I64d\n",ans,way/2);
	return 0;
}