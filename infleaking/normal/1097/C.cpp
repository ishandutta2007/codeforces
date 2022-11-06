#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
const int N=1e6+10;
int cnt1[N],n,cnt2[N],mx,mn,c0;
char s[N];
int d[N],t,mxl;
int main(){
	cin>>n;
	for (int i=1;i<=n;i++){
		scanf("%s",s);
		int l=strlen(s),cnt=0;mx=-l-1,mn=l+1;
		t=0;mxl=max(mxl,l);
		for (int i=0;i<l;i++){
			if (t&&d[t]=='('&&s[i]==')')t--;
			else d[++t]=s[i];
		}
		int can=1;
		for (int i=2;i<=t;i++)if (d[i]!=d[i-1])can=0;
		if (can){
			if (!t){
				c0++;
				continue;
			}
			if (d[t]=='(')cnt1[t]++;
			if (d[t]==')')cnt2[t]++;
		}
	}
	int ans=c0/2;
	for (int i=1;i<=mxl;i++)ans=ans+min(cnt1[i],cnt2[i]);
	cout<<ans<<endl;
}