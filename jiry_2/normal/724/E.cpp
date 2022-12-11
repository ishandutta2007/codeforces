#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
struct atom{
	int a,w;
}x[21000],s[11000];
int len,tot;
int A[11000],B[11000],n,c;
long long ans;
void insert(int ss,int t){
	len=0; int now=1;
	for (int i=1;i<=tot;i++){
		while (now<=tot&&s[now].a-c>=s[i].a){
			len++; x[len]=(atom){s[now].a-c,-s[now].w}; now++;
		}
		x[++len]=s[i];
	}
	while (now<=tot&&s[now].a-c>0){
		len++; x[len]=(atom){s[now].a-c,-s[now].w}; now++;
	}
	x[len+1].a=0;
	int k=0,pre=ss-t; tot=0;
	for (int i=1;i<=len;i++){
		if (x[i].a<=pre){
			s[++tot]=(atom){pre,1}; 
			for (int j=i;j<=len;j++) if (x[j].w>0) s[++tot]=x[j];
			ans+=t; return;
		}
		if (x[i].w<0){
			tot++; s[tot]=(atom){x[i].a,-x[i].w};
		}
		k+=x[i].w; if (k==0) continue;
		int dis=x[i].a-x[i+1].a;
		if (1ll*dis*k+pre>=x[i+1].a){
			int dis=x[i].a-pre,k2=dis/(k+1),k3=dis%(k+1);
			int a=k-k3+1,b=k3;
			if (a&&x[i].a-k2) s[++tot]=(atom){x[i].a-k2,a};
			if (b&&x[i].a-k2-1) s[++tot]=(atom){x[i].a-k2-1,b};
			for (int j=i+1;j<=len;j++) if (x[j].w>0) s[++tot]=x[j];
			ans+=t; return;
		}
		pre+=dis*k;
	}
	if (pre>0) {s[++tot]=(atom){pre,1}; ans+=t;} else ans+=t+pre;
}
int main(){
	scanf("%d%d",&n,&c);
	len=0; tot=0;
	for (int i=1;i<=n;i++) scanf("%d",&A[i]);
	for (int i=1;i<=n;i++) scanf("%d",&B[i]);
	for (int i=1;i<=n;i++){
		insert(A[i],B[i]);
	//	cout<<"fa "<<A[i]<<" "<<B[i]<<endl;
	//	for (int j=1;j<=tot;j++) cout<<s[j].a<<" "<<s[j].w<<endl;
	//	cout<<ans<<endl;
	}
	cout<<ans<<endl;
	return 0;
}