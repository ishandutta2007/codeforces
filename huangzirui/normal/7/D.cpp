#include <bits/stdc++.h>
#define ll long long
#define Mid ((L+R)>>1)
using namespace std;
typedef pair<int,int> pii;
inline int read(){
	char c;int x=0;int b=1;do{c=getchar();if(c==45)b=-1;}while(c>57||c<48);
	do x=x*10+c-48,c=getchar();while(c<=57&&c>=48);x*=b;return x;
}
const int maxn=5000010;
int i,j,k,n,m,len[maxn*2],ans[maxn*2],S;
char s[maxn*2],s2[maxn*2];
void manacher(){
	int Max=0,R=-1;
	for(i=1;i<=2*n+2;i++){
		if(i<=R)len[i]=min(len[2*Max-i],R-i+1);else len[i]=1;
		while(i-len[i]>=0 && i+len[i]<=2*n+2 && s2[i-len[i]]==s2[i+len[i]])len[i]++;
		if(i+len[i]-1>R)R=i+len[i]-1,Max=i;
		//cout<<i<<' '<<s2[i]<<' '<<len[i]<<" R="<<R<<endl;
	}
}
int main() {
	scanf("%s",s);n=strlen(s);
	s2[0]='#';for(i=0;i<n;i++)s2[2*i+1]=s[i],s2[2*i+2]+='#';
	manacher();
	for(i=1;i<=2*n+2;i++){
		if(len[i]==i+1)ans[i]=ans[i/2]+1;
		S+=ans[i];//cout<<i<<' '<<ans[i]<<endl;
	}cout<<S<<endl;
	//cerr << 1.0*clock()/CLOCKS_PER_SEC << endl;
	return 0;
}