#include<bits/stdc++.h>
#define ll long long
using namespace std;
inline int read(){
	char c=getchar();int x=0,f=1;
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
    return x*f;
}
const int maxn=100010;
int i,j,k,n,m,T,a[maxn];
priority_queue<int>Q;
int main(){
	cin>>T;
	while(T--){
		while(!Q.empty())Q.pop();
		cin>>n;
		for(i=1;i<=n;i++)a[i]=read();
		int ans=0,t=0;
		for(i=1;i<=n;i++){
			Q.push(a[i]);
			ans=max(ans,Q.top()-a[i]);
		}
		while(ans)ans/=2,t++;
		cout<<t<<endl;
	}
	return 0;
}