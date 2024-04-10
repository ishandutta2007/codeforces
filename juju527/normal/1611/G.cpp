#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=1e6+5;
char s[maxn];
set<int> a[2*maxn];
int read(){
    int x=0,y=1;
    char ch=getchar();
    while(ch<48||ch>57){if(ch==45)y=-1;ch=getchar();}
    while(ch>=48&&ch<=57)x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
    return x*y;
}
int main(){
//    freopen("CF1611G.in","r",stdin);
//    freopen("CF1611G.out","w",stdout);
    int T;
	T=read();
	while(T--){
		int n,m;
		n=read();m=read();
		for(int i=2;i<=n+m;i++)a[i].clear();
		for(int i=1;i<=n;i++){
			scanf("%s",s+1);
			for(int j=1;j<=m;j++)if(s[j]=='1')a[i+j].insert(i);
		}
		int res=0;
		for(int i=2;i<=n+m;i++){
//			cout<<"@"<<i<<" "<<a[i].size()<<endl;
			if(!a[i].size())continue;
			res++;
			int x=1,y=i;
			if(y-1>m)x=i-m,y=i;
//			cout<<i<<" "<<x<<" "<<y-x<<endl;
			while(x<=n){
//				cout<<"#"<<x<<" "<<y-x<<endl;
				if(a[y].find(x)!=a[y].end())a[y].erase(x);
				if(a[y].upper_bound(x)!=a[y].end())x++;
				else if(y+2<=n+m)x++,y+=2;
				else x++;
			}
		}
		printf("%d\n",res);
	}
    return 0;
}