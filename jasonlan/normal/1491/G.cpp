#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
const int maxn=201010;
int n,m;
int c[maxn],vcnt;
bool in[maxn];
vector <int> v[maxn];
int ans[maxn][2],tnt;
inline int read(){
	int res=0;
	char ch=getchar(),ch1=ch;
	while(!isdigit(ch))ch1=ch,ch=getchar();
	while(isdigit(ch))res=(res<<3)+(res<<1)+ch-'0',ch=getchar();
	return ch1=='-'?-res:res;
}
void op(int x,int y){
	ans[++tnt][0]=x;ans[tnt][1]=y;
}
void circle_np1(int p){
	if(v[p].size()==2){
		for(int i=1;i<=n;++i){
			if(v[p][0]!=i&&v[p][1]!=i){
				op(i,v[p][0]);
				op(i,v[p][1]);
				op(i,v[p][0]);
				return;
			}
		}
	}
	else if(v[p].size()==3){
		op(v[p][0],v[p][1]);
		op(v[p][1],v[p][2]);
		op(v[p][0],v[p][2]);
		op(v[p][0],v[p][1]);
	}
	else{
		int s=v[p].size();
		op(v[p][0],v[p][s-1]);
		for(int i=1;i<s-2;++i)
			op(v[p][s-1],v[p][i]);
		op(v[p][0],v[p][s-2]);
		op(v[p][s-2],v[p][s-1]);
		op(v[p][0],v[p][s-1]);
	}
}
void circle_n(int p,int q){
	op(v[p][0],v[q][0]);
	for(int i=1;i<v[p].size();++i)
		op(v[q][0],v[p][i]);
	for(int i=1;i<v[q].size();++i)
		op(v[p][0],v[q][i]);
	op(v[p][0],v[q][0]);
}
int main(){
	n=read();
	for(int i=1;i<=n;++i)
		c[i]=read();
	for(int i=1,p;i<=n;++i){
		if(in[i])continue;
		else if(i!=c[i]){
			p=i;
			in[p]=true;
			v[++vcnt].push_back(p);
			while(c[p]!=i){
				v[vcnt].push_back(c[p]);
				in[c[p]]=true;
				p=c[p];
			}
		}
	}
	for(int i=1;i<=vcnt;i+=2){
		if(i==vcnt)circle_np1(i);
		else circle_n(i,i+1);
	}
	printf("%d\n",tnt);
	for(int i=1;i<=tnt;++i)
		printf("%d %d\n",ans[i][0],ans[i][1]);
	return 0;
}