#include<bits/stdc++.h>
#define ll long long
using namespace std;
inline int read(){
	char c=getchar();int x=0,f=1;
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
    return x*f;
}
const int maxn=310;
int i,j,k,n,m,T;
struct per{
	int id,sit;
}P[maxn*maxn];
bool cmp(per a,per b){
	return a.sit<b.sit || (a.sit==b.sit && a.id>b.id);
}
bool cmp2(per a,per b){
	return a.sit<b.sit || (a.sit==b.sit && a.id>b.id);
}
int is[maxn][maxn];
int tree[maxn][maxn],rk[maxn];
int lowbit(int x){
	return x&(-x);
}
int find(int x,int id){
	int ans=0;for(;x;x-=lowbit(x))ans+=tree[x][id];return ans;
}
void add(int x,int s,int id){
	for(;x<=m;x+=lowbit(x))tree[x][id]+=s;
}
int main(){
	cin>>T;
	while(T--){
		memset(tree,0,sizeof(tree));
		cin>>n>>m;
		for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)P[i*m+j-m]={i*m+j-m,read()};
		sort(P+1,P+1+n*m,cmp);
		int last=1;
		for(i=1;i<=n;i++)
		for(j=1;j<=m+(i==n);j++){
			if(last && (j==m+1 || P[last].sit!=P[i*m+j-m].sit)){
//				cout<<last<<" ~ "<<(i*m+j-m)-1<<endl;
				reverse(P+last,P+(i*m+j-m));
				last=i*m+j-m;
			}
		}
		for(i=1;i<=n;i++)
			sort(P+i*m-m+1,P+i*m+1,cmp);
		for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
			is[n-i+1][j]=P[i*m+j-m].id;
		int ans=0;
		for(i=1;i<=n;i++){
			is[i][m+1]=1185151212;	
			for(j=1;j<=m;j++){
				rk[j]=is[i][j];
			}sort(rk+1,rk+1+m);
			for(j=1;j<=m;j++){
				int t=lower_bound(rk+1,rk+m+1,is[i][j])-rk;
				ans+=find(t,i);
//				cout<<is[i][j]<<' '<<t<<' '<<m<<endl;
				add(t,1,i);
			}//cout<<ans<<endl;
		}printf("%d\n",ans);
	}
	return 0;
}