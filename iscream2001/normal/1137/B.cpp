#pragma GCC optimize("-O3")
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<algorithm>
#include<cstring>
#include<map>
#include<queue>
#include<set>
#include<cmath>
#include<vector>
#define LL long long
#define ui unsigned int
#define ull unsigned long long
using namespace std;
  
inline int read(){
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
void Out(int x){
    if(x>9) Out(x/10);
    putchar('0'+x%10);
}
LL gcd(LL x,LL y){
    if(!y) return x;
    return gcd(y,x%y);
}
LL qpow(LL x,LL y,LL P){
    LL re=1;
    while(y){
        if(y&1) re=re*x%P;
        x=x*x%P;y>>=1;
    }
    return re;
}
const double eps=1e-6;
const int inf=1e9;
const int P=998244353;
const int N=5e5+50;

int ls,lt;
char s[N],t[N];
int nxt[N];
int main(){
	scanf("%s",t+1);lt=strlen(t+1);
    scanf("%s",s+1);ls=strlen(s+1);
    int j=0;
    for(int i=2;i<=ls;++i){
    	while(j&&s[j+1]!=s[i]) j=nxt[j];
    	if(s[j+1]==s[i]) ++j;
    	nxt[i]=j;
	}
	//cout<<nxt[ls]<<endl;
	int u=0,v=0;
	for(int i=1;i<=lt;++i)
		if(t[i]=='1') ++v;
		else ++u;
	int l=nxt[ls];
	int U=0,V=0;
	for(int i=1;i<=ls;++i)
		if(s[i]=='1') ++V;
		else ++U;
	int y=0,z=0;
	for(int i=l+1;i<=ls;++i){
		if(s[i]=='1')++z;
		else ++y;
	}
	j=0;
	//cout<<u<<" "<<v<<endl;
	if(u>=U&&v>=V){
		for(int i=1;i<=ls;++i){
			t[++j]=s[i];
			if(s[i]=='1') --v;
			else --u;
		}
		//cout<<"y"<<endl;
		while(u>=y&&v>=z){
			for(int i=1+l;i<=ls;++i){
				t[++j]=s[i];
				if(s[i]=='1') --v;
				else --u;
			}
		}
	}
	//cout<<"y"<<endl;
	while(u--) t[++j]='0';
	while(v--) t[++j]='1';
	for(int i=1;i<=lt;++i) printf("%c",t[i]);puts("");
}
/*
3 2
554 727
467 591
603 609

5 8
2 588
749 791
502 819
148 456
79 571
*/