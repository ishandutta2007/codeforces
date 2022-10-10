#include<bits/stdc++.h>
#define ll long long
using namespace std;
inline int read(){
	char c=getchar();int x=0,f=1;
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
    return x*f;
}
const int maxn=400010;
int i,j,k,n,m,t,S[maxn];
string str;
int main(){
	cin>>t;
	while(t--){
		int ans=0;
		cin>>n>>k;
		cin>>str;
		memset(S,0,sizeof(S));
		for(int i=1;i<=n;i++)
			S[i]=S[i-1]+(str[i-1]=='1');
		for(int i=1;i<=n;i++){
			if(S[i]==S[max(0,i-k-1)] && S[min(n,i+k)]==S[i-1]){
				++ans;i+=k;
			}
		}
		for(int i=1;i<=n;i++)
			S[i]=0; 
		printf("%d\n",ans);
	}
	return 0;
}