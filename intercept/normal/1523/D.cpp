#include<bits/stdc++.h>
#define pbb pair<bitset<M>,long long>
#define pii pair<pbb,int>
#define eb emplace_back
#define ll long long
#define bp __builtin_popcountll
using namespace std;
const int M=2e5+9;
int n,m,q,mx;
ll ans,a[M],s[M];
mt19937 rd(time(0));
int v[69];
char t[69];
int main(){
	scanf("%d%d%d",&n,&m,&q);
	for(int i=1;i<=n;++i){
		scanf("%s",&t);
		for(int j=0;j<m;++j){
			if(t[j]=='1')a[i]|=1ll<<j;
		}
	}
	for(int T=1;T<=50;++T){
		int x=rd()%n+1,num=0;
		for(int j=0;j<m;++j){
			if((a[x]>>j)&1)v[num++]=j;
		}
		for(int S=1<<num,j=0;j<S;++j)s[j]=0;
		for(int i=1;i<=n;++i){
			ll y=0;
			for(int j=0;j<num;++j){
				if((a[i]>>v[j])&1)y|=1<<j;
			}
			s[y]++;
		}
		for(int S=1<<num,mid=1;mid<S;mid<<=1){
			for(int j=0;j<S;j+=mid<<1){
				for(int k=0;k<mid;++k){
					s[j+k]+=s[j+k+mid];
				}
			}
		}
		for(int S=1<<num,j=0;j<S;++j){
			if(s[j]>=(n+1)/2&&bp(j)>mx){
				mx=bp(j),ans=0;
				for(int k=0;k<num;++k)if(j>>k&1)ans|=1ll<<v[k];
			}
		}
	}
	for(int i=0;i<m;++i)cout<<(ans>>i&1);
	return 0;
}