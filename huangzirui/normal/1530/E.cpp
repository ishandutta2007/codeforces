#include<bits/stdc++.h>
#define ll long long
using namespace std;
typedef pair<int,int> pii;
int read(){
	int x=0,b=1;char c;do c=getchar();while((c>'9'||c<'0')&&c!='-');
	if(c=='-')b=0;do x=x*10+c-'0',c=getchar();while(c>='0'&&c<='9');return b?x:-x;
}
const int maxn=100010;
int i,j,k,n,m,T,num[27000],opopop;
int main(){
	int T=read();
	while(T--){
		string s;
		cin>>s;n=s.size();
		for(i=1;i<=26;i++)num[i]=0;
		for(i=0;i<s.size();i++)num[s[i]-'a'+1]++;
		opopop=0;
		for(i=1;i<=26;i++)if(num[i]==1 && !opopop)opopop=i;
		int c1=0,c2=0,c3=0;
		for(i=1;i<=26;i++){
			if(num[i] && (!c1))c1=i;
			else if(num[i] && (!c2))c2=i;
			else if(num[i] && (!c3))c3=i;
		}
		if(!c2)cout<<s<<endl;
		else{
			if(opopop){
				putchar(opopop+'a'-1);
				for(i=1;i<=26;i++)
					if(i!=opopop)
						while(num[i])putchar(i+'a'-1),--num[i];
				puts("");
				continue;
			}
			if(num[c1]>1){
				int S=num[c1]-2;
				if(S<=(n-2)/2){
					putchar(c1+'a'-1);
					putchar(c1+'a'-1);
					putchar(c2+'a'-1);
					num[c1]-=2;num[c2]--;
					int u=1;
					while(num[c1]){
						putchar(c1+'a'-1);num[c1]--;
						while(u<=26 &&(!num[u] || u==c1))++u;
						if(u<=26)putchar(u+'a'-1),num[u]--/*,cerr<<u<<' '<<num[u]<<endl*/;
					}
					for(i=1;i<=26;i++)while(num[i])putchar(i+'a'-1),--num[i];
					puts("");
					continue;
				}
			}
			putchar(c1+'a'-1);
			putchar(c2+'a'-1);
			num[c1]--;num[c2]--;
			if(c3 && num[c1]!=0){
				while(num[c1])putchar(c1+'a'-1),--num[c1];
				putchar(c3+'a'-1);--num[c3];
				for(i=1;i<=26;i++)
					if(i!=c1){
						while(num[i])putchar(i+'a'-1),--num[i];
					}
				puts("");
			}else{
				for(i=1;i<=26;i++)
					if(i!=c1){
						while(num[i])putchar(i+'a'-1),--num[i];
					}
				while(num[c1])putchar(c1+'a'-1),--num[c1];
				puts("");
			}
		}
	}
}
/*
 * aabababa
 * */