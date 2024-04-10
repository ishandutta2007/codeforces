#include<bits/stdc++.h>
#define ll long long
using namespace std;
inline int read(){
	char c=getchar();int x=0,f=1;
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
    return x*f;
}
const int maxn=10010;
int i,j,k,n,m,a[maxn],b[maxn],cnt;
string str;int ans[maxn];
int main(){
	int T;
	cin>>T;
	while(T--){
		memset(a,0,sizeof(a));
		cnt=0;
		cin>>str;for(i=0;i<str.size();i++)a[str[i]-'a'+1]++;
		cin>>n;for(i=1;i<=n;i++)b[i]=read();
		int used=26;
		while(cnt!=n){
			int Num=0;
			queue<int>Q;
			while(!Q.empty())Q.pop();
			for(i=1;i<=n;i++)if(!b[i]){ 
				Q.push(i);
				++Num;
			}
			while(a[used]<Num)used--;
			for(i=1;i<=n;i++)
				if(!b[i]){
					++cnt;
					b[i]=-1;
					ans[i]=used+'a'-1;
				}
			used--;
			while(!Q.empty()){
				int now=Q.front();
				Q.pop();
				for(i=1;i<=n;i++)
					if(b[i]>0)
						b[i]-=abs(now-i);
			}
		}
		for(i=1;i<=n;i++)putchar(ans[i]);
		puts("");
	}
	return 0;
}