#include<bits/stdc++.h>
using namespace std;
int st[50],p[2005];
int read(){
	int x=0,y=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')y=-1;ch=getchar();}
	while(ch>='0'&&ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	return x*y;
}
int gcd(int x,int y){
	return y?gcd(y,x%y):x;
}
int main(){
	int t;
	t=read();
	while(t--){
		int n,k;
		string s;
		n=read();k=read();
		cin>>s;
		memset(st,0,sizeof(st));
		memset(p,0,sizeof(p));
		for(int i=0;i<n;i++)st[s[i]-'a']++;
		for(int i=0;i<26;i++)p[st[i]]++;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				p[i]+=j/i*p[j];
			}
		}
		for(int i=n;i>=1;i--){
			int c=k%i,g,lcm;
			g=gcd(i,c);
			if(p[i]||c==0){printf("%d\n",i);break;}
			if(g==1)continue;
			if(p[i/g]>=g){printf("%d\n",i);break;}
		}
	}
	return 0;
}