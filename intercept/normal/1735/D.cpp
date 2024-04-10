#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int sed=131;
const int mod1=1e9+7;
const int mod2=1e9+87;
struct Hash{
	int x1,x2;
	Hash(int t1=0,int t2=0):x1(t1),x2(t2){}
	bool operator != (const Hash&o)const{return x1!=o.x1||x2!=o.x2;}
	bool operator == (const Hash&o)const{return x1==o.x1&&x2==o.x2;}
	bool operator <  (const Hash&o)const{return x1==o.x1?x2<o.x2:x1<o.x1;}
	Hash operator +  (const Hash&o)const{return Hash((x1+o.x1)%mod1,(x2+o.x2)%mod2);}
	Hash operator -  (const Hash&o)const{return Hash((x1-o.x1+mod1)%mod1,(x2-o.x2+mod2)%mod2);}
	Hash operator +  (const int&o)const{return Hash((x1+o)%mod1,(x2+o)%mod2);}
	Hash operator -  (const int&o)const{return Hash((x1+mod1-o)%mod1,(x2+mod2-o)%mod2);}
	Hash operator *  (const int&o)const{return Hash(1ll*x1*o%mod1,1ll*x2*o%mod2);}
	Hash operator *  (const Hash&o)const{return Hash(1ll*x1*o.x1%mod1,1ll*x2*o.x2%mod2);}
};
const int M=1009;
int n,k;
int a[M][29],b[M];
map<Hash,int>mp;
int main(){
	cin>>n>>k;
	for(int i=1;i<=n;++i){
		for(int j=0;j<k;++j){
			cin>>a[i][j];
		}
	}
	for(int i=1;i<=n;++i){
		for(int j=i+1;j<=n;++j){
			Hash x={0,0};
			for(int o=0;o<k;++o){
				if(a[i][o]==a[j][o]){
					x=x*sed+a[i][o];
				}
				else{
					x=x*sed+(3^a[i][o]^a[j][o]);
				}
			}
			if(mp.count(x)){
				b[i]++;
				b[j]++;
				b[mp[x]]++;
			}
		}
		Hash x={0,0};
		for(int o=0;o<k;++o){
			x=x*sed+a[i][o];
		}
		mp[x]=i;
	}
	ll ans=0;
	for(int i=1;i<=n;++i)ans+=b[i]*(b[i]-1)/2;
	cout<<ans<<"\n";
	return 0;
}