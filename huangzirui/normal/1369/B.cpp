#include<bits/stdc++.h>
#define ll long long
using namespace std;
inline int read(){
	char c=getchar();int x=0,f=1;
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
    return x*f;
}
int i,j,k,n,m;
string s;
int main(){
	int T;
	cin>>T;
	while(T--){
		n=read();
		getline(cin,s);
		int L=0,R=n-1;
		while(L!=n && s[L]=='0')L++;
		while(R!=-1 && s[R]=='1')R--;
		for(i=0;i<L;i++)putchar('0');
		if(L<=R)putchar('0');
		for(i=R+1;i<n;i++)putchar('1');
		puts("");
	}
	return 0;
}