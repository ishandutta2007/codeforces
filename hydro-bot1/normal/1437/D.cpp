// Hydro submission #618e1010df417b8c5f5bfb1c@1636700260561
#include<bits/stdc++.h>
using namespace std;
int a[200005];
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int n;
		scanf("%d",&n);
		int lstcnt=1,nowcnt=0,sum=0,cnt=1;
		scanf("%d",&a[1]);
		for(int i=2;i<=n;i++){
			scanf("%d",&a[i]);
			if(a[i]>a[i-1]||nowcnt==0)nowcnt++,sum++;
			else{
				lstcnt--;
				if(!lstcnt){
					lstcnt=sum;
					sum=0;
					cnt++;
					nowcnt=0;
				}
				sum++;
				nowcnt=1;
			}
		}
		printf("%d\n",cnt);
	}
	return 0;
}