#include<bits/stdc++.h>
#define ll long long
using namespace std;
inline int read(){
	char c=getchar();int x=0,f=1;
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
    return x*f;
}
const int maxn=1e5;
int i,j,k,n,m,a[maxn],s[maxn],ans1,ans2,ans3,ans4;
int main(){
	cin>>n;
	for(i=1;i<=n;i++){
		a[i]=read();
		s[a[i]]++;
		if(s[a[i]]==2)ans1++;
		if(s[a[i]]==4)ans2++;
		if(s[a[i]]==6)ans3++;
		if(s[a[i]]==8)ans4++;
	}
	cin>>m;
	for(i=1;i<=m;i++){
		string S;int x;
		cin>>S;x=read();
		if(S=="+"){
			s[x]++;
			if(s[x]==2)ans1++;
			if(s[x]==4)ans2++;
			if(s[x]==6)ans3++;
			if(s[x]==8)ans4++;
		}else{
			s[x]--;
			if(s[x]==1)ans1--;
			if(s[x]==3)ans2--;
			if(s[x]==5)ans3--;
			if(s[x]==7)ans4--;
		}
		if(ans4 || (ans3 && ans1>1) || (ans2>1) || (ans2 && ans1>2))puts("YES");
		else puts("NO");
	}
	return 0;
}