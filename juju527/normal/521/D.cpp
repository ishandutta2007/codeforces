//Code by juju527.
#include<bits/stdc++.h>
typedef long long ll;
typedef double db;
#define pii pair<int,int>
#define fi first
#define se second
#define vec vector<int>
#define eb emplace_back
using namespace std;
const int maxn=1e5+5;
int a[maxn];
pii val[maxn];
vector<pii> add[maxn];
int read(){
    int x=0,y=1;
    char ch=getchar();
    while(ch<48||ch>57){if(ch==45)y=-1;ch=getchar();}
    while(ch>=48&&ch<=57)x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
    return x*y;
}
priority_queue<pair<db,int>> q;
int op[maxn],res[maxn];
bool cmp(int i,int j){return op[i]<op[j];}
int main(){
    int k,n,m;
	k=read();n=read();m=read();
	for(int i=1;i<=k;i++)a[i]=read();
	for(int i=1;i<=n;i++){
		int opt,x,b;
		opt=read();x=read();b=read();
		op[i]=opt;
		if(opt==1)val[x]=max(val[x],pii(b,i));
		else if(opt==2)add[x].eb(pii(b,i));
		else q.push(make_pair(b,i));
	}
	for(int i=1;i<=k;i++){
		if(val[i].fi>a[i])add[i].eb(pii(val[i].fi-a[i],val[i].se));
		sort(add[i].begin(),add[i].end());
		ll w=a[i];
		for(int j=add[i].size()-1;j>=0;j--){
			q.push(make_pair(1.0*(w+add[i][j].fi)/w,add[i][j].se));
			w+=add[i][j].fi;
		}
	}
	int len=0;
	while(q.size()&&len<m){
		db v=q.top().fi;
		int id=q.top().se;
		q.pop();
		if(v<1)break;
		res[++len]=id;
	}
	sort(res+1,res+len+1,cmp);
	printf("%d\n",len);
	for(int i=1;i<=len;i++)printf("%d ",res[i]);
	puts("");
    return 0;
}