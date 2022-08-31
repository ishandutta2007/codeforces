#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<cstdlib>
#include<cmath>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<bitset>
using namespace std;
typedef long long ll;
typedef double db;
const db pi=acos(-1);
void gn(int &x){
    int sg=1;char c;while(((c=getchar())<'0'||c>'9')&&c!='-');
    if(c=='-')sg=-1,x=0;else x=c-'0';
    while((c=getchar())>='0'&&c<='9')x=x*10+c-'0';
    x*=sg;
}
void gn(ll &x){
    int sg=1;char c;while(((c=getchar())<'0'||c>'9')&&c!='-');
    if(c=='-')sg=-1,x=0;else x=c-'0';
    while((c=getchar())>='0'&&c<='9')x=x*10+c-'0';
    x*=sg;
}
const int mo=1000000007;
int qp(int a,ll b){int ans=1;do{if(b&1)ans=1ll*ans*a%mo;a=1ll*a*a%mo;}while(b>>=1);return ans;}
int gcd(int a,int b){return b?gcd(b,a%b):a;}

char s[111111];
int n;
set<int>ls,rs;
vector<int>an[111111];int tot=0;
int sx[111111],ex[111111];
void work(int st){
	++tot;
	int cur=s[st]=='L'?0:1;
	while(1){
		an[tot].push_back(st);
		if(cur==0){
			ls.erase(st);
			set<int>::iterator it=rs.lower_bound(st);
			if(it!=rs.end()){
				st=*it;
				cur=1;
			}else{
				break;
			}
		}else{
			rs.erase(st);
			set<int>::iterator it=ls.lower_bound(st);
			if(it!=ls.end()){
				st=*it;
				cur=0;
			}else{
				break;
			}
		}
	}
	sx[tot]=s[an[tot].front()]=='R';
	ex[tot]=s[an[tot].back()]=='R';
}
int lll[111111],rrr[1111111];

void out(int i){
	for (int j=0;j<an[i].size();j++)printf("%d ",an[i][j]);
}
int main()
{
	scanf("%s",s+1);
	n=strlen(s+1);
	for (int i=1;i<=n;i++)if(s[i]=='L')ls.insert(i);else rs.insert(i);

	while(!ls.empty() || !rs.empty()){
		int st=n+1;
		if(!ls.empty())st=min(st,*ls.begin());
		if(!rs.empty())st=min(st,*rs.begin());
		work(st);
	}
	printf("%d\n",tot-1);
	int nl=0,nr=0;
	for (int i=1;i<=tot;i++)if(sx[i]==0 && ex[i]==0)lll[++nl]=i;else if(sx[i]==1 && ex[i]==1)rrr[++nr]=i;
	if(nl>nr){
		for (int i=1;i<=tot;i++)if(sx[i]==0 && ex[i]==1)out(i);
		for (int i=1;i<=nr;i++){
			out(lll[i]);
			out(rrr[i]);
		}
		out(lll[nl]);
		for (int i=1;i<=tot;i++)if(sx[i]==1 && ex[i]==0)out(i);
	}else if(nl<nr){
		for (int i=1;i<=tot;i++)if(sx[i]==1 && ex[i]==0)out(i);
		for (int i=1;i<=nl;i++){
			out(rrr[i]);
			out(lll[i]);
		}
		out(rrr[nr]);
		for (int i=1;i<=tot;i++)if(sx[i]==0 && ex[i]==1)out(i);
	}else if(nl==nr){
		out(lll[1]);
		for (int i=1;i<=tot;i++)if(sx[i]==1 && ex[i]==0)out(i);
		out(rrr[1]);
		for (int i=1;i<=tot;i++)if(sx[i]==0 && ex[i]==1)out(i);
		for (int i=2;i<=nl;i++){
			out(lll[i]);
			out(rrr[i]);
		}
	}
	printf("\n");
	return 0;
}