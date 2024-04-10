#include<bits/stdc++.h>
#define ll long long
using namespace std;
inline int read(){
	char c=getchar();int x=0,f=1;
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
    return x*f;
}
int i,j,k,n,m,Sum[2];
int main(){
	int T;
	cin>>T;
	while(T--){
		string S;
		cin>>S;n=S.size();
		Sum[0]=Sum[1]=0;
		for(int i=0;i<n;i++)Sum[S[i]-'0']++;
		k=min(Sum[0],Sum[1]);
		if(k%2)puts("DA");
		else puts("NET");
	}
	return 0;
}