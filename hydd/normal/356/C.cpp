#include<bits/stdc++.h>
using namespace std;
int n,ans;
int main(){
	scanf("%d",&n);
	int x,a=0,b=0,c=0,d=0;
	for (int i=1;i<=n;i++){
		scanf("%d",&x);
		if (x==1) a++;
		if (x==2) b++;
		if (x==3) c++;
		if (x==4) d++;
	}
	x=min(a,b); ans+=x; a-=x; b-=x; c+=x;
	x=a/3; ans+=2*x; a-=3*x; c+=x;
	x=b/3; ans+=2*x; b-=3*x; c+=2*x;
	if (a==1){
		if (c>=1) a--,c--,d++,ans++;
		else
			if (d>=2) a--,d-=2,c+=3,ans+=2;
			else ans=-1;
		printf("%d\n",ans); return 0;
	}
	if (a==2){
		if (c>=2) a-=2,c-=2,d+=2,ans+=2;
		else
			if (d>=1) a-=2,d--,c+=2,ans+=2;
			else ans=-1;
		printf("%d\n",ans); return 0;
	}
	if (b==1){
		if (d>=1) b--,d--,c+=2,ans++;
		else
			if (c>=2) b--,c-=2,d+=2,ans+=2;
			else ans=-1;
		printf("%d\n",ans); return 0;
	}
	if (b==2){
		b-=2; d++; ans+=2;
		printf("%d\n",ans); return 0;
	}
	printf("%d\n",ans);
	return 0;
}