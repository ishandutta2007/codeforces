#pragma GCC optimize("-O2")
#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#include<cmath>
#include<algorithm>
#include<map>
#include<bitset>
#include<ctime>
#include<cstdlib> 
#define LL long long
#define DB long double
#define pa pair<LL,int>
using namespace std;

inline int read(){
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
inline void Out(LL x){
    if(x>9) Out(x/10);
    putchar(x%10+'0'); 
}
LL qpow(LL x,LL y,LL P){
    LL re=1;
    while(y){
        if(y&1) re=re*x%P;
        x=x*x%P;y>>=1;	
    } 
    return re;
}

const LL P=998244353;
const int N=350;
int n,t,x,y;
int cnt=0,js=0;
int ans[N];
int s[N],f[N];
int main(){
    //freopen("1.in","r",stdin);
    //freopen("1.out","w",stdout);
    scanf("%d%d",&n,&t);
    for(int i=n;i>1;--i){
    	memcpy(f,s,sizeof(f));
    	printf("? %d %d\n",1,i-1);
    	fflush(stdout);
    	y=n-t;
    	scanf("%d",&t);
    	js=0;
    	while(y==t){
    		++js;
    		for(int j=1;j<=n;++j) s[j]=s[j]^1;
    		printf("? %d %d\n",1,i-1);
    		fflush(stdout);
    		y=n-t;
    		scanf("%d",&t);
    		if(js==30) break;
		}
		if(js==30){
			//cout<<"x"<<" ";for(int j=1;j<=n;++j) cout<<s[j];cout<<endl;
			for(int j=1;j<=n;++j) s[j]=s[j]^1;
			for(int j=i;j<=n;++j) s[j]=f[j];
			int sum=0;
			for(int j=i+1;j<=n;++j){
				if(s[j]==0) --sum;
				else ++sum;
			}
			if(sum<0) x=1;
			else x=0;
			if(s[i]!=x) ans[i]=1;
			else ans[i]=0;
			s[i]=x;
		}
		else{
			for(int j=i+1;j<=n;++j){
				if(s[j]==0) --y;
				else ++y;
			}
			if(y>t) x=0;
			else x=1;
			if(s[i]!=x) ans[i]=1;
			else ans[i]=0;
			s[i]=x;
			for(int j=1;j<i;++j) s[j]=s[j]^1;
		}
		//for(int j=1;j<=n;++j) cout<<s[j];cout<<endl;
	}
	for(int i=2;i<=n;++i) if(s[i]==1) --t;
	if(!t) x=0;
	else x=1;
	if(s[1]!=x) ans[1]=1;
	else ans[1]=0;
	printf("! ");
	for(int i=1;i<=n;++i) printf("%d",ans[i]);
	fflush(stdout);
	return 0;
} 
/*
3
1
3
1
3
1
3
1
3
1
3
1
3
1
3
1
3
1
3
1
3
1
3
1
3
1
3
*/