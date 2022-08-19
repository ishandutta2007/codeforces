#include <cstdio>
#include <set>

char ans[100001];
int n;
int read(){
	int x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
	return x;
}
int query(const char *str,bool bb=0){
	printf("? %s\n",str);
	fflush(stdout);
	int k,ans=0;
	k=read();
	for(int i=1,pos;i<=k;i++){
		pos=read();
		if(bb==0&&i==1)ans=pos;
		else if(bb)ans=pos;
	}
	return k?ans:-1;
}
int query(int l,int r){
//	printf("query %d %d\n",l,r);
	printf("? ");
	for(int i=l;i<=r;i++)putchar(ans[i]);putchar('\n');
	fflush(stdout);
	int k,ans=0;
	k=read();
	for(int i=1,pos;i<=k;i++){
		pos=read();
		if(i==1)ans=pos;
	}
	return k?ans:-1;
}
char str[4]="HOC";
void solve1(int l,int r){
//	printf("%d %d\n",l,r);
	if(l==1&&r==n)return;
	if(r==n){
		for(int i=0;i<2;i++){
			ans[l-1]=str[i];
			if(query(l-1,r)==l-1)break;
			else ans[l-1]=str[i+1];
		}
		solve1(l-1,r);
	}
	else{
		for(int i=0;i<2;i++){
			ans[r+1]=str[i];
			if(query(l,r+1)==l)break;
			else ans[r+1]=str[i+1];
		}
		solve1(l,r+1);
	}
}
void solve2(int l,int r,int ind){
	if(l==1)return;
	if(ind==0){
		for(int i=1;i<l;i++)ans[i]=str[ind];
		return;
	}
	else{
		int i=ind;
		for(i=ind;i;--i){
			ans[l-1]=str[i];
			if(query(l-1,r)==l-1)break;
		}
		ans[l-1]=str[i];
		solve2(l-1,r,i);
	}
}
void solve3(int l,int r){
	if(r==n)return;
	ans[r+1]='C';
	if(query(l,r+1)!=l)ans[r+1]='O';
	solve3(l,r+1);
}
void out(int n){
	printf("! ");
	for(int i=1;i<=n;i++)putchar(ans[i]);putchar('\n');
	fflush(stdout);
}
int top,cnt;
bool good;
void dfs(int x,int n){
	if(good)return;
	if(x==3){
		if(n==top){
			++cnt;
			if(cnt==6||query(1,n)!=-1)
				good=1;
		}
		return;
	}
	for(int i=0;i<=2;i++){
		top+=i;
		for(int j=0;j<i;j++)ans[top-j]=str[x];
		dfs(x+1,n);
		top-=i;
		if(good)return;
	}
}
int T;
int main(){
	T=read();
	for(int fd=1;fd<=T;fd++){
		n=read();
		int tem;
		if((tem=query("CH"))!=-1){
			int v=tem;
			ans[v]='C';
			ans[v+1]='H';
			solve1(v,v+1);
		}
		else if((tem=query("OH"))!=-1){
			int v=tem;
			ans[v]='O';
			ans[v+1]='H';
			solve1(v,v+1);
		}
		else if((tem=query("CO"))!=-1){
			int v=tem;
			ans[v]='C';
			ans[v+1]='O';
			solve2(v,v+1,2);
			solve3(1,v+1);
		}
		else if((tem=query("OOO"))!=-1){
			int v=tem;
			for(int i=1;i<v;i++)ans[i]='H';
			ans[v]=ans[v+1]=ans[v+2]='O';
			solve3(1,v+2);
		}
		else if((tem=query("CCC"))!=-1){
			int v=tem;
			for(int i=v;i<=n;i++)ans[i]='C';
			solve2(v,n,1);
		}
		else if((tem=query("HHH",1))!=-1){
			int v=tem+2;
			for(int i=1;i<=v;i++)ans[i]='H';
			solve3(1,v);
		}
		else{
			good=0;
			cnt=0;
			dfs(0,n);
		}
		out(n);
		read();
		top=0;
	}
}