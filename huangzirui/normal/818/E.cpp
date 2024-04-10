#include<bits/stdc++.h>
#define ll long long
using namespace std;
typedef pair<int,int> pii;
int read(){
	int x=0,b=1;char c;do c=getchar();while((c>'9'||c<'0')&&c!='-');
	if(c=='-')b=0,c='0';do x=x*10+c-'0',c=getchar();while(c>='0'&&c<='9');return b?x:-x;
}

const int maxn=100010;

int i,j,k,n,m,T,a[maxn],t[maxn],nd[maxn],tot,X;

vector<int>S;

int main(){
	cin>>n>>m;
	if(m==1){cout<<1ll*n*(n+1)/2<<endl;return 0;}
	for(i=1;i<=n;i++)a[i]=read();
	for(i=2;i<=m;i++){
		int num=0;
		while(m%i==0)m/=i,++num;
		if(num){S.push_back(i);nd[tot++]=num;}
	}
	int R=0;
	ll ans=0;
	for(int L=1;L<=n;L++){
		while(R!=n && X!=tot){
			R++;
			int w=a[R];
			for(i=0;i<S.size();i++){
				while(w%S[i]==0){
					w/=S[i];
					++t[i];
					if(t[i]==nd[i])++X;
				}
			}
		}
		if(X==tot)ans+=n-R+1;
		for(i=0;i<S.size();i++){
			int w=a[L];
			while(w%S[i]==0){
				w/=S[i];
				if(t[i]==nd[i])--X;
				--t[i];
			}
		}
	}cout<<ans<<endl;
}