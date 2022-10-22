#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
using namespace std;
const int maxn=50005;
int r[maxn][6],ban[maxn];
vector<int> s;
int read(){
    int x=0,y=1;
    char ch=getchar();
    while(ch<48||ch>57){if(ch==45)y=-1;ch=getchar();}
    while(ch>=48&&ch<=57)x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
    return x*y;
}
bool battle(int x,int y){
	int ans=0;
	for(int i=1;i<=5;i++)ans+=r[x][i]<r[y][i];
	return ans>=3;
}
int main(){
	int T;
	T=read();
	while(T--){
		int n;
		n=read();
		s.resize(n);
		for(int i=1;i<=n;i++)s[i-1]=i,ban[i]=0;
		for(int i=1;i<=n;i++)for(int j=1;j<=5;j++)r[i][j]=read();
		int cur=0;
		for(int i=1;i<=n;i++){
			if(ban[i])continue;
			while(s.size()>1){
				int j=s.back();
				if(j==i)swap(s[s.size()-1],s[0]);
				if(ban[j]){s.pop_back();continue;}
				if(battle(i,j))s.pop_back(),ban[j]=1,cur++;
				else{ban[i]=1;cur++;break;}
			}
		}
		int x=s[0];
		for(int i=1;i<=n;i++)if(i!=x&&!battle(x,i)){x=-1;break;}
		printf("%d\n",x);
	}
    return 0;
}