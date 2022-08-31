#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,v,n1,n2,ans,t;
pair<int,int>a[N],b[N];
int main(){
	scanf("%d%d",&n,&v);
	for(int i=1;i<=n;++i){
		int type;
		scanf("%d",&type);
		switch(type){
			case 1:
				++n1;
				scanf("%d",&a[n1].first);
				a[n1].second=i;
				break;
			case 2:
				++n2;
				scanf("%d",&b[n2].first);
				b[n2].second=i;
				break;
		}
	}
	sort(a+1,a+n1+1,greater<pair<int,int> >());
	sort(b+1,b+n2+1,greater<pair<int,int> >());
	for(int i=2;i<=n1;++i){
		a[i].first+=a[i-1].first;
	}
	for(int i=2;i<=n2;++i){
		b[i].first+=b[i-1].first;
	}
	for(int i=0;i<=min(v/2,n2);++i){
		if(b[i].first+a[min(n1,v-i*2)].first>ans){
			ans=b[i].first+a[min(n1,v-i*2)].first;
			t=i;
		}
	}
	printf("%d\n",ans);
	for(int i=1;i<=t;++i){
		printf("%d ",b[i].second);
	}
	for(int i=1;i<=min(n1,v-t*2);++i){
		printf("%d ",a[i].second);
	}
	return 0;
}