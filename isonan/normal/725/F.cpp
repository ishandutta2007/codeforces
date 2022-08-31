#include <bits/stdc++.h>

std::pair<int,int>vec[200001];
int top,n;
bool cmp(std::pair<int,int>a,std::pair<int,int>b){
	return a.first+a.second>b.first+b.second;
}
int main(){
	scanf("%d",&n);
	long long ans=0;
	for(int i=1,a1,b1,a2,b2;i<=n;i++){
		scanf("%d%d%d%d",&a1,&b1,&a2,&b2);
		if(a1<b2&&b1<a2)continue;
		if(a1+b1>=a2+b2){
			vec[++top]=std::make_pair(a1,b1);
			vec[++top]=std::make_pair(a2,b2);
		}
		else{
			if(a1-b2>=0)ans+=a1-b2;
			else ans-=b1-a2;
//			vec[++top]=std::make_pair(a1-b2,b1-a2);
		}
	}
	std::sort(vec+1,vec+top+1,cmp);
	for(int i=1;i<=top;i++){
		if(i&1)ans+=vec[i].first;
		else ans-=vec[i].second;
	}
	printf("%lld\n",ans);
}