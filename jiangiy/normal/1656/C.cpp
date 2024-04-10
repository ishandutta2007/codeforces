#include<bits/stdc++.h>
#define LL long long
#define PI std::pair<int,int>
#define MP std::make_pair
using namespace std;
int s[200005];
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int n;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)scanf("%d",s+i);
		s[n+1]=-1;
		sort(s+1,s+n+1);
		bool flag=1;
		if(s[1]==1&&s[n]==1);
		else if(s[1]==0){
			for(int i=1;i<=n;i++) if(s[i]==1)flag=0;
		}
		else if(s[1]==1){
			for(int i=1;i<=n;i++) if(s[i]==2)flag=0;
			for(int i=n;i;i--) if(s[i]>2){
				if(*lower_bound(s+1,s+n+1,s[i]-1)==s[i]-1)flag=0;
			}
		}
		puts(flag?"YES":"NO");
	}
}