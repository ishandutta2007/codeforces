#include <bits/stdc++.h>
#define LL long long
#define LD long double
using namespace std;
const LL P=998244353;
const int N=3e5+10;
const int INF=1e9;
int read(){
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
void print(LL x){
    if(x>9) print(x/10);
    putchar(x%10+'0');
}
void pls(LL &x,LL y){
    x+=y;if(x>=P)x-=P;
}
int n,cnt;
int a[N];
int len[N];
bool vis[N];
vector<int> p[N];
int t;
int l[N],r[N];
void MAIN(){
	n=read();cnt=0;
    for(int i=1;i<=n;++i) {
    	a[i]=read();
    	vis[i]=0;
	}
	//for(int i=1;i<=n;++i) cout<<a[i]<<" ";puts("");
    for(int i=1;i<=n;++i){
    	if(!vis[i]){
    		++cnt;
    		p[cnt].clear();
    		len[cnt]=0;
    		for(int j=i;;j=a[j]){
    			if(!vis[j]){
    				vis[j]=1;
    				++len[cnt];
    				p[cnt].push_back(j);
				}
				else break;
			}
		}
	}
	t=0;
	if(cnt==1){
		for(int i=1;i<len[cnt]-1;++i){
			++t;
			l[t]=p[cnt][i];r[t]=p[cnt][len[cnt]-1];
		}
		++t;
		l[t]=p[cnt][0];r[t]=p[cnt][len[cnt]-1];
		++t;
		l[t]=p[cnt][0];r[t]=p[cnt][1];
		++t;
		l[t]=p[cnt][1];r[t]=p[cnt][len[cnt]-1];
	}
	else{
		while(cnt>=2){
			++t;
			l[t]=p[cnt][0];r[t]=p[cnt-1][0];
			for(int i=1;i<len[cnt];++i){
				++t;
				l[t]=p[cnt][i];r[t]=p[cnt-1][0];
			}
			for(int i=1;i<len[cnt-1];++i){
				++t;
				l[t]=p[cnt-1][i];r[t]=p[cnt][0];
			}
			++t;
			l[t]=p[cnt][0];r[t]=p[cnt-1][0];
			cnt-=2;
		}
		if(cnt==1){
			++cnt;
			len[cnt]=1;
			++t;
			l[t]=p[cnt][0];r[t]=p[cnt-1][0];
			for(int i=1;i<len[cnt];++i){
				++t;
				l[t]=p[cnt][i];r[t]=p[cnt-1][0];
			}
			for(int i=1;i<len[cnt-1];++i){
				++t;
				l[t]=p[cnt-1][i];r[t]=p[cnt][0];
			}
			++t;
			l[t]=p[cnt][0];r[t]=p[cnt-1][0];
			cnt-=2;
		}
	}
	printf("%d\n",t);
	for(int i=1;i<=t;++i){
		printf("%d %d\n",l[i],r[i]);
	}
	return;
}

int main(){
    int ttt=1;
    while(ttt--) MAIN();
    return 0;
}