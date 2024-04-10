#include<iostream>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
int c[1100000],v[1100000],w[1100000],n,K,s1[1100000],s2[1100000],len1,len2,pre1,pre2;
void insert(int k){
	while (len1>=pre1&&v[s1[len1]]<=v[k]) len1--;
	s1[++len1]=k;
	while (len2>=pre2&&c[s2[len2]]>=c[k]) len2--;
	s2[++len2]=k;
}
int main(){
	scanf("%d%d",&n,&K);
	for (int i=1;i<=n;i++) scanf("%d",&v[i]);
	for (int i=1;i<=n;i++) scanf("%d",&c[i]);
	pre1=1; pre2=1; len1=1; len2=1;
	int now=1; s1[1]=1; s2[1]=1;
	for (int i=1;i<=n;i++){
		if (now<i) insert(i),now++;
		while (s1[pre1]<i) pre1++;
		while (s2[pre2]<i) pre2++;
		while (now<n){
			int k1=v[s1[pre1]],k2=c[s2[pre2]];
			if (k1*100>=k2) break;
			k1=max(k1,v[now+1]); k2=min(k2,c[now+1]);
			if (k1*100<k2) {insert(now+1); now++;} else break;
		}
		int k1=v[s1[pre1]],k2=c[s2[pre2]];
		w[i]=min(k1*100,k2);
		if (now!=n){
			k1=max(k1,v[now+1]); k2=min(k2,c[now+1]);
			w[i]=max(w[i],min(k1*100,k2));
		}
	}
	sort(w+1,w+n+1);
	double ans=0,noww=(double)K/(double)n;
	for (int i=1;i<=n-K+1;i++){
		ans=ans+w[i]*noww;
		int k1=n-K+1-i,k2=n-i;
		noww=noww*k1/k2;
	}
	printf("%.11lf\n",ans);
	return 0;
}