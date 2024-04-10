#include<bits/stdc++.h>
#define fo(i,a,b)for(int i=a,_e=b;i<=_e;i++)
#define fd(i,a,b)for(int i=b,_e=a;i>=_e;i--)
#define ll long long
using namespace std;
const int N=1e5+5;
int n,m,ans;
char a[N],b[N];
bool bz;
void R(int &n){
	char c;for(n=0;(c=getchar())<'0'||c>'9';);
	for(;c<='9'&&c>='0';c=getchar())n=n*10+c-48;
}
int pd(char x){
	return x=='a'||x=='e'||x=='i'||x=='o'||x=='u';
}
int main(){
	scanf("%s\n",a+1);
	n=strlen(a+1);
	scanf("%s",b+1);
	m=strlen(b+1);
	if(n==m){
		bz=1;
		fo(i,1,n)if(pd(a[i])!=pd(b[i])){
			bz=0;
			break;
		}
	}
	if(bz)printf("Yes");else printf("No");
}