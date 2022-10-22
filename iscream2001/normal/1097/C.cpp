#pragma GCC optimize("-O2")
#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#include<cmath>
#include<algorithm>
#include<map>
#include<set>
#include<bitset>
#include<ctime>
#include<cstdlib> 
#define LL long long
#define DB double
#define pa pair<LL,int>
#define ctz __builtin_ctz
using namespace std;

inline int read(){
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}

inline void Out(int x){
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

map<int,int> mp;
int n;
char s[500050];
int mx,mn;
int main(){
//    freopen("1.in","r",stdin);
//    freopen("1.out","w",stdout);
	cin>>n;
	int ans=0,len;
	while(n--){
		scanf("%s",s+1);
		len=strlen(s+1);
		mn=1000000000;
		mx=-1000000000;
		int x=0;
		for(int i=1;i<=len;++i){
			if(s[i]=='(') ++x;
			else --x;
			mn=min(mn,x);
		}
		x=0;
		for(int i=len;i>=1;--i){
			if(s[i]=='(') ++x;
			else --x;
			mx=max(mx,x);
		}
		if(x<0){
			if(mx<=0){
				if(mp[-x]){
					--mp[-x];
					++ans;
				}
				else ++mp[x];
			}
		}
		else if(x>0){
			if(mn>=0){
				if(mp[-x]){
					--mp[-x];
					++ans;
				}
				else ++mp[x];
			}
		}
		else{
			if(mn>=0&&mx<=0){
				if(mp[-x]){
					--mp[-x];
					++ans;
				}
				else ++mp[x];
			}
		}
	}
	cout<<ans<<endl; 
	return 0;
}
/*
1
0
*/