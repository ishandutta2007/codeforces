#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=5e5+5;
int read(){
    int x=0,y=1;
    char ch=getchar();
    while(ch<48||ch>57){if(ch==45)y=-1;ch=getchar();}
    while(ch>=48&&ch<=57)x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
    return x*y;
}
int T,n;
int lowbit[maxn],tt[maxn];
vector<int>v[27];
string s,t,p;
void update(int x,int v){while(x<=n)tt[x]+=v,x+=lowbit[x];}
int query(int x){int res=0;while(x)res+=tt[x],x-=lowbit[x];return res;}
int main(){
	T=read();
	for(int i=1;i<=100000;i++)lowbit[i]=i&-i;
	while(T--){
		n=read();
		cin>>s>>t;p=s;
		ll res=1ll*n*n;
		sort(p.begin(),p.end());
		if(p>=t){puts("-1");continue;}
		for(int i=1;i<=26;i++)v[i].clear();
		for(int i=0;i<n;i++)v[s[i]-'a'+1].push_back(i);
		for(int i=1;i<=26;i++)reverse(v[i].begin(),v[i].end());
		ll tot=0;
		for(int i=0;i<n;i++){
			int w=t[i]-'a'+1,pos;
			for(int j=1;j<w;j++)if(v[j].size())res=min(res,tot+v[j][v[j].size()-1]-query(v[j][v[j].size()-1]));
			if(!v[w].size())break;
			pos=v[w][v[w].size()-1];tot+=pos-query(pos);
			update(pos+1,1),v[w].pop_back();
		}
		printf("%lld\n",res);
		for(int i=1;i<=n;i++)tt[i]=0;
	}
	return 0;
}