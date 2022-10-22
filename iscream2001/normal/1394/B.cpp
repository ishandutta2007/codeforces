#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
#include<set>
#define LL long long
using namespace std;
const int N=2e5+10;
int read(){
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
void print(LL x){
    if(x>9) print(x/10);
    putchar(x%10+'0');
}
int n,m,k;
int D[N],ru[N],cu[N];
struct edge{
	int l,r,val;
}e[N];
bool cmp(edge A,edge B){
	return A.val<B.val;
}
vector<int> r[N],s[10];
bool flag[10][10];
bool dp[10][10][10][10];
int c[10];
int ans=0;
void find(int cs){
	if(cs>k){
		++ans;
		return;
	}
	for(int i=1;i<=cs;++i){
		if(!flag[cs][i]) continue;
		c[cs]=i;
		bool fff=0;
		for(int p=1;p<cs;++p){
			if(!dp[cs][c[cs]][p][c[p]]) fff=1;
		}
		if(!fff) find(cs+1);
	}
	return;
}

int main(){
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;++i){
		scanf("%d%d%d",&e[i].l,&e[i].r,&e[i].val);
	}
	sort(e+1,e+1+m,cmp);
	for(int i=1;i<=m;++i){
		++D[e[i].l];
		r[e[i].l].push_back(e[i].r);
	}
	for(int i=1;i<=n;++i){
		s[D[i]].push_back(i);
	}
	int x,y;
	bool ff;
	for(int i=1;i<=k;++i){
		for(int j=1;j<=i;++j){
			ff=0;
			for(int a=0;a<s[i].size();++a){
				x=s[i][a];
				y=r[x][j-1];
				cu[x]++;
				ru[y]++;
				if(cu[x]>1) ff=1;
				if(ru[y]>1) ff=1;
			}
			for(int a=0;a<s[i].size();++a){
				x=s[i][a];
				y=r[x][j-1];
				cu[x]--;
				ru[y]--;
			}
			if(!ff) flag[i][j]=1;
		}
	}
	for(int i=1;i<=k;++i){
		for(int j=1;j<=i;++j){
			if(!flag[i][j]) continue;
			for(int a=0;a<s[i].size();++a){
				x=s[i][a];
				y=r[x][j-1];
				cu[x]++;
				ru[y]++;
			}
			for(int p=1;p<=k;++p){
				for(int q=1;q<=p;++q){
					if(!flag[p][q]) continue;
					ff=0;
					for(int a=0;a<s[p].size();++a){
					    x=s[p][a];
						y=r[x][q-1];
						cu[x]++;
						ru[y]++;
						if(cu[x]>1) ff=1;
						if(ru[y]>1) ff=1;
					}
					for(int a=0;a<s[p].size();++a){
					    x=s[p][a];
						y=r[x][q-1];
						cu[x]--;
						ru[y]--;
					}
					if(!ff) dp[i][j][p][q]=1;
				}
			}
			for(int a=0;a<s[i].size();++a){
				x=s[i][a];
				y=r[x][j-1];
				cu[x]--;
				ru[y]--;
			}
		}
	}
	find(1);
	cout<<ans<<endl;
	return 0;
}