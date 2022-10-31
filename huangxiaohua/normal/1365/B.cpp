#include<bits/stdc++.h>
using namespace std;
int n,i,j,a,yes,sb[666],one,zero,tmp;
int main(){
	scanf("%d",&n);
	while(n--){
		scanf("%d",&a);yes=1;one=zero=0;
		for(i=1;i<=a;i++){
			scanf("%d",&sb[i]);
			if(i>=2&&sb[i]<sb[i-1]){yes=0;
			}
		}
		for(i=1;i<=a;i++){
			scanf("%d",&tmp);
			if(tmp==1){one=1;
			}if(tmp==0){zero=1;
			}
		}
		if(one+zero==2){yes=1;}
		if(yes==1){puts("Yes");
		}else{puts("No");
		}
	}
}