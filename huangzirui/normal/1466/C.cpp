#include<bits/stdc++.h>
#define ll long long
using namespace std;
inline int read(){
	char c=getchar();int x=0,f=1;
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
    return x*f;
}
int i,j,k,n,m,T,Sta[100010],top;
int main(){
	cin>>T;
	while(T--){
		string S;cin>>S;n=S.size();top=0;int ans=0;
		for(i=1;i<=n;i++){
			Sta[++top]=S[i-1];
			if(top>1 && Sta[top]==Sta[top-1])Sta[top]=-i,ans++;
			if(top>2 && Sta[top]==Sta[top-2])Sta[top]=-i,ans++;
		}cout<<ans<<endl;
	}
	return 0;
}