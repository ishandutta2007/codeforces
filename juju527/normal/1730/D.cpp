//Code by juju527.
#include<bits/stdc++.h>
typedef long long ll;
#define pii pair<int,int>
#define fi first
#define se second
#define vec vector<int>
#define eb emplace_back
using namespace std;
const int maxn=1e5+5;
char s[maxn],t[maxn];
int read(){
    int x=0,y=1;
    char ch=getchar();
    while(ch<48||ch>57){if(ch==45)y=-1;ch=getchar();}
    while(ch>=48&&ch<=57)x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
    return x*y;
}
map<pii,int> mp;
int main(){
    int T;
	T=read();
	while(T--){
		int n;
		n=read();
		scanf("%s",s+1);
		scanf("%s",t+1);
		mp.clear();
		for(int i=1;i<=n;i++){
			int u=s[i]-'a',v=t[n-i+1]-'a';
			if(u>v)swap(u,v);
			mp[pii(u,v)]++;
		}
		int cnt=0,cur=0;
		for(auto p:mp)if((p.se&1)&&p.fi.fi==p.fi.se)cnt++;else if(p.se&1)cur++;
		if(cur){puts("NO");continue;}
		if(cnt<=1)puts("YES");else puts("NO");
	}
    return 0;
}