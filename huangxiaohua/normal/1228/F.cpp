#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,a[300500],x,y,num[300500],vis[300500],res,dep[300500],ans;
bool chk[300500];
vector<int> v[300500];
queue<int> q,q2;

void dfs0(int x,int fa){
	dep[x]=dep[fa]+1;
	if(dep[x]==n){return;}
	for(auto i:v[x]){
		if(i==fa){continue;}
		dfs0(i,x);
	}
}

void work0(){
	for(i=1;i<=m-2;i++){
		if(a[i]==1){vis[i]=1;q.push(i);}
	}
	for(t=1;t<n-1;t++){
		while(!q.empty()){
			x=q.front();q.pop();
			for(auto i:v[x]){
				if(vis[i]){continue;}
				a[i]--;
				if(a[i]==1){q2.push(i);vis[i]=1;}
			}
		}
		swap(q,q2);
	}
	for(i=1;i<=m-2;i++){
		if(!vis[i]){
			if(res){puts("0");return;}
			res=i;
		}
	}
	dfs0(res,0);
	for(i=1;i<=m-2;i++){
		if(dep[i]==1){if(v[i].size()!=2){puts("0");return;}continue;}
		if(dep[i]>n){puts("0");return;}
		if(dep[i]==n){continue;}
		if(dep[i]==n-1&&v[i].size()==2){if(ans){puts("0");return;}ans=i;continue;}
		if(v[i].size()!=3){puts("0");return;}
	}
	if(!ans){puts("0");}
	else{printf("1\n%d",ans);}
}

void dfs11(int x,int fa,int z){
	dep[x]=dep[fa]+1+z;
	if(dep[x]>n){
		puts("0");exit(0);
	}
	else{
		if(dep[x]==n){
			if(v[x].size()!=1){chk[x]=0;return;}
			chk[x]=1;return;
		}
		else{
			if(v[x].size()!=3){chk[x]=0;return;}
		}
	}
	int y=1;
	for(auto i:v[x]){
		if(i==fa){continue;}
		dfs11(i,x,0);
		y&=chk[i];
	}
	chk[x]=y;
}

void dfs1(int x,int fa){
	dep[x]=dep[fa]+1;
	if(dep[x]==1){
		if(v[x].size()!=2){
			puts("0");exit(0);
		}
	}
	else{
		if(dep[x]>n){
			puts("0");exit(0);
		}
		else{
			if(dep[x]==n){
				if(v[x].size()!=1){chk[x]=0;return;}
				chk[x]=1;return;
			}
			else{
				if(x!=ans){
					if(v[x].size()!=3){chk[x]=0;return;}
				}
			}
		}
	}
	bool y=1;
	int no=2;
	for(auto i:v[x]){
		if(i==fa){continue;}
		dfs1(i,x);
		if(!chk[i]){
			if(x==ans){
				no--;dfs11(i,x,1);
			}
		}
		y&=chk[i];
	}
	if(x==ans){
		if(no){return;}
		chk[x]=y;return;
	}
	chk[x]=y;
}

void work1(){
	for(i=1;i<=m-2;i++){
		if(a[i]==1){vis[i]=1;q.push(i);}
		if(a[i]==4){vis[i]=1;ans=i;}
	}
	for(t=1;t<=n-1;t++){
		while(!q.empty()){
			x=q.front();q.pop();
			for(auto i:v[x]){
				if(vis[i]){continue;}
				a[i]--;
				if(a[i]==1){q2.push(i);vis[i]=1;}
			}
		}
		swap(q,q2);
	}
	if(q.empty()){
		puts("0");return;
	}
	res=q.front();
	dfs1(res,0);
	if(chk[res]){
		printf("1\n%d",ans);
	}
	else{
		puts("0");
	}
}

void dfs22(int x,int fa,int z){
	dep[x]=dep[fa]+1+z;
	if(dep[x]>n){
		chk[x]=0;return;
	}
	else{
		if(dep[x]==n){
			if(v[x].size()!=1){chk[x]=0;return;}
			chk[x]=1;return;
		}
		else{
			if(v[x].size()!=3){chk[x]=0;return;}
		}
	}
	int y=1;
	for(auto i:v[x]){
		if(i==fa){continue;}
		dfs22(i,x,0);
		y&=chk[i];
	}
	chk[x]=y;
}

void dfs2(int x,int fa){
	dep[x]=dep[fa]+1;
	if(dep[x]==1){
		if(v[x].size()!=3){return;}
	}
	else{
		if(dep[x]>n){return;}
		else{
			if(dep[x]==n){
				if(v[x].size()!=1){chk[x]=0;return;}
				chk[x]=1;return;
			}
			else{
				if(v[x].size()!=3){chk[x]=0;return;}
			}
		}
	}
	bool y=1;
	int no=2;
	for(auto i:v[x]){
		if(i==fa){continue;}
		dfs2(i,x);
		if(!chk[i]){
			if(dep[x]==1){
				no--;dfs22(i,x,1);
			}
		}
		y&=chk[i];
	}
	if(x==ans){
		if(no){return;}
		chk[x]=y;return;
	}
	chk[x]=y;
}

void work2(){
	for(i=1;i<=m-2;i++){
		if(a[i]==1){vis[i]=1;q.push(i);}
	}
	for(t=1;t<n-2;t++){
		while(!q.empty()){
			x=q.front();q.pop();
			for(auto i:v[x]){
				if(vis[i]){continue;}
				a[i]--;
				if(a[i]==1){q2.push(i);vis[i]=1;}
			}
		}
		swap(q,q2);
	}
	vector<int> vv;
	for(i=1;i<=m-2;i++){
		if(!vis[i]){
			memset(dep,0,sizeof(dep));
			memset(chk,0,sizeof(chk));
			res=i;
			dfs2(res,0);
			if(chk[res]){
				vv.push_back(res);
			}
		}
	}
	printf("%d\n",vv.size());
	for(auto i:vv){
		printf("%d ",i);
	}
}

int main(){
	scanf("%d",&n);
	if(n==2){
		printf("2\n1 2");return 0;
	}
	m=(1<<n);
	for(i=1;i<=m-3;i++){
		scanf("%d%d",&x,&y);
		a[x]++;a[y]++;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	for(i=1;i<=m-2;i++){
		num[a[i]]++;
	}
	if(num[1]==((1<<n)/2-1)){
		work0();return 0;
	}
	if(num[4]==1){
		work1();return 0;
	}
	if(num[2]==0){
		work2();return 0;
	}
	puts("0");
}