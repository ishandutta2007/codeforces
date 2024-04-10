#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
#include<set>
#define LL long long
using namespace std;
const int N=2e5+10;
const int inf=1e9+10;
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
int n,d,mx;
LL a[30][30],B,C;
int tp;
int l[100],r[100];
int main(){
	cin>>n;
	B=1;
	for(int s=3;s<n+n;++s){
		C=0;
		for(int i=1;i<=n;++i){
			C=B-C;
			int j=s-i;
			if(j>=1&&j<=n){
				a[i][j]=C;
			}
		}
		B<<=1;
	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j) cout<<a[i][j]<<" ";
		puts("");
		cout.flush();
	}
	int Q;
	LL K,v,w;
	cin>>Q;
	while(Q--){
		cin>>K;v=1;
		tp=1;l[1]=1;r[1]=1;
		while(l[tp]!=n||r[tp]!=n){
			w=(K&v);
			if(l[tp]<n&&a[l[tp]+1][r[tp]]==w){
				l[tp+1]=l[tp]+1;
				r[tp+1]=r[tp];
			}
			else {
				l[tp+1]=l[tp];
				r[tp+1]=r[tp]+1;
			}
			++tp;v<<=1;
		}
		for(int i=1;i<=tp;++i){
			printf("%d %d\n",l[i],r[i]);
			fflush(stdout);
		}
	}
	return 0;
}