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
const int N=3e5+50;
int n;
LL K;
struct date{
	int l,r,c;
	date(int _l=0,int _r=0,int _c=0){l=_l;r=_r;c=_c;}
};
bool operator < (date A,date B){
	return A.l<B.l||(A.l==B.l&&A.r<B.r);
}
int a[N],b[N],len[N];
set<date> S;
set<date>::iterator it;
vector<date> ve[N];
vector<date>::iterator ti;
date zz;
void init(){
	S.insert(date(0,inf,0));
	for(int i=1;i<=n;++i){
		it=S.lower_bound(date(a[i],inf,0));--it;
		zz=(*it);
		if(zz.r>=b[i]){
			ve[i].push_back(date(a[i],b[i],zz.c));
			if(zz.l<a[i]) S.insert(date(zz.l,a[i]-1,zz.c));
			if(zz.r>b[i]) S.insert(date(b[i]+1,zz.r,zz.c));
			S.erase(it);S.insert(date(a[i],b[i],i));
			continue;
		}
		ve[i].push_back(date(a[i],zz.r,zz.c));
		if(zz.l<a[i]) S.insert(date(zz.l,a[i]-1,zz.c));
		S.erase(it++);zz=(*it);
		if(zz.r<a[i]){++it;zz=(*it);}
		while(zz.r<b[i]){
			ve[i].push_back(zz);
			S.erase(it++);
			zz=(*it);
		}
		ve[i].push_back(date(zz.l,b[i],zz.c));
		if(zz.r>b[i]) S.insert(date(b[i]+1,zz.r,zz.c));
		S.erase(it);S.insert(date(a[i],b[i],i));
	}
}
LL cnt,ans;
bool check(int x){
	cnt=0;ans=0;int sum=0;LL now=0;
	for(int i=1,l=1;i<=n;++i){
		sum+=(len[i]=b[i]-a[i]+1);
		for(ti=ve[i].begin();ti!=ve[i].end();++ti){
			zz=(*ti);
			len[zz.c]-=zz.r-zz.l+1;
			if(zz.c>=l) sum-=zz.r-zz.l+1;
			if(zz.c&&zz.c<l) now-=(LL)zz.c*(zz.r-zz.l+1);
		}
		while(sum>=x){
			sum-=len[l];
			now+=(LL)l*len[l];
			++l;
		}
		ans+=now+(LL)sum*(l-1);cnt+=l-1;
	}
	return cnt>=K;
}
int main(){
    scanf("%d%I64d",&n,&K);
    for(int i=1;i<=n;++i){
    	a[i]=read();b[i]=read()-1;
	}
	init();
	int l=1,r=inf,mid;
	while(l!=r){
		mid=l+r+1>>1;
		if(check(mid)) l=mid;
		else r=mid-1;
	}
	//cout<<l<<endl;
	check(l);
	ans=ans-(LL)l*(cnt-K);
	printf("%I64d\n",ans);
	return 0;
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