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
inline bool np(const int &x){
	int i,s=sqrt(x);
	//rep(i,2,s)if(!(x%i)){ERR("np %d\n",x);break;}
	rep(i,2,s)if(!(x%i))return true;
	return false;
}
inline int get(int x){
	while(np(x))++x;
	return x;
}
inline void ac(){
	int d,p,q;
	scanf("%d",&d);
	p=get(d+1);
	q=get(d+p);
	printf("%d\n",p*q);
}