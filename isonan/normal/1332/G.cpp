#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>

std::vector<int>ans[200001],now1,now2;
std::vector<std::pair<int,int> >que[200001];
int n,q,a[200001];
int stk[2][200001],top[2];
int fst[2][200001];
int cnt[200001];
int c[3][200001];
int mn[200001][21],mx[200001][21],Log[200001];
void update(int ind,int *c){for(int tem=ind;ind<=n;ind+=ind&-ind)c[ind]=std::max(c[ind],tem);}
int query(int ind,int *c){int tot=0;for(;ind>0;ind-=ind&-ind)tot=std::max(tot,c[ind]);return tot;}
int min(int u,int v){return a[u]<a[v]?u:v;}
int max(int u,int v){return a[u]>a[v]?u:v;}
int getmn(int l,int r){
	int k=Log[r-l+1];
	return min(mn[l][k],mn[r-(1<<k)+1][k]);
}
int getmx(int l,int r){
	int k=Log[r-l+1];
	return max(mx[l][k],mx[r-(1<<k)+1][k]);
}
int read(){
	int x=0;
//	scanf("%d",&x);
	char ch=getchar();
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
	return x;
}
void write(const int &x){
	if(x>9)write(x/10);
	putchar((x%10)+'0');
}
int main(){
	n=read(),q=read();
	for(int i=2;i<=n;i++)Log[i]=Log[i>>1]+1;
	for(int i=1;i<=n;i++)a[i]=read(),cnt[i]=2,mn[i][0]=mx[i][0]=i;
	for(int j=1;(1<<j)<=n;j++)
		for(int i=1;i+(1<<j)-1<=n;i++)
			mn[i][j]=min(mn[i][j-1],mn[i+(1<<(j-1))][j-1]),
			mx[i][j]=max(mx[i][j-1],mx[i+(1<<(j-1))][j-1]);
	for(int i=1,l,r;i<=q;i++){
		l=read(),r=read();
		que[r].push_back(std::make_pair(l,i));
	}
	for(int i=1;i<=n;i++){
		std::vector<int>tem1,tem2;
		while(top[0]&&a[stk[0][top[0]]]<a[i]){
			int v=stk[0][top[0]];
			if(!(--cnt[v]))update(v,c[2]);
			update(v,c[0]);
			--top[0];
		}
		while(top[1]&&a[stk[1][top[1]]]>a[i]){
			int v=stk[1][top[1]];
			if(!(--cnt[v]))update(v,c[2]);
			update(v,c[1]);
			--top[1];
		}
		for(int fd=0;fd<2;fd++)
			fst[fd][i]=(a[i]==a[stk[fd][top[fd]]])?fst[fd][stk[fd][top[fd]]]:stk[fd][top[fd]];
		stk[0][++top[0]]=stk[1][++top[1]]=i;
		int p,q;
		if(q=query(fst[0][i]-1,c[0])){
			tem2.push_back(q);
			if(a[getmn(q+1,i-1)]<std::min(a[q],a[i]))tem2.push_back(getmn(q+1,i-1));
			if(a[getmx(q+1,i-1)]>std::max(a[q],a[i]))tem2.push_back(getmx(q+1,i-1));
			tem2.push_back(i);
		}
		if(q=query(fst[1][i]-1,c[1])){
			if(!tem2.size()||tem2[0]<q){
				tem2.clear();
				tem2.push_back(q);
				if(a[getmn(q+1,i-1)]<std::min(a[q],a[i]))tem2.push_back(getmn(q+1,i-1));
				if(a[getmx(q+1,i-1)]>std::max(a[q],a[i]))tem2.push_back(getmx(q+1,i-1));
				tem2.push_back(i);
			}
		}
		p=std::min(fst[0][i],fst[1][i])-1,q=query(p,c[2]);
//		printf("%d %d\n",i,q);
		if(q){
			tem1.push_back(q);
			tem1.push_back(getmn(q+1,i-1));
			tem1.push_back(getmx(q+1,i-1));
			tem1.push_back(i);
			std::sort(tem1.begin(),tem1.end());
		}
		if(tem1.size()&&(!now1.size()||now1[0]<tem1[0]))now1=tem1;
		if(tem2.size()&&(!now2.size()||now2[0]<tem2[0]))now2=tem2;
		for(int j=0;j<que[i].size();j++){
			if(now1.size()&&que[i][j].first<=now1[0])ans[que[i][j].second]=now1;
			else if(now2.size()&&que[i][j].first<=now2[0])ans[que[i][j].second]=now2;
		}
	}
		for(int i=1;i<=q;i++){
			write((int)ans[i].size());putchar('\n');
			for(int j=0;j<(int)ans[i].size();j++)write(ans[i][j]),putchar(' ');putchar('\n');
		}
}