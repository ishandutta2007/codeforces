#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
 
struct sb{
	int a,b;
}s[600500];
bool cmp(sb x,sb y){
	return x.a<y.a;
}
int i,j,k,c[7],res=1145141919,used[100500],un,n,l;
 
int main(){
	for(i=1;i<=6;i++){
		scanf("%d",&c[i]);
	}
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d",&k);
		for(j=1;j<=6;j++){
			s[i*6+j-6].a=k-c[j];
			s[i*6+j-6].b=i;
		}
	}
	sort(s+1,s+n*6+1,cmp);
	l=1;
	for(i=1;i<=n*6;i++){
		//printf("%d %d\n",s[i].a,s[i].b);
		if(!used[s[i].b]){un++;}
		used[s[i].b]++;
		if(un<n){continue;}
		while(used[s[l].b]>1){used[s[l].b]--;l++;}
		res=min(res,s[i].a-s[l].a);
		//printf("%d %d %d\n",res,l,i);
	}
	printf("%d",res);
}