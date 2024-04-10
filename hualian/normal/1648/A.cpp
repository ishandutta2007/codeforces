#include<bits/stdc++.h>
#define int long long
#define x first
#define y second
#define For(i,a,b) for(int i=a,i##end=b;i<=i##end;i++)
#define Rof(i,a,b) for(int i=a,i##end=b;i>=i##end;i--)
#define rep(i,  b) for(int i=1,i##end=b;i<=i##end;i++)
using namespace std;
typedef pair<int,int> PI;
const int N=2e5+9;
int a[N],m,n,t;
int ans;vector<PI>id[N];
map<int,int>cnt;
void chmx(int &x,int y){(x<y)&&(x=y);}
void chmn(int &x,int y){(x>y)&&(x=y);}
int read(){
	int f=0,x=0;
	char ch=getchar();
	while(!isdigit(ch)){f|=(ch=='-');ch=getchar();}
	while(isdigit(ch)){x=x*10+ch-'0';ch=getchar();}
	return f?-x:x;
}
signed main(){
	n=read(),m=read();
	rep(i,n)for(int j=1,x;j<=m;++j){
		x=read();
		id[x].push_back(make_pair(i,j));
	}
	rep(i,100000)if(id[i].size()){
		cnt.clear();int last=0;
		for(PI j:id[i])++cnt[j.x];
		for(PI j:cnt){
			ans+=last*j.x*j.y;
			last+=j.y;
			ans-=(id[i].size()-last)*j.x*j.y;
		}cnt.clear();
		for(const PI &j:id[i])++cnt[j.y];last=0;
		for(PI j:cnt){
			ans+=last*j.x*j.y;
			last+=j.y;
			ans-=(id[i].size()-last)*j.x*j.y;
		}
	}
	printf("%lld",ans);
	return 0;
}