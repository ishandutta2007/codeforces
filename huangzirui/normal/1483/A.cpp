#include<bits/stdc++.h>
#define ll long long
using namespace std;
inline int read(){
	char c=getchar();int x=0,f=1;
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
    return x*f;
}
const int maxn=200010;
int i,j,k,n,m,T,s[maxn],ans[maxn];
vector<int>a[maxn];
int main(){
	cin>>T;
	while(T--){
		cin>>n>>m;
		for(i=1;i<=m;i++){
			int w=read(),o;
			for(j=0;j<w;j++)a[i].push_back(read());
			if(w==1)s[a[i][0]]++;
		}
		bool b=true;
		for(i=1;i<=m;i++){
			if(a[i].size()==1)ans[i]=a[i][0];
			else{
				int u=0;
				for(j=0;j<a[i].size();j++)
					if(!u || s[u]>s[a[i][j]])u=a[i][j];
				s[u]++;ans[i]=u;
			}
		}
		for(i=1;i<=n;i++)if(s[i]>(m+1)/2)b=false;
		if(b){
			puts("YES");
			for(i=1;i<=m;i++)printf("%d ",ans[i]);
			puts("");
		}else puts("NO");
		for(i=1;i<=n;i++)s[i]=0;
		for(i=1;i<=m;i++)vector<int>().swap(a[i]);
	}
	return 0;
}