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
}P[maxn];
bool cmp(per a,per b){
	return a.sit<b.sit || (a.sit==b.sit && a.id>b.id);
}
int is[maxn];
int main(){
	cin>>T;
	while(T--){
		cin>>n>>m;
		for(i=1;i<=m;i++)P[i]={i,read()};
		sort(P+1,P+1+m,cmp);
		for(i=1;i<=m;i++)is[i]=P[i].id;
		int ans=0;
		for(i=1;i<=m;i++){
			for(j=1;j<i;j++){
				if(is[j]<is[i])++ans;
			}
		}printf("%d\n",ans);
	}
	return 0;
}