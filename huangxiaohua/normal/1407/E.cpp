#pragma GCC optimize(2)
#pragma GCC optimize(3)

#include<bits/stdc++.h>
using namespace std;
 
namespace IO {
const int MAXSIZE = 1 << 20;
char buf[MAXSIZE], *p1, *p2;
#define gc()                                                               \
  (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, MAXSIZE, stdin), p1 == p2) \
       ? EOF                                                               \
       : *p1++)
inline int rd() {
  int x = 0;
  char c = gc();
  while (!isdigit(c)) {
    c = gc();
  }
  while (isdigit(c)) x = x * 10 + (c ^ 48), c = gc();
  return x;
}
}
 
int i,j,n,t,res[500500],color[500500],a,b,c;
vector<int> v0[500500],v1[500500];
queue<int> q;
bool used[500500];
int main(){
	n=IO::rd();t=IO::rd();
	if(n==1){puts("0\n1");return 0;}
	for(i=1;i<=n;i++){
		color[i]=-1;res[i]=1145141919;
	}
	while(t--){
		a=IO::rd();b=IO::rd();c=IO::rd();
		if(a==b){continue;}
		if(c==1){
			v1[b].push_back(a);
		}
		else{
			v0[b].push_back(a);
		}
	}
	q.push(n);res[n]=0;used[n]=1;
	while(!q.empty()){
		a=q.front();q.pop();
		for(i=0;i<v0[a].size();i++){
			if(used[v0[a][i]]){continue;}
			if(color[v0[a][i]]==0){q.push(v0[a][i]);used[v0[a][i]]=1;res[v0[a][i]]=min(res[v0[a][i]],res[a]+1);}
			if(color[v0[a][i]]==-1){color[v0[a][i]]=1;}
		}
		for(i=0;i<v1[a].size();i++){
			if(used[v1[a][i]]){continue;}
			if(color[v1[a][i]]==1){q.push(v1[a][i]);used[v1[a][i]]=1;res[v1[a][i]]=min(res[v1[a][i]],res[a]+1);}
			if(color[v1[a][i]]==-1){color[v1[a][i]]=0;}
		}
		if(a==1){break;}
	}
	printf("%d\n",(res[1]==1145141919)?-1:res[1]);
	for(i=1;i<=n;i++){
		if(color[i]==0){putchar('0');}
		else{putchar('1');}
	}
}