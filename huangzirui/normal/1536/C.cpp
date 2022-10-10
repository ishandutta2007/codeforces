#include<bits/stdc++.h>
#define ll long long
using namespace std;
typedef pair<int,int> pii;
int read(){
	int x=0,b=1;char c;do c=getchar();while((c>'9'||c<'0')&&c!='-');
	if(c=='-')b=0,c='0';do x=x*10+c-'0',c=getchar();while(c>='0'&&c<='9');return b?x:-x;
}

const int maxn=500010;

int i,j,k,n,m,T,s[maxn];

map<pii,int>M;

int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	cin>>T;
	while(T--){
		M.clear();
		string S;
		cin>>n;
		cin>>S;
		for(i=1;i<=n;i++)s[i]=S[i-1]=='D';
		int x=0,y=0;
		for(i=1;i<=n;i++){
			if(s[i])x++;else y++;
			int w=__gcd(x,y);
			M[make_pair(x/w,y/w)]++;
			printf("%d ",M[make_pair(x/w,y/w)]);
		}cout<<endl;
	}
}