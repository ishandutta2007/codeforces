// Hydro submission #614c87cde7c893b91cbb500e@1632406194762
#include <bits/stdc++.h>
using namespace std;
const int N=100010;
inline int read(){
	int x=0;bool f=false;char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-')	f=true;
		ch=getchar();
	}
	while(isdigit(ch)){
		x=(x<<3)+(x<<1)+(ch^48);
		ch=getchar();
	}
	return f?-x:x;
}
int n;
double p[N],len[N];
double ans;
int main(){
	n=read();
	for(int i=1;i<=n;i++)
		scanf("%lf",p+i);
	for(int i=1;i<=n;i++){
		len[i]=p[i]*(len[i-1]+1);
		ans+=p[i]*(2*len[i-1]+1);
	}
	printf("%.15lf\n",ans);
	return 0;
}