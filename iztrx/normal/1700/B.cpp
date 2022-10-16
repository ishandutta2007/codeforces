#include<bits/stdc++.h>
using namespace std;
#define ll long long
string s;
int T,n,i;
char t[1000005];
int main(){
	cin>>T;
	while(T--){
		cin>>n>>s;
		if(s[0]!='9'){
			for(i=0;i<n;++i)putchar('9'-s[i]+'0');
		}
		else{
			for(i=0;i<n;++i)t[i]='9'+1-s[i];
			t[n-1]+=1;
			for(i=n-1;i;--i){
				if(t[i]<10)continue;
				t[i]-=10;
				t[i-1]+=1;
			}
			for(i=0;i<n;++i)putchar(t[i]+'0');
		}
		putchar('\n');
	}
}