#include<bits/stdc++.h>
#define ll __int128
using namespace std;
const int M=1e3+9;
ll a[M],b[M];
ll Tn[M][M<<1],Tm[M][M<<1];
bool vis[M][2];
void push(ll* t,int x,ll y,int z){
	for(t[x+=z-1]=y;x;x>>=1)t[x>>1]=t[x]/__gcd(t[x],t[x^1])*t[x^1];
}
void rd(ll&x){
	x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
}
void wr(ll x){
	string s;
	while(x)s.push_back('0'+x%10),x/=10;
	reverse(s.begin(),s.end());
	cout<<s<<" ";
}
void work(){
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;++i)rd(a[i]);
	for(int i=1;i<=m;++i)rd(b[i]);
	for(int i=0;i<=n;++i){
		for(int j=0;j<=m<<1;++j)Tn[i][j]=1;
	}
	for(int i=0;i<=m;++i){
		for(int j=0;j<=n<<1;++j)Tm[i][j]=1;
	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			push(Tn[i],j,__gcd(a[i],b[j]),m);
		}
		
	}
	for(int i=1;i<=m;++i){
		for(int j=1;j<=n;++j){
			push(Tm[i],j,__gcd(b[i],a[j]),n);
		}
	}
	queue<pair<int,int>>q;
	for(int i=1;i<=n;++i){
		if(Tn[i][1]!=a[i])q.push(make_pair(i,0)),vis[i][0]=0;
		else vis[i][0]=1;
	}
	for(int i=1;i<=m;++i){
		if(Tm[i][1]!=b[i])q.push(make_pair(i,1)),vis[i][1]=0;
		else vis[i][1]=1;
	}
	
	while(!q.empty()){
		auto o=q.front();
		q.pop();
		if(o.second==0){
			for(int i=1;i<=m;++i){
				if(vis[i][1]){
					push(Tm[i],o.first,1,n);
					if(Tm[i][1]!=b[i])vis[i][1]=0,q.push(make_pair(i,1));
				}
			}
		}
		else{
			for(int i=1;i<=n;++i){
				if(vis[i][0]){
					push(Tn[i],o.first,1,m);
					if(Tn[i][1]!=a[i])vis[i][0]=0,q.push(make_pair(i,0));
				}
			}
		}
	}
	int l1=0,l2=0;
	for(int i=1;i<=n;++i)if(vis[i][0])l1++;
	for(int i=1;i<=m;++i)if(vis[i][1])l2++;
	if(!l1||!l2){
		puts("NO");
		return;
	}
	puts("YES");
	cout<<l1<<" "<<l2<<endl;
	for(int i=1;i<=n;++i)if(vis[i][0])wr(a[i]);
	puts("");
	for(int i=1;i<=m;++i)if(vis[i][1])wr(b[i]);
	puts("");
}
int main(){
	
	int T;
	cin>>T;
	while(T--)work();
	return 0;
}