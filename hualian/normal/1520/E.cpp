#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1000010;
inline int read(){
	int f=0,x=0;
	char ch=getchar();
	while(!isdigit(ch)){f|=(ch=='-');ch=getchar();}
	while(isdigit(ch)){x=x*10+ch-'0';ch=getchar();}
	return f?-x:x;
}
char s[N];
int a[N];
signed main(){
	int t=read();
	while(t--){
		int n=read();
		scanf("%s",s+1);int cnt=0,res=0,ans=0;
		for(int i=1;i<=n;i++)
			if(s[i]=='*')cnt++,a[cnt]=i;
		for(int i=1;i<=n;i++){
			if(s[i]=='*')res++;
			if(res==cnt-cnt/2){
				int be=i-res;
				for(int i=1;i<=cnt;i++){
					ans+=abs(a[i]-(i+be));
				}
				cout<<ans<<endl;break;
			}
		}
	}
	return 0;
}