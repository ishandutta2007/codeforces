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
		string s;
		cin>>s;
		putchar(s[0]);
		n=s.size();
		for(i=1;i<n;i+=2)putchar(s[i]);
		puts("");
	}
	return 0;
}