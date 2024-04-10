#include <cstdio>
#include <algorithm>

using std::max;

long long stk[1000001],top,a[1000001],S[1000001],tot,n,k[1000001],b[1000001],fin;
double Int[1000001];
double intersect(int i,int j){
	return (double)(b[i]-b[j])/(double)(k[j]-k[i]);
}
int main(){
	scanf("%I64d",&n);
	for(int i=1;i<=n;i++)scanf("%I64d",a+i),tot+=a[i]*i,S[i]=S[i-1]+a[i];
	for(int i=1;i<=n;i++){
		int l=2,r=top,mid,ans=1;
		while(l<=r){
			mid=(l+r)>>1;
			if((long long)Int[mid]<a[i])ans=mid,l=mid+1;
			else r=mid-1;
		}
		if(i>1)fin=max(fin,a[i]*stk[ans]-a[i]*i+S[i-1]-S[stk[ans]-1]);
		k[i]=i;
		b[i]=-S[i-1];
		while(top>1&&intersect(i,stk[top-1])<Int[top])--top;
		stk[++top]=i;
		if(top>1)Int[top]=intersect(i,stk[top-1]);
	}
	top=0;
	for(int i=n;i;i--){
		int l=2,r=top,mid,ans=1;
		while(l<=r){
			mid=(l+r)>>1;
			if((long long)Int[mid]>a[i])ans=mid,l=mid+1;
			else r=mid-1;
		}
		if(i<n)fin=max(fin,a[i]*stk[ans]-a[i]*i+S[i]-S[stk[ans]]);
		k[i]=i;
		b[i]=-S[i];
		while(top>1&&intersect(i,stk[top-1])>Int[top])--top;
		stk[++top]=i;
		if(top>1)Int[top]=intersect(i,stk[top-1]);
	}
	printf("%I64d",tot+fin);
}