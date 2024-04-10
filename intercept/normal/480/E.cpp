#include<bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
const int M=2009;
int n,m,q,ans=0;
int lm[M][M],rm[M][M],ql[M],qr[M];
char s[M][M];
vector<pii>op;
vector<int>sum;
void change(int x){
	rm[x][m+1]=m+1;
	for(int i=1;i<=m;++i)lm[x][i]=s[x][i]=='X'?i:lm[x][i-1];
	for(int i=m;i>=1;--i)rm[x][i]=s[x][i]=='X'?i:rm[x][i+1];
}
bool ask(int x,int li){
	int lb=1,le=0,rb=1,re=0;
	for(int i=1;i<=n;++i){
		while(le>=lb&&i-ql[lb]+1>li)lb++;
		while(re>=rb&&i-qr[rb]+1>li)rb++;
		while(le>=lb&&lm[i][x]>lm[ql[le]][x])le--;
		while(re>=rb&&rm[i][x]<rm[qr[re]][x])re--;
		ql[++le]=i;
		qr[++re]=i;
		if(i>=li&&rm[qr[rb]][x]-lm[ql[lb]][x]-1>=li)return 1;
	}
	return 0;
}
int main(){
	scanf("%d%d%d",&n,&m,&q);
	for(int i=1;i<=n;++i)scanf("%s",s[i]+1);
	for(int i=1,x,y;i<=q;++i){
		scanf("%d%d",&x,&y);
		s[x][y]='X';
		op.push_back({x,y});
	}
	for(int i=1;i<=n;++i)change(i);
	for(int i=1;i<=m;++i)while(ask(i,ans+1))ans++;
	reverse(op.begin(),op.end());
	for(auto o:op){
		sum.push_back(ans);
		int x=o.first,y=o.second;
		s[x][y]='.';
		change(x);
		while(ask(y,ans+1))ans++;
	}
	reverse(sum.begin(),sum.end());
	for(auto o:sum)printf("%d\n",o);
	return 0;
}