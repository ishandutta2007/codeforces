#include<bits/stdc++.h>
#define fi first
#define se second
#define LL long long
#define PI std::pair<int,int>
#define MP std::make_pair
int n,s[50005][5],t[5][50005],tmp[50005];
bool ok[50005];
bool chk(int x,int y){
	int c=0;
	for(int i=0;i<5;i++) if(s[x][i]<s[y][i])c++;
	return c>=3;
}
void work(int x){
	bool o=ok[x];
	for(int i=1;i<=n;i++) if(!chk(i,x))ok[i]=0;
	else o=0;
	ok[x]=o;
}
int main(){
	std::mt19937 ran(111);
	int T;
	for(scanf("%d",&T);T--;){
		scanf("%d",&n);
		for(int i=1;i<=n;i++) for(int j=0;j<5;j++)scanf("%d",s[i]+j),t[j][i]=s[i][j];
		for(int i=1;i<=n;i++)ok[i]=1;
		for(int i=0;i<5;i++){
			int pos=std::min_element(t[i]+1,t[i]+n+1)-t[i];
			work(pos);
		}
		while(1){
			int c=0;
			for(int i=1;i<=n;i++) if(ok[i])tmp[c++]=i;
			if(c<=1){
				if(!c){
					puts("-1");
					break;
				}
			}
			work(tmp[ran()%c]);
			if(c==1){
				int c=0;
				for(int i=1;i<=n;i++) if(ok[i])tmp[c++]=i;
				if(!c)puts("-1");
				else printf("%d\n",tmp[0]);
				break;
			}
		}
	}
}