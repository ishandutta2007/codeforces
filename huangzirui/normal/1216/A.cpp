#include <bits/stdc++.h>
#define ll long long
using namespace std;
int i,j,k,n,m;
void read(int &x){
	char c;x=0;int b=1;do{c=getchar();if(c==45)b=-1;}while(c>57||c<48);
	do x=x*10+c-48,c=getchar();while(c<=57&&c>=48);x*=b;
}
void read(ll &x){
	char c;x=0;int b=1;do{c=getchar();if(c==45)b=-1;}while(c>57||c<48);
	do x=x*10+c-48,c=getchar();while(c<=57&&c>=48);x*=b;
}
string str;
int main() {
    cin>>n>>str;
	int ans=0;
	for(i=0;i<n;i+=2){
		if(str[i]==str[i+1]){ans++;if(str[i]=='a')str[i]='b';else str[i]='a';}
	}cout<<ans<<endl<<str<<endl;
    //cerr << 1.0*clock()/CLOCKS_PER_SEC << endl;
    return 0;
}