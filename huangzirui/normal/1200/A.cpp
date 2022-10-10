#include <bits/stdc++.h>
#define ll long long
using namespace std;
int i,j,k,n,m;
void read(int &x){
	char c;x=0;do c=getchar();while(c>57||c<48);
	do x=x*10+c-48,c=getchar();while(c<=57&&c>=48);
}
void read(ll &x){
	char c;x=0;do c=getchar();while(c>57||c<48);
	do x=x*10+c-48,c=getchar();while(c<=57&&c>=48);
}
int b[11];
int main() {
    scanf("%d\n",&n);
	for(i=1;i<=n;i++){
		char c;
		scanf("%c",&c);
		if(c=='L')
			for(j=0;j<=9;j++){if(!b[j]){b[j]=1;break;}}
		else
		if(c=='R')
			for(j=9;j>=0;j--){if(!b[j]){b[j]=1;break;}}
		else{
			int u=c-'0';
			b[u]=0;
		}
	}
	for(i=0;i<=9;i++)cout<<b[i];
    //cerr << 1.0*clock()/CLOCKS_PER_SEC << endl;
    return 0;
}