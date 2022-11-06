#include<bits/stdc++.h>
#define ri register int
#define fi first
#define se second
using namespace std;
const int rlen=1<<18|1;
inline char gc(){
	static char buf[rlen],*ib,*ob;
	(ib==ob)&&(ob=(ib=buf)+fread(buf,1,rlen,stdin));
	return ib==ob?-1:*ib++;
}
inline int read(){
	int ans=0;
	bool f=1;
	char ch=gc();
	while(!isdigit(ch))f^=ch=='-',ch=gc();
	while(isdigit(ch))ans=((ans<<2)+ans<<1)+(ch^48),ch=gc();
	return f?ans:-ans;
}
typedef pair<int,int> pii;
typedef long long ll;
int a[105],b[105];
bool in[20005];
map<int,bool>vis;
int main(){
	int mod=1<<14;
	for(ri i=1;i<=100;++i)a[i]=i,vis[a[i]]=1;
	for(ri i=1;i<=100;++i)for(ri j=i+1;j<=100;++j)in[a[i]^a[j]]=1;
	int cnt=0;
	for(ri i=0;i<mod;++i){
		if(cnt==100)break;
		if(vis[i])continue;
		bool ff=1;
		for(ri j=1;j<=cnt;++j){
			if(in[b[j]^i]){
				ff=0;
				break;
			}
		}
		if(ff)b[++cnt]=i;
	}
	cout<<"? ";
	for(ri i=1;i<=99;++i)cout<<a[i]<<' ';
	cout<<a[100];
	cout<<endl;
	int x;
	cin>>x;
	cout<<"? ";
	for(ri i=1;i<=99;++i)cout<<b[i]<<' ';
	cout<<b[100];
	cout<<endl;
	int y;
	cin>>y;
	int t=x^y;
	for(ri i=1;i<=100;++i)for(ri j=1;j<=100;++j)if((a[i]^b[j])==t){
		cout<<"! "<<(x^a[i]);
		cout<<endl;
	}
	return 0;
}