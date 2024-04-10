#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define M 998244353

#define b(x) (1<<((x)-1))

int i,j,k,n,m,t,b[500500][21],id[500500][21],cur,d[21],res[500500];
vector<pair<int,int> >v[500500];

#define getchar()(p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++)
char buf[1<<21],*p1=buf,*p2=buf;
inline ll read()
{
    char c=getchar();ll x=0;bool f=0;
    for(;!isdigit(c);c=getchar())f^=!(c^45);
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
    if(f)x=-x;return x;
}

int main() {
	n=read();
	for(i=1;i<=n;i++){
		k=read();
		cur=i;
		memcpy(b[i],b[i-1],sizeof(b[i]));
		memcpy(id[i],id[i-1],sizeof(id[i]));
		for(j=20;j>=1;j--){
			if(k&b(j)){
				if(!b[i][j]){
					b[i][j]=k;id[i][j]=cur;break;
				}
				else{
					if(id[i][j]<=cur){
						swap(cur,id[i][j]);
						swap(b[i][j],k);
					}
					k^=b[i][j];cur=min(cur,id[i][j]);
				}
			}
		}
	}

	t=read();
	for(i=1;i<=t;i++){
		j=read();k=read();v[k].push_back({j,i});
	}
	
	for(i=1;i<=500000;i++){
		for(auto [x,y]:v[i]){
			for(j=1;j<=20;j++){
				if(id[i][j]>=x){
					d[j]=b[i][j];
				}
				else{d[j]=0;}
			}
			for(j=20;j>=1;j--){
				if((res[y]^d[j])>res[y])res[y]^=d[j];
			}
		}
	}
	for(i=1;i<=t;i++){
		printf("%d\n",res[i]);
	}
}