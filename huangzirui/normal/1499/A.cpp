#include<bits/stdc++.h>
#define ll long long
using namespace std;
typedef pair<int,int> pii;
int read(){
	int x=0,b=1;char c;do c=getchar();while((c>'9'||c<'0')&&c!='-');
	if(c=='-')b=0,c='0';do x=x*10+c-'0',c=getchar();while(c>='0'&&c<='9');return b?x:-x;
}
int i,j,k,n,m,T,k1,k2,w,b;
int main(){
	cin>>T;
	while(T--){
		cin>>n>>k1>>k2;
		cin>>w>>b;
		if(w<=min(k1,k2)+(max(k1,k2)-min(k1,k2))/2 &&
		   b<=min(n-k1,n-k2)+(max(n-k1,n-k2)-min(n-k1,n-k2))/2)puts("YES");
		else puts("NO");
	}
}