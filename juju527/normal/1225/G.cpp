//Code by juju527.
#include<bits/stdc++.h>
typedef long long ll;
#define pii pair<int,int>
#define fi first
#define se second
#define vec vector<int>
#define eb emplace_back
using namespace std;
const int maxn=25,maxs=(1<<16)+5,maxk=2005;
int n,k,sum;
int a[maxn],b[maxn];
bitset<maxk> f[maxs];
int read(){
    int x=0,y=1;
    char ch=getchar();
    while(ch<48||ch>57){if(ch==45)y=-1;ch=getchar();}
    while(ch>=48&&ch<=57)x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
    return x*y;
}
void dfs(int s,int x){
	if(!s)return ;
	int tag=0;
	for(int i=x*k;i<=sum;i*=k)if(f[s][i])x=i,tag++;
	for(int i=0;i<n;i++)if((s>>i)&1)b[i]+=tag;
	for(int i=0;i<n;i++){
		if(!((s>>i)&1))continue;
		if(x>=a[i]&&f[s^(1<<i)][x-a[i]]){dfs(s^(1<<i),x-a[i]);break;}
	}
	return ;
}
struct node{
	int a,b;
	bool operator <(node i)const{return b<i.b;}
};
priority_queue<node> q;
int main(){
	n=read();k=read();
	for(int i=0;i<n;i++)a[i]=read(),sum+=a[i];
	int S=(1<<n)-1;
	f[0].set(0);
	for(int s=1;s<=S;s++){
		for(int x=0;x<n;x++)if((s>>x)&1)f[s]|=(f[s^(1<<x)]<<a[x]);
		for(int v=sum/k;v>=1;v--)f[s].test(v*k)?f[s].set(v):0;
	}
	if(!f[S][1]){puts("NO");return 0;}
	puts("YES");
	dfs(S,1);
	for(int i=0;i<n;i++)q.push((node){a[i],b[i]});
	while(q.size()){
		node u,v;
		u=q.top();q.pop();
		v=q.top();q.pop();
		printf("%d %d\n",u.a,v.a);
		int x=u.a+v.a,c=0;
		while(x%k==0)x/=k,c++;
		if(x==1&&u.b-c==0)break;
		q.push((node){x,u.b-c});
	}
    return 0;
}