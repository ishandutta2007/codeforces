#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int read(){
	int f=0,x=0;
	char ch=getchar();
	while(!isdigit(ch)){f|=(ch=='-');ch=getchar();}
	while(isdigit(ch)){x=x*10+ch-'0';ch=getchar();}
	return f?-x:x;
}
const int N=2e5+10;
int a[N],b[N],tp;
signed main(){
	int n=read(),k=read(),x=read();
	for(int i=1;i<=n;i++)a[i]=read();
	sort(a+1,a+1+n);
	int cnt=1;
	for(int i=2;i<=n;i++){
		if(a[i]-a[i-1]>x)b[++tp]=(a[i]-a[i-1]+x-1)/x-1,cnt++;
	}
	sort(b+1,b+1+tp);
	for(int i=1;i<=tp;i++){
		if(k>=b[i])k-=b[i],cnt--;
		else break;
	}
	cout<<cnt<<endl;
	return 0;
}