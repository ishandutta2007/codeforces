
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
int i,j,k,n,m;
string s;
bool C[100];
int main(){
	int t;
	cin>>t;
	while(t--){
		memset(C,0,sizeof(C));
		cin>>s;
		s+='1';
		char G='0';
		int sum=0;
		for(i=0;i<s.size();i++){
			if(s[i]!=G){
				if(sum&1)
					C[G-'a'+1]=true;
				G=s[i];
				sum=1;
			}else ++sum;
		}
		for(i=1;i<=26;i++)
			if(C[i])cout<<(char)(i+'a'-1);
		puts("");
	}
	return 0;
}