#include<iostream>
#include<cstdio>
#include<vector>
#define pii pair<int,int>
using namespace std;
const int maxn=201000;
int n,m;
int ans[maxn],ap[4];
vector <int> v[maxn];
bool ok;
inline int read(){
	int res=0;
	char ch=getchar(),ch1=ch;
	while(!isdigit(ch))ch1=ch,ch=getchar();
	while(isdigit(ch))res=(res<<3)+(res<<1)+ch-'0',ch=getchar();
	return ch1==-'-'?-res:res;
}
void output(){
	if(!ok){puts("No");return;}
	puts("Yes");
	for(int i=0;i<m;++i)
		printf("%d ",ans[i]);
	cout<<endl;
}
pii check(){
	int res=0,pos=0;
	for(int i=0,cnt;i<n;++i){
		cnt=0;
		for(int j=0;j<m;++j)
			if(ans[j]!=v[i][j])++cnt;
		if(cnt>res)res=cnt,pos=i;
	}
	return make_pair(pos,res);
}
int main(){
	n=read();m=read();
	for(int i=0;i<n;++i)
		for(int j=0;j<m;++j)
			v[i].push_back(read());
	for(int j=0;j<m;++j)
		ans[j]=v[0][j];
	pii gloc=check();
	if(gloc.second<=2)ok=true;
	else if(gloc.second>4);
	else{
		int p=gloc.first;
		for(int i=0,j=0;i<m;++i)
			if(ans[i]!=v[p][i])
				ap[j]=i,++j;
		if(gloc.second==4){
			for(int i=0;i<4;++i){
				ans[ap[i]]=v[p][ap[i]];
				for(int j=i+1;j<4;++j){
					ans[ap[j]]=v[p][ap[j]];
					gloc=check();
					if(gloc.second<=2){
						ok=true;break;
					}
					ans[ap[j]]=v[0][ap[j]];
				}
				if(ok)break;
				ans[ap[i]]=v[0][ap[i]];
			}
		}
		else{
			for(int i=0;i<3;++i){
				ans[ap[i]]=v[p][ap[i]];
				gloc=check();
				if(gloc.second<=2)ok=true;
				else if(gloc.second==3){
					for(int j=0;j<3;++j)
						if(ans[ap[j]]!=v[gloc.first][ap[j]]&&i!=j){
							ans[ap[j]]=v[gloc.first][ap[j]];
							gloc=check();
							if(gloc.second<=2)ok=true;
							else
								ans[ap[j]]=v[0][ap[j]];
						}
				}
				if(ok)break;
				ans[ap[i]]=v[0][ap[i]];
			}
		}
	}
	output();
	return 0;
}