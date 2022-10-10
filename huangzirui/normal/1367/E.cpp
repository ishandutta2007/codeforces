#include<bits/stdc++.h>
#define ll long long
using namespace std;
inline int read(){
	char c=getchar();int x=0,f=1;
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
    return x*f;
}
const int maxn=20010;
int i,j,k,n,m;
string str;
int gcd(int x,int y){
	return y==0?x:gcd(y,x%y);
}
int s[300];
int main(){
	int T;
	cin>>T;
	while(T--){
		memset(s,0,sizeof(s));
		cin>>n>>m;
		cin>>str;
		for(i=0;i<n;i++)s[str[i]-'a'+1]++;
		for(i=n;i>=1;i--){
			int X=gcd(i,m),sum=0,S=i/X;
			for(j=1;j<=26;j++)
				sum+=s[j]/S;
			if(sum>=X)break;
		}printf("%d\n",i);
	}
	return 0;
}