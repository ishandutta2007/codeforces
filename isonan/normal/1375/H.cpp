#include <algorithm>
#include <cstdio>
#include <vector>
#include <cmath>

int n,q,a[5001],l[200001],r[200001],cnt;
int set[51][301][301],top,val[301][301][301],fin[1000001];
int mn[301][5001];
std::vector<std::pair<int,int> >ans;
int merge(int a,int b){
	ans.push_back(std::make_pair(a,b));
	return ++cnt;
}
void solve(std::vector<std::pair<int,int> >&a,int vl,int vr,int now[301][301]){
//	printf("%d %d %d %d %d\n",a.size(),vl,vr,a[0].first,a[1].first);
	if(a.size()==1){
		now[0][0]=a[0].first;
		return;
	}
	if(!a.size())return;
	std::vector<std::pair<int,int> >L,R;
	int vmid=(vl+vr)>>1;
	for(int i=0;i<a.size();i++)
		if(a[i].second<=vmid)L.push_back(a[i]);
		else R.push_back(a[i]);
	++top;
	solve(L,vl,vmid,set[top]);
	++top;
	solve(R,vmid+1,vr,set[top]);
	for(int i=0;i<a.size();i++)
		for(int j=i;j<a.size();j++){
			int l=std::lower_bound(L.begin(),L.end(),std::make_pair(a[i].first,0))-L.begin(),
				r=std::lower_bound(L.begin(),L.end(),std::make_pair(a[j].first+1,0))-L.begin()-1,x=0;
			if(l<=r)x=set[top-1][l][r];
				l=std::lower_bound(R.begin(),R.end(),std::make_pair(a[i].first,0))-R.begin(),
				r=std::lower_bound(R.begin(),R.end(),std::make_pair(a[j].first+1,0))-R.begin()-1;
			if(l<=r&&x)x=merge(x,set[top][l][r]);
			else x|=set[top][l][r];
			now[i][j]=x;
		}
	top-=2;
}
std::vector<std::pair<int,int> >vec[5001];
int read(){
	int x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
	return x;
}
void write(int x){
	if(x>9)write(x/10);
	putchar((x%10)+'0');
}
int main(){
//	freopen("in.txt","r",stdin);
	n=read(),q=read();
	cnt=n;
	for(int i=1;i<=n;i++)a[i]=read();
	int block=256;
	for(int i=1;i<=n;i++)vec[(a[i]-1)/block+1].push_back(std::make_pair(i,a[i]));
	for(int i=1;i<=(n-1)/block+1;i++){
		solve(vec[i],(i-1)*block+1,std::min(i*block,n),val[i]);
		for(int j=1;j<=n+1;j++){
			mn[i][j]=std::lower_bound(vec[i].begin(),vec[i].end(),std::make_pair(j,0))-vec[i].begin();
		}
	}
	for(int i=1,l,r;i<=q;i++){
		l=read(),r=read();
		int x=0;
		for(int j=1;j<=(n-1)/block+1;j++){
			int L=mn[j][l],R=mn[j][r+1]-1;
			if(L<=R&&x)x=merge(x,val[j][L][R]);
			else x|=val[j][L][R];
		}
		fin[i]=x;
	}
	write(cnt);putchar('\n');
	for(int i=0;i<ans.size();i++)write(ans[i].first),putchar(' '),write(ans[i].second),putchar('\n');
	for(int i=1;i<=q;i++)write(fin[i]),putchar(' ');
}