#include<bits/stdc++.h>
#define ll long long
using namespace std;
 int main(){
 	int t;
 	scanf("%d",&t);
	 while(t--){
	 	ll a[3];
	 	ll ans[3];
	 	for(int i=0;i<3;i++){
	 		scanf("%lld",a+i);
		 }
		vector<int> mx;
		vector<int> z;
		ll tmp=0ll;
		for(int i=0;i<3;i++){
			tmp=max(tmp,a[i]);
			if(a[i]==0)z.push_back(i);
		}
		if(!z.empty()){
			if(z.size()==3){
			for(int i=0;i<3;i++){
			ans[i]=1ll;
			}
			}else if(z.size()==2){
				ll x;
				int pos;
				for(int i=0;i<3;i++){
					if(a[i]){
						x=a[i];
						pos=i;
					}
				}
				if(x==1){
					for(int i=0;i<3;i++){
						if(!a[i])ans[i]=2;
						else ans[i]=1;
					}
				}else{
					for(int i=0;i<3;i++){
						if(!a[i])ans[i]=x*x;
						else ans[i]=x;
					}
				}
			}else{
				int pos=z[0];
				ll x=-1,y=-1;
				for(int i=0;i<3;i++){
					if(!a[i]){
						x=a[(i+1)%3];
						y=a[(i+2)%3];
						break;
					}
				}
				if(x!=1ll&&y!=1ll){
					if(x<y){
					for(int i=0;i<3;i++){
						if(!a[i])ans[i]=x+y;
						else if(a[i]==x)ans[i]=x+y;
						else ans[i]=y;
					}	
					}else if(x>y){
						for(int i=0;i<3;i++){
						if(!a[i])ans[i]=x;
						else if(a[i]==x)ans[i]=x;
						else ans[i]=y+x;
					}
					}else{
						int fl=0;
						if(x == 2){
							for(int i=0;i<3;i++){
								if(!a[i])ans[i]=4;
								else if(a[i]==x){
									if(a[(i+1)%3]==x)ans[i]=2;
									else ans[i]=6;
								}
							}	
						}
						else{
							for(int i=0;i<3;i++){
								if(!a[i])ans[i]=(x-1ll)*x;
								else if(a[i]==x){
									if(a[(i+1)%3]==x)ans[i]=x;
									else ans[i]=x*x;
								}
							}	
						}
					}
				}else if(x==1ll&&y==1ll){
					for(int i=0;i<3;i++){
						if(!a[i])ans[i]=2ll;
						else if(a[i]==1ll){
							if(a[(i+1)%3])ans[i]=1ll;
							else ans[i]=3ll;
						}
					}
				}else{
					if(x==1ll){					
						for(int i=0;i<3;i++){
							if(!a[i])ans[i]=2*y;
							else if(a[i]==x){
								ans[i]=1ll;
							}else{
								ans[i]=3*y;
							}
						}
					}else{
						for(int i=0;i<3;i++){
							if(!a[i])ans[i]=x;
							else if(a[i]==x){
								ans[i]=x;
							}else{
								ans[i]=x+1ll;
							}
						}
					}
				}
			}
		
			puts("YES");
			for(int i=0;i<3;i++){
					printf("%lld ",ans[i]);
			}
			puts("");
		}else{
			for(int i=0;i<3;i++){
				if(a[i]==tmp)mx.push_back(i);
			}
			int fl=0;
			for(int i:mx){
				int pre=((i-1)%3+3)%3;
				if(a[pre]==a[i]){
					continue;
				}else{
					fl=i+1;
					break;	
				}
			}
			if(!fl){
				assert(0);
			}else{
				fl--;
				int cnt=3;
				int pre=0;
				while(cnt--){
					ans[fl]=a[fl]+pre;
					pre=ans[fl];
					fl=((fl-1)%3+3)%3;
				}
				for(int i=0;i<3;i++){
					printf("%lld ",ans[i]);
				}
				puts("");
			}
		}
	 } 
 }