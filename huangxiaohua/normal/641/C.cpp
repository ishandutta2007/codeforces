#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t;
ll sb1,sb2,res[2005000],tmp;
#define getchar()(p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++)
char buf[1<<21],*p1=buf,*p2=buf;
template <typename T>
inline void read(T& r) {
	r=0;bool w=0; char ch=getchar();
	while(ch<'0'||ch>'9') w=ch=='-'?1:0,ch=getchar();
	while(ch>='0'&&ch<='9') r=r*10+(ch^48), ch=getchar();
	r=w?-r:r;
}

int main(){
	read(n);read(t);
	sb1=1;sb2=2;
	while(t--){
		read(k);
		if(k==2){
			swap(sb1,sb2);
		}
		else{
			read(k);
			k=(n-k)%n;
			if(k&1){
				tmp=sb1+2;
				if(tmp>n){tmp-=n;}
				sb1=sb2;
				sb2=tmp;
				k--;
			}
			sb2+=k;
			sb1+=k;
			if(sb2>n){sb2-=n;}
			if(sb1>n){sb1-=n;}
		}
		//printf("r:%d %d\n",sb1,sb2);
	}
	res[1]=sb1;res[2]=sb2;
	for(i=1;i<=n;i++){
		if(i>=3){
			res[i]=res[i-2]+2;
			if(res[i]>n){res[i]-=n;}
		}
		printf("%lld ",res[i]);
	}
}