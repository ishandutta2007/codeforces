#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+9;
inline int read(){
	int f=0,x=0;
	char ch=getchar();
	while(!isdigit(ch)){f|=(ch=='-');ch=getchar();}
	while(isdigit(ch)){x=x*10+ch-'0';ch=getchar();}
	return f?-x:x;
}
char s[N];
int cnt[200];
signed main(){
//	freopen("my.txt","w",stdout);
	int t=read();
	while(t--){
		int n=read(),k=read(),ans=0;
		memset(cnt,0,sizeof cnt);
		scanf("%s",s+1);
		if(n%k){puts("-1");continue;}
		int sum=0;
		for(int i=1;i<=n;i++){
			if(!cnt[s[i]])cnt[s[i]]+=k,sum+=k;
			cnt[s[i]]--;
			if(sum<n&&s[i+1]<'z')ans=max(ans,i);
			if(sum==n){
				if(i==n){ans=n;break;}
				for(int j='z';j>='a';j--)if(cnt[j]){
						if(j>(int)s[i+1])
							ans=max(ans,i);
						break; 
					}
			}
			if(sum>n)break;
		}
		sum=0;
		memset(cnt,0,sizeof cnt);
		for(int i=1;i<=ans;i++){
			putchar(s[i]);
			if(!cnt[s[i]])cnt[s[i]]+=k,sum+=k;
			cnt[s[i]]--;
		}if(ans==n){puts("");continue;}
		
		if(sum==n){
			for(int j='a';j<='z';j++)if(cnt[j]){
				int f=1;
				if(j>(int)s[ans+1]){
					putchar(j);
					cnt[j]--;f=0;
					break;
				}if(!f)break;
			}
		}
		else{
			putchar(s[ans+1]+1);
			if(!cnt[s[ans+1]+1])cnt[s[ans+1]+1]+=k,sum+=k;
				cnt[s[ans+1]+1]--;
			cnt[(int)'a']+=n-sum;
		}
		for(int i='a';i<='z';i++)for(int j=1;j<=cnt[i];j++)
				putchar(i);
		puts("");
	}
	return 0;
}