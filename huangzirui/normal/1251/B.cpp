#include<bits/stdc++.h>
#define ll long long
using namespace std;
void read(int &x){
	x=0;char ch;
	do ch=getchar();while(ch>'9'||ch<'0');
	do{
		x=x*10+ch-'0';
		ch=getchar();
	}while(ch<='9' && ch>='0');
}
void read(ll &x){
	x=0;char ch;
	do ch=getchar();while(ch>'9'||ch<'0');
	do{
		x=x*10+ch-'0';
		ch=getchar();
	}while(ch<='9' && ch>='0');
}
int i,j,k,n,m,t;
string s;
int main(){
	read(t);
	while(t--){
		read(n);
		bool ji=0,one=0,zero=0;
		for(i=1;i<=n;i++){
			cin>>s;
			if(s.size()&1)ji=1;
			int len=s.size();
			for(j=0;j<len;j++)
				if(s[j]=='1')
					one^=1;
				else
					zero^=1;
		}
		if(ji || ((!one) && (!zero)))cout<<n<<endl;
		else cout<<n-1<<endl;
	}
	return 0;
}