#include<bits/stdc++.h>
using namespace std;
const int N=200005;

int Zero,One,k,Bits;
int ans1[N],ans2[N];

inline int read(){
	int x=0,f=1; char ch=getchar();
	while (!isdigit(ch)) { if (ch=='-') f=-1; ch=getchar(); }
	while (isdigit(ch)) { x=x*10+ch-'0'; ch=getchar(); }
	return x*f;
}

int main(){
	//freopen("CF1492D.in","r",stdin);
	//freopen("CF1492D.out","w",stdout);
	Zero=read(),One=read(),k=read();
	Bits=Zero+One;
	if ((Zero==0) && (k>0)) { printf("No\n"); return 0; }
	if ((Zero==0) && (k==0)){
		printf("Yes\n");
		for (int i=1;i<=Bits;++i) printf("1");
		printf("\n");
		for (int i=1;i<=Bits;++i) printf("1");
		printf("\n");
		return 0;
	}
	if ((One==1) && (k>0)) { printf("No\n"); return 0; }
	if (Bits-2<k){ printf("No\n"); return 0; }
	if (k==0){
		--One; ans1[1]=ans2[1]=1;
		for (int i=2;i<=Bits;++i){
			if (Zero) { --Zero; ans1[i]=ans2[i]=0; }
			else { --One; ans1[i]=ans2[i]=1; }
		}
		printf("Yes\n");
		for (int i=1;i<=Bits;++i) printf("%d",ans1[i]);
		printf("\n");
		for (int i=1;i<=Bits;++i) printf("%d",ans2[i]);
		printf("\n");
		return 0;
	}
	ans1[1]=ans2[1]=1;
	ans1[2]=1,ans2[2]=0;
	ans1[k+2]=0,ans2[k+2]=1;
	One-=2,--Zero;
	for (int i=3;i<=Bits;++i)
		if (i!=k+2){
			if (Zero) { --Zero; ans1[i]=ans2[i]=0; }
			else { --One; ans1[i]=ans2[i]=1; }
		}
	printf("Yes\n");
	for (int i=1;i<=Bits;++i) printf("%d",ans1[i]);
	printf("\n");
	for (int i=1;i<=Bits;++i) printf("%d",ans2[i]);
	printf("\n");
	return 0;
}