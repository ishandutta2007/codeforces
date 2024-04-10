#include<bits/stdc++.h>
#define ll long long
using namespace std;
inline int read(){
	char c=getchar();int x=0,f=1;
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
    return x*f;
}
int i,j,k,n,m,T,a,b;
string S;
int main(){
	cin>>T;
	while(T--){
		cin>>n>>a>>b;
		cin>>S;
		int w=0;
		for(i=1;i<S.size();i++)
			if(S[i]!=S[i-1])w++;
		if(b>0){
			cout<<a*n+b*n<<endl;
		}else{
			cout<<a*n+b*((w+1)/2+1)<<endl;
		}
	}
	return 0;
}