#include<bits/stdc++.h>
#define ll long long
using namespace std;
inline int read(){
	char c=getchar();int x=0,f=1;
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
    return x*f;
}
ll i,j,k,n,m,T;
int main(){
	cin>>T;
	while(T--){
		cin>>n;
		if(n&1)puts("NO");
		else{
			ll w=n/2,p1=sqrt(n),p2=sqrt(w);
			if(n%4==0 && p1*p1==n)puts("YES");
			else if(n%2==0 && p2*p2==w)puts("YES");
			else puts("NO");
		}
	}
	return 0;
}