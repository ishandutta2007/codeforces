#include<bits/stdc++.h>
#define ll long long
using namespace std;
inline int read(){
	char c=getchar();int x=0,f=1;
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
    return x*f;
}
int i,j,k,n,m,T;
int main(){
	cin>>T;
	while(T--){
		string S;
		cin>>S;
		int is=0;
		for(int i=0;i<S.size();i++){
			if(S[i]=='0')is=1;
		}
		if(!is){
			puts("0");
			continue;
		}
		is=0;int last=0;
		for(int i=0;i<S.size();i++){
			if(S[i]=='0'){
				last=1; 
			}else is+=last,last=0;
		}is+=last;
		if(is<=1)puts("1");
		else puts("2");
	}
	return 0;
}