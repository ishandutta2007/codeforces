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
		int a,b,c,d;
		a=read();b=read();c=read();d=read();
		int Max=max(0,a-1)+max(0,b-1)+max(0,c-1);
		int Min;
		if(a<b)swap(a,b);
		if(a<c)swap(a,c);
		if(b<c)swap(b,c);
		if(a<=b+c)Min=0;
		else Min=max(0,a-1-b-c);
		if(Min<=d && d<=Max)puts("Yes");
		else puts("No");
	}
	return 0;
}