//Code by juju527.
#include<bits/stdc++.h>
typedef long long ll;
#define pii pair<int,int>
#define fi first
#define se second
#define mp make_pair
#define vec vector<int>
#define eb emplace_back
using namespace std;
const int maxk=105;
int c[maxk];
int read(){
    int x=0,y=1;
    char ch=getchar();
    while(ch<48||ch>57){if(ch==45)y=-1;ch=getchar();}
    while(ch>=48&&ch<=57)x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
    return x*y;
}
ll f[60],s[60];
bitset<60> b[maxk],buf,tmp;
int main(){
    int T;
	T=read();
	f[0]=f[1]=1;for(int i=2;i<=55;i++)f[i]=f[i-1]+f[i-2];
	s[0]=1;for(int i=1;i<=55;i++)s[i]=s[i-1]+f[i];
	while(T--){
		int k,p=-1;
		k=read();
		ll sum=0;
		for(int i=1;i<=k;i++)c[i]=read(),sum+=c[i];
		for(int i=0;i<=55;i++)if(sum==s[i]){p=i;break;}
		if(p==-1){puts("NO");continue;}
		bool tag=0;
		for(int i=1;i<=k;i++){
			b[i].reset();
			for(int j=p;j>=0;j--)if(c[i]>=f[j])b[i].set(j),c[i]-=f[j];
			if(c[i])tag=1;
			for(int j=p-1;j>=0;j--){
				if(b[i].test(j)&&b[i].test(j+1)){
					if(j%2==0){tag=1;break;}
					for(int l=j-1;l>=0;l-=2)if(b[i].test(l)){tag=1;break;}else b[i].set(l);
					b[i].reset(j);
				}
			}
		}
		if(tag){puts("NO");continue;}
		buf.reset();
		int num=0;
		for(int i=1;i<=k;i++){
			tmp=buf&b[i];
			if(tmp.count()>1){tag=1;break;}
			else if(tmp.count()==1){
				num++;if(num>1){tag=1;break;}
				int c=tmp._Find_first();
				if(c%2==0){tag=1;break;}
				buf=buf|b[i];b[i].reset(c);
				bool tagi=0;
				for(int j=c-2;j>=1;j-=2)if(b[i].test(j))tagi=1;
				if(tagi){
					bool tagj=0;
					for(int j=1;j<=i;j++){
						if(!b[j].test(c))continue;
						for(int l=c-2;l>=1;l-=2)if(b[j].test(l))tagj=1;
						break;
					}
					if(tagj){tag=1;break;}
				}
				for(int j=c-1;j>=0;j-=2)if(buf.test(j)){tag=1;break;}else buf.set(j);
				if(tag)break;
				continue;
			}
			buf=buf|b[i];
		}
		for(int i=0;i<=p;i++)if(!buf.test(i)){tag=1;break;}
		if(tag){puts("NO");continue;}
		puts("YES");
	}
    return 0;
}