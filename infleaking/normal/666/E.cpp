#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pi;
const int N=1e5+10,M=N*5;
int tr[N][26],trans[N][26],step[N],pre[N],las[N],t;
int r[N],n,m,q,t1,lp[N],fa[N][20],dep[N];
int getp(int x){
	step[++t]=step[x]+1;
	return t;
}
int extend(int las,int x){
	int p=las,np=getp(p);
	for (;p&&!trans[p][x];p=pre[p])trans[p][x]=np;
	if (!p){
		pre[np]=1;
		return np;
	}
	int q=trans[p][x];
	if (step[q]!=step[p]+1){
		int nq=getp(p);
		for (;p&&trans[p][x]==q;p=pre[p])trans[p][x]=nq;
		memcpy(trans[nq],trans[q],sizeof trans[q]);
		pre[nq]=pre[q];
		pre[q]=pre[np]=nq;
	}else pre[np]=q;
	return np;
}
char h[N],s[M];
int ps[M],rt[N],c[M*10][2],t2,len[M];
pi tmx[M*10];
#define x1 c[x][0]
#define x2 c[x][1]
#define Md (l+r>>1)
int merge(int x,int y,int l=1,int r=m){
	if (!x||!y)return x^y;
	int x0=x;x=++t2;
	tmx[x]=tmx[x0];
	if (l==r){
		tmx[x].first+=tmx[y].first;
		return x;
	}
	x1=merge(c[x0][0],c[y][0],l,Md);
	x2=merge(c[x0][1],c[y][1],Md+1,r);
	tmx[x]=max(tmx[x1],tmx[x2]);
	return x;
}
int pl,pr,px;
pi query(int x,int l,int r){
	if (!x||r<pl||pr<l)return make_pair(-1,0);
	if (pl<=l&&r<=pr)return tmx[x];
	return max(query(x1,l,Md),query(x2,Md+1,r));
}
void build(int &x,int l,int r){
	if (!x)x=++t2;
	if (l==r){
		tmx[x]=make_pair(1,-px);
		return;
	}
	if (px<=Md)build(x1,l,Md);
	else build(x2,Md+1,r);
	tmx[x]=max(tmx[x1],tmx[x2]);
}
bool comp(int x,int y){
	return step[x]<step[y];
}
vector<int> que[N];
bool comp2(int x,int y){
	return dep[x]<dep[y];
}
int main(){
	scanf("%s",s+1);n=strlen(s+1);
	cin>>m;
	t=las[1]=t1=1;
	for (int i=1;i<=m;i++){
		scanf("%s",h);
		int now=1,id=i;
		for (int i=0;h[i];i++){
			int x=h[i]-'a';
			if (!tr[now][x]){
				tr[now][x]=++t1;
//				las[tr[now][x]]=extend(las[now],x);
			}
			now=tr[now][x];
			que[now].push_back(id);
			dep[now]=i+1;
//			px=id;
//			build(rt[las[now]],1,m);
		}lp[i]=las[now];
	}
	for (int i=1;i<=t1;i++)r[i]=i;
	sort(r+1,r+t1+1,comp2);
	for (int i=1;i<=t1;i++){
		int x=r[i];
		for (int j=0;j<26;j++)
			if (tr[x][j])
				las[tr[x][j]]=extend(las[x],j);
		for (auto j:que[x])
			px=j,build(rt[las[x]],1,m);
	}
	int now=1;
	for (int i=1;i<=n;i++){
		len[i]=len[i-1];
		while (now&&!trans[now][s[i]-'a'])now=pre[now],len[i]=step[now];
		now=now?trans[now][s[i]-'a']:1;
		ps[i]=now;len[i]++;
	}
	for (int i=1;i<=t;i++)fa[i][0]=pre[i],r[i]=i;
	sort(r+1,r+t+1,comp);
	for (int j=1;j<16;j++)
		for (int i=1;i<=t;i++)
			fa[i][j]=fa[fa[i][j-1]][j-1];
	for (int i=t;i>1;i--)
		rt[pre[r[i]]]=merge(rt[pre[r[i]]],rt[r[i]]);
	for (cin>>q;q--;){
		int l,r;
		scanf("%d%d%d%d",&pl,&pr,&l,&r);
		int k=ps[r];
		if (len[r]<r-l+1){
			printf("%d 0\n",pl);
			continue;
		}
		for (int i=15;i>=0;i--)
			if (step[fa[k][i]]>=(r-l+1))k=fa[k][i];
		pi ans=query(rt[k],1,m);
		if (!ans.second)
			printf("%d 0\n",pl);
		else printf("%d %d\n",-ans.second,ans.first);
	}
}