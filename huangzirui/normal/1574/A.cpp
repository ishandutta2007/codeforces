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
		cin>>n;
		for(i=1;i<=n;i++){
			for(j=1;j<=i;j++)printf("(");
			for(j=1;j<=i;j++)printf(")");
			for(j=i+1;j<=n;j++)printf("()");puts("") ;
		}
	}
	return 0;
}