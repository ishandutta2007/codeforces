#include<bits/stdc++.h>
#define fi first
#define se second
#define LL long long
#define PI std::pair<int,int>
#define MP std::make_pair
char s[505];
int cmp(int x,int y){
	if(x!=y)return x<y?-1:1;
	return 0;
}
int main(){
	int T;
	for(scanf("%d",&T);T--;){
		scanf("%s",s);
		int ans=10;
		for(int i=0;i<1<<10;i++){
			bool flag=1;
			for(int j=0;j<10;j++){
				if(s[j]=='?')continue;
				flag&=(i>>j&1)==s[j]-48;
			}
			if(!flag)continue;
			int a=0,b=0,ra=5,rb=5,ta;
			for(int j=0;j<10;j++){
				if(~j&1){
					a+=i>>j&1;
					ra--;
				}
				else{
					b+=i>>j&1;
					rb--;
				}
				if(cmp(a,b)==cmp(a+ra,b)&&cmp(a,b)==cmp(a,b+rb)){
					ta=j+1;
					break;
				}
			}
			ans=std::min(ans,ta);
		}
		printf("%d\n",ans);
	}
}