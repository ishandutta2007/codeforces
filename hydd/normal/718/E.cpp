#include<bits/stdc++.h>
using namespace std;
const int INF=0x3f3f3f3f;
typedef long long ll;
int T,n,k,upperlim,num[110000],pcnt[110000];
int cnt[26],tot[26][110000],sum[26][110000];
bool vis[110000],vis2[110000]; char s[110000];
vector<int> vec[16]; int dis1[16][110000],dis2[16][16];
int s0[16][16],s1[16][16],mn[16][16]; ll Ans[110];
void FMT_or(int *a){
	for (int j=0;j<k;j++)
		for (int i=0;i<=upperlim;i++)
			if (i&(1<<j)) a[i]+=a[i^(1<<j)];
}
int head,tail,que[1100000];
void bfs(int c,int *dis1,int *dis2){
	head=1; tail=0;
	for (int i=1;i<=n;i++){
		if (c==s[i]-'a') que[++tail]=i,dis1[i]=0;
		else dis1[i]=INF;
		vis[i]=false;
	}
	for (int i=0;i<k;i++) vis2[i]=false,dis2[i]=INF;
	while (head<=tail){
		int u=que[head++];
		if (vis[u]) continue;
		vis[u]=true;
		if (!vis2[s[u]-'a']){
			vis2[s[u]-'a']=true; dis2[s[u]-'a']=dis1[u];
			for (int v:vec[s[u]-'a'])
				if (dis1[v]>dis1[u]+1){
					dis1[v]=dis1[u]+1;
					que[++tail]=v;
				}
		}
		if (u>1)
			if (dis1[u-1]>dis1[u]+1){
				dis1[u-1]=dis1[u]+1;
				que[++tail]=u-1;
			}
		if (u<n)
			if (dis1[u+1]>dis1[u]+1){
				dis1[u+1]=dis1[u]+1;
				que[++tail]=u+1;
			}
	}
	for (int i=1;i<=n;i++) num[i]|=(dis1[i]-dis2[s[i]-'a'])<<c;
}

void work(int a,int b){
	int *f1=sum[a],*f2=sum[b]; static int g1[110000],g2[110000];
	if (!cnt[a]||!cnt[b]) return;
	
	int mn=INF,s0=0,s1=0; ll res;
	for (int c=0;c<k;c++) mn=min(mn,dis2[c][a]+dis2[c][b]+1);

	for (int c=0;c<k;c++){
		if (dis2[c][a]+dis2[c][b]+1==mn) s0|=(1<<c);
		if (dis2[c][a]+dis2[c][b]+1==mn+1) s1|=(1<<c);
	}
	::s0[a][b]=::s0[b][a]=s0; ::s1[a][b]=::s1[b][a]=s1; ::mn[a][b]=::mn[b][a]=mn;
	
	Ans[mn+1]+=1ll*cnt[a]*cnt[b];
	res=1ll*cnt[a]*cnt[b];
	for (int s=0;s<=upperlim;s++){
		if ((s&(upperlim^s0))==(upperlim^s0))
			res-=1ll*f1[s]*f2[s]*(pcnt[s0^(s&s0)]&1?-1:1);
	}
	Ans[mn]+=res; Ans[mn+1]-=res;

	for (int s=0;s<=upperlim;s++) g1[s]=0,g2[s]=0;
	for (int s=0;s<=upperlim;s++) g1[s|s0]+=f1[s]*(pcnt[s0^(s&s0)]&1?-1:1);
	for (int s=0;s<=upperlim;s++) g2[s|s0]+=f2[s]*(pcnt[s0^(s&s0)]&1?-1:1);
	
	res=0;
	for (int s=0;s<=upperlim;s++)
		if ((s&(upperlim^s1))==(upperlim^s1))
			res+=1ll*g1[s]*g2[s]*(pcnt[s1^(s&s1)]&1?-1:1);
	Ans[mn+2]+=res; Ans[mn+1]-=res;
}
int main(){
	pcnt[0]=0; for (int i=1;i<=100000;i++) pcnt[i]=pcnt[i>>1]+(i&1);
//	scanf("%d",&T);
	T=1;
	while (T--){
		scanf("%d",&n);
		scanf("%s",s+1); n=strlen(s+1);
		k=0;
		for (int i=1;i<=n;i++) k=max(k,s[i]-'a'+1);
		upperlim=(1<<k)-1;

		for (int i=1;i<=n;i++) num[i]=0;
		for (int i=0;i<k;i++){
			cnt[i]=0;
			for (int s=0;s<=upperlim;s++){
				tot[i][s]=0;
				sum[i][s]=0;
			}
			for (int j=0;j<k;j++){
				s0[i][j]=0; s1[i][j]=0; mn[i][j]=0;
			}
		}
		for (int i=0;i<=32;i++) Ans[i]=0;
		memset(num,0,sizeof(num)); memset(cnt,0,sizeof(cnt));
		memset(tot,0,sizeof(tot)); memset(sum,0,sizeof(sum));
		memset(dis1,0,sizeof(dis1)); memset(dis2,0,sizeof(dis2));
		memset(vis,false,sizeof(vis)); memset(vis2,0,sizeof(vis2));
		memset(s0,0,sizeof(s0)); memset(s1,0,sizeof(s1)); memset(mn,0,sizeof(mn)); memset(Ans,0,sizeof(Ans));

		for (int i=0;i<k;i++) vec[i].clear();
		for (int i=1;i<=n;i++) vec[s[i]-'a'].push_back(i);

		for (int i=0;i<k;i++) bfs(i,dis1[i],dis2[i]); 

		for (int i=1;i<=n;i++){
			cnt[s[i]-'a']++;
			tot[s[i]-'a'][num[i]]++;
			sum[s[i]-'a'][num[i]]++;
		}
		for (int i=0;i<k;i++) FMT_or(sum[i]);

		for (int i=0;i<k;i++) work(i,i);
		for (int c=0;c<k;c++)
			for (int s=0;s<=upperlim;s++)
				if (tot[c][s]){
					int mn=INF;
					for (int i=0;i<k;i++) mn=min(mn,dis2[c][i]+(s>>i&1)+dis2[c][i]+(s>>i&1)+1);
					Ans[mn]-=tot[c][s];
				}
		for (int i=0;i<=32;i++) Ans[i]>>=1;
		

		for (int i=0;i<k;i++)
			for (int j=i+1;j<k;j++)
				work(i,j);

		for (int i=1;i<=n;i++)
			for (int j=i+1;j<=n&&j<=i+k;j++){
				int x=num[i],y=num[j],a=s[i]-'a',b=s[j]-'a';
				if (a==b) continue;
				int _s0=s0[a][b],_s1=s1[a][b],_mn=mn[a][b];
				if (((x|y)&_s0)!=_s0) _mn=mn[a][b];
				else if ((x&_s0)==_s0&&(y&_s0)==_s0&&((x|y)&_s1)==_s1) _mn=mn[a][b]+2;
				else _mn=mn[a][b]+1;
				if (j-i<_mn) Ans[_mn]--,Ans[j-i]++;
			}
		
		int ans=0;
		for (int i=0;i<=32;i++)
			if (Ans[i]) ans++;
//		printf("%d\n",ans);
		for (int i=32;i>=0;i--)
			if (Ans[i]){
				printf("%d %lld\n",i,Ans[i]);
				break;
			}
	}
	return 0;
}