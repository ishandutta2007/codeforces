/************************************************
*Author        :  xzj213
*Created Time  :  2020.12.01.15:17
*Mail          :  xzj213@qq.com
*Problem       :  B
************************************************/
#include <bits/stdc++.h>
using namespace std;
const int maxn=3e5+5;
int T,n,f[maxn];
void chkmax(int &a,int b) {if (a<b)a=b;}
void chkmin(int &a,int b) {if (a>b)a=b;}
int read() {
	int x=0,f=1;
	char ch=getchar();
	while (ch>57 || ch<48) {if(ch==45)f=-1;ch=getchar();}
	while (ch<=57 && ch>=48) {x=x*10+ch-48;ch=getchar();}
	return x*f;
}
int main() {
    T=read();
	while(T--) {
		n=read();
		for (int i=0;i<=n;i++) f[i]=0;
		string str;
		cin>>str;
		char ch='-';
		for (int i=0;i<str.size();i++) {
			if (str[i]=='-') f[i]=f[(i+1)%n]=1;
			else ch=str[i];
		}
		bool flag=false;
		for (int i=0;i<str.size();i++) {
			if (str[i]!=ch && str[i]!='-') {
				flag=true;
				break;
			}
		}
		if (!flag) {cout<<n<<endl;continue;}
		int cnt=0;
		for (int i=0;i<n;i++) if (f[i]) cnt++;
		cout<<cnt<<endl;
	}
	//cerr<<"Time : "<<1.0*clock()/CLOCKS_PER_SEC<<endl;
    return 0;
}