#include<bits/stdc++.h>
using namespace std;
#define l(x) (x&(-x))
#define N 1100005
#define getc() p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++;
char buf[1<<21],*p1,*p2,ch;
int ret,fl;
inline int re() {
	ret=fl=0;
	ch=getc();
	while(!isdigit(ch)){
		if(ch=='-')fl=1;
		ch=getc();
	}
	while(isdigit(ch)){
		ret=(ret<<1)+(ret<<3)+(ch^48);
		ch=getc();
	}
	return fl?-ret:ret;
}
int c[N],x,n,q,k,now,to,sum,i;
void add(int x,int v){while(x<N)c[x]+=v,x+=l(x);}
inline int S(int x){int ret=0;while(x)ret+=c[x],x-=l(x);return ret;}
int main(){
	n=re(),q=re();
	for(i=1;i<=n;++i)x=re(),add(x,1);
	while(q--){
		k=re();
		if(k>0)add(k,1);
		else{
			k=-k;now=0;sum=0;
			for(i=19;~i;--i){
				to=now+(1<<i);
				if(c[to]+sum<k)now=to,sum+=c[to];
			}
			++now;
			add(now,-1);
		}
	}
	if(S(N-1)==0)cout<<0;
	else{
		k=1;
		now=0;sum=0;
		for(i=20;~i;--i){
			to=now+(1<<i);
			if(c[to]+sum<k)now=to,sum+=c[to];
		}
		cout<<now+1<<"\n";
	}
	return 0;
}