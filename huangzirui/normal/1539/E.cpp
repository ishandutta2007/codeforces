#include<bits/stdc++.h>
#define pii pair<int,int>
#define ll long long
using namespace std;
inline int read(){
	char c=getchar();int x=0,f=1;
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
    return x*f;
}
const int maxn=100010;
int i,j,k,n,m,T,a[maxn][2],b[maxn][2],w[maxn],s[maxn][2],Ans[maxn];
set<pii>S[2];
set<pii>::iterator it;
pii getmin(int id){
	pii w=*S[id].begin();
	return w;
}
pii getmax(int id){
	it=S[id].end();it--;
	pii w=*it;
	return w;
}
void make_erase(int id,pii p){
//	cout<<"ERASE"<<endl;
	S[id].erase(S[id].find(p));
}
int dfs(int now,pii x,pii y){
//	cout<<now<<' '<<x.first<<' '<<x.second<<' '<<y.first<<' '<<y.second<<endl;
	if(now>n)return 1;
	int c=0,S[2]={0,1};
	pii ans[2];
	ans[0]=(pii){x.first,s[now][1]};
	ans[1]=(pii){s[now][0],y.second};
	x=ans[0];y=ans[1];
	if(x.first<y.first && x.second<y.second)x=y,S[0]=S[1];
	if(x.first>y.first && x.second>y.second)y=x,S[1]=S[0];
	if(x.first<y.first)swap(x,y),swap(S[0],S[1]);
	if(x.second>y.second)swap(x,y),swap(S[0],S[1]);
	if(x.first<=now || x.second<=now)c++;
	if(y.first<=now || y.second<=now)c+=2;
	if(c==3)return -1;
	if(c==1)x=y,S[0]=S[1];
	if(c==2)y=x,S[1]=S[0];
	int w=dfs(now+1,x,y);
	if(w<0)return -1;
	Ans[now]=1-S[w];
	return S[w];
}
int main(){
	cin>>n>>m;
	S[0].insert(make_pair(0,0));
	S[1].insert(make_pair(0,0));
	for(i=1;i<=n;i++){
		w[i]=read();
		S[0].insert(make_pair(w[i],i));
		S[1].insert(make_pair(w[i],i));
		a[i][0]=read();
		a[i][1]=read();
		b[i][0]=read();
		b[i][1]=read();
		while(S[0].size() && getmin(0).first<a[i][0]){
			pii w=getmin(0);
			make_erase(0,w);
			s[w.second][0]=i;
		}
		while(S[0].size() && getmax(0).first>a[i][1]){
			pii w=getmax(0);
			make_erase(0,w);
			s[w.second][0]=i;
		}
		while(S[1].size() && getmin(1).first<b[i][0]){
			pii w=getmin(1);
			make_erase(1,w);
			s[w.second][1]=i;
		}
		while(S[1].size() && getmax(1).first>b[i][1]){
			pii w=getmax(1);
			make_erase(1,w);
			s[w.second][1]=i;
		}
	}
	while(S[0].size()){
		pii w=getmin(0);
		make_erase(0,w);
		s[w.second][0]=n+1;
	}
	while(S[1].size()){
		pii w=getmin(1);
		make_erase(1,w);
		s[w.second][1]=n+1;
	}
//	cout<<endl;
//	for(i=1;i<=n;i++)cout<<s[i][0]<<' '<<s[i][1]<<endl;
	if(dfs(1,(pii){s[0][0],s[0][1]},(pii){s[0][0],s[0][1]})<0)puts("No");
	else{
		puts("Yes");
		for(i=1;i<=n;i++)printf("%d ",Ans[i]);
		puts("");
	}
	return 0;
}