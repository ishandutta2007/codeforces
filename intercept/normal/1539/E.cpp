#include<bits/stdc++.h>
using namespace std;
const int M=1e5+9;
int n,m;
int a[M],c[M][2];
vector<int>v[M][2],u[2];
void change(vector<int>&p,vector<int>x){
	p[0]=max(p[0],x[0]);
	p[1]=min(p[1],x[1]);
}
bool check(vector<int>p,int x){return p[0]<=x&&x<=p[1];}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i){
		scanf("%d",&a[i]);
		for(int o=0;o<2;++o){
			v[i][o].resize(2);
			scanf("%d%d",&v[i][o][0],&v[i][o][1]);
		}
	}
	v[n+1][0]=v[n+1][1]={0,m};
	for(int i=n;i>=1;--i){
		u[0]=v[i][0],u[1]=v[i][1];
		for(int o=0;o<2;++o){
			if(check(u[o^1],a[i])){
				if(check(v[i+1][o^1],a[i]))c[i][o^1]=o;
				else change(v[i][o],v[i+1][o]),c[i][o^1]=o^1;
			}
			else v[i][o]={m,0};
		}
	}
	if(!check(v[1][0],0)&&!check(v[1][1],0))return puts("No"),0;
	puts("Yes");
	for(int i=1,o=check(v[1][0],0);i<=n;o=c[i][o],++i)printf("%d ",o);
	return 0;
}