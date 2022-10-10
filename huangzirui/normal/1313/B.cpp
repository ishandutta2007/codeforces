#include<bits/stdc++.h>
#define ll long long
using namespace std;
inline int read(){
	char c=getchar();int x=0,f=1;
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
    return x*f;
}
int i,j,k,n,m,x,y;
int main(){
	int t;
	cin>>t;
	while(t--){
		cin>>n>>x>>y;
		cout<<n-(min(x-1,max(0,n-y-1))+max(0,min(n-min(x-1,max(0,n-y-1))-1-1,n-x-1))+((x!=n) && (y!=n)))<<' '<<min(n+x,y-1)+min(x-1,n-min(n+x,y-1)-1)+1<<endl;
	}return 0;
}