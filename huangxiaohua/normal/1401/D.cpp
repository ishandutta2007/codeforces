#define _CRT_SECURE_NO_WARNINGS
#define M 1000000007
#pragma GCC optimize(2)
#pragma GCC optimize(3)
 
#include<bits/stdc++.h>
using namespace std;
 
int i,t,n,m,k,son[100500],link[100500],x,y;
long long res=0,p[100500],cishu[100500],a[100500];
vector<int> v[100500];
queue<int> q;
 
bool cmp(long long a,long long b){
	return a>b;
}
 
namespace IO {
const int MAXSIZE = 1 << 20;
char buf[MAXSIZE], *p1, *p2;
#define gc()                                                               \
  (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, MAXSIZE, stdin), p1 == p2) \
       ? EOF                                                               \
       : *p1++)
inline int rd() {
  int x = 0, f = 1;
  char c = gc();
  while (!isdigit(c)) {
    if (c == '-') f = -1;
    c = gc();
  }
  while (isdigit(c)) x = x * 10 + (c ^ 48), c = gc();
  return x * f;
}
}
 
void chk(int n){
	int i,tmp;
	for(i=0;i<v[n].size();i++){
		tmp=v[n][i];
		if(!link[tmp]){
			a[tmp]+=a[n];link[n]=tmp;break;
		}
		
	}
}
 
int main(){
	t=IO::rd();while(t--){
		
	n=IO::rd();res=0;
	memset(link,0,n*4+50);
	memset(son,0,n*4+50);
	memset(cishu,0,n*8+50);memset(p,0,n*8+50);
	memset(a,0,n*8+50);
	while(!q.empty()){q.pop();}
	
	for(i=1;i<=n;i++){a[i]=1;v[i].clear();}
	
	for(i=1;i<=n-1;i++){
		x=IO::rd();y=IO::rd();
		v[x].push_back(y);son[x]++;
		v[y].push_back(x);son[y]++;
	}
	
	m=IO::rd();
	for(i=1;i<=m;i++){
		p[i]=IO::rd();
	}
	
	sort(p+1,p+m+1);
	
	for(i=m-1;i>=n-1;i--){
		p[i]=p[i]*p[i+1]%M;
	}
	
	reverse(p+1,p+1+min(n-1,m));
	
	for(i=1;i<=n;i++){
		if(son[i]==1){q.push(i);chk(i);}
	}
	
	for(i=1;i<=n-1;i++){
		k=q.front();q.pop();
		cishu[i]=a[k]*(n-a[k]);
		son[link[k]]--;
		if(son[link[k]]==1){chk(link[k]);q.push(link[k]);}
	}
	
	sort(cishu+1,cishu+n,cmp);
	
	for(i=1;i<=n-1;i++){
		if(p[i]==0){res+=cishu[i];}
		else{res+=p[i]*cishu[i];}
		res%=M;
	}
	printf("%lld\n",res%M);
}}