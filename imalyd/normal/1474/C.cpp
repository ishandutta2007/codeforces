#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(i=(a);i<=(b);++i)
#define per(i,a,b) for(i=(a);i>=(b);--i)
#define REP(i,a,b) for(i=(a);i< (b);++i)
#define PER(i,a,b) for(i=(a);i> (b);--i)
typedef long long ll;
#define ERR(...) fprintf(stderr,__VA_ARGS__);

inline void ac();
int main(){
	int t;scanf("%d",&t);while(t--)ac();
	return 0;
}
const int MAXN=2005;
multiset<int>S,T;
int A[MAXN];
inline void dbg(const multiset<int> &S){
	multiset<int>::iterator m;
	for(m=S.begin();m!=S.end();++m)ERR("%d ",*m);
	ERR("\n");
}
inline void ac(){
	ERR("\n\n\n\n");
	int n,i,mx,sx,a,b,c,t;
	scanf("%d",&n);n<<=1;
	S.clear();
	rep(i,1,n){scanf("%d",&a);S.insert(a);}
	multiset<int>::iterator m=--S.end(),mm;
	mx=*m;S.erase(m);
	for(m=S.begin();m!=S.end();++m){
		T=S;
		T.erase(T.find(sx=*m));
		//ERR("a=%d\n",mx);
		//dbg(T);
		A[1]=a=mx;A[t=2]=sx;
		while(!T.empty()){
			mm=--T.end();
			b=*mm;c=a-b;
			A[++t]=b;A[++t]=c;
			T.erase(mm);
			if(T.find(c)==T.end())break;
			T.erase(T.find(c));
			a=max(b,c);
			//ERR("a=%d\n",a);
			//dbg(T);
		}
		if(T.empty()){
			printf("YES\n%d\n",mx+sx);
			for(i=1;i<t;i+=2)printf("%d %d\n",A[i],A[i+1]);
			return;
		}
	}
	puts("NO");
}