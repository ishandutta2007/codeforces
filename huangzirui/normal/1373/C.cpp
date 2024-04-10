#include<bits/stdc++.h>
#define ll long long
using namespace std;
inline int read(){
	char c=getchar();int x=0,f=1;
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
    return x*f;
}
int i,j,k,n,m,Sum[2];
int main(){
	int T;
	cin>>T;
	while(T--){
		string S;
		cin>>S;n=S.size();
		ll ans=0;int Sum=0,Min=0,h;
		for(i=0;i<n;i++)
			if(S[i]=='-')Sum--,Min=min(Min,Sum);
			else Sum++;
		h=Min;Min=0;Sum=0;
		for(i=0;i<n;i++){
			if(S[i]=='-')Sum--,Min=min(Min,Sum);
			else Sum++;
			ans+=(-h+Min+1);
		}printf("%lld\n",ans-h);
	}
	return 0;
}