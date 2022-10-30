// Hydro submission #61cc6297cb38e9d32635731a@1640784535192
#include<bits/stdc++.h>
using namespace std;
const int N=2e5;
int _,n;
char a[N],b[N];
int main(){
	scanf("%d",&_);
	while(_--){
		int s3=0,s4=0,s1=0,s2=0;
		scanf("%d",&n);
		scanf("%s",a+1);
		scanf("%s",b+1);
		for(int i=1;i<=n;i++){
			if(a[i]=='1'&&b[i]=='1')s1++;
			if(a[i]=='0'&&b[i]=='0')s2++;
			if(a[i]=='1'&&b[i]=='0')s3++;
			if(a[i]=='0'&&b[i]=='1')s4++;
		}
		int ans=1e9;
		if(s3==s4)ans=s3*2;
		if(s2==s1-1)ans=min(ans,s2*2+1);
		printf("%d\n",ans==1e9?-1:ans);
	}
}