#include<bits/stdc++.h>
#define ll long long
using namespace std;
inline int read(){
	char c=getchar();int x=0,f=1;
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
    return x*f;
}
int i,j,k,n,m,T;
int main(){
	cin>>T;
	while(T--){
		cin>>n>>k;
		if(k>(n-1)/2)puts("-1");
		else{
			int l=1,r=n;
			for(i=1;i<=n;i++){
				if(i%2==0 && k)printf("%d ",r--),k--;
				else printf("%d ",l++);
			}puts("");
		}
	}
	return 0;
}