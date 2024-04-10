#include<bits/stdc++.h>
using namespace std;
#define N 100005
int t,n,k,a[27],x[27],i,fir,j,Q;
char s[N];
int main(){
	scanf("%d",&t);
	while(t--){
		memset(a,0,sizeof(a));Q=0;
		scanf("%d%d%s",&n,&k,s+1);
		for(i=1;i<=strlen(s+1);++i)a[s[i]-'a']++;
		for(i=0;i<=25;++i){
			if(a[i]){
				fir=i;break;
			}
		}
		for(i=0;i<=25;++i)if(a[i])++Q;
		if(a[fir]>=k){
				if(Q==1){
					for(i=1;i<=(a[fir]+k-1)/k;++i){
						cout<<char('a'+fir);
					}cout<<"\n";
				}
				else if(a[fir]==k&&Q==2){
					if(a[fir]==k){
						cout<<char(fir+'a');
						for(i=fir+1;i<=25;++i){
							if(a[i]){fir=i;break;}
						}
						for(i=1;i<=(a[fir]+k-1)/k;++i){
							cout<<char(fir+'a');
						}cout<<"\n";
					}
				}
			else{
			a[fir]-=k-1;
			for(i=fir;i<=25;++i){
				for(j=1;j<=a[i];++j){
					cout<<char(i+'a');
				}
			}cout<<"\n";
			}
		}
		else{
			for(i=0;i<=25;++i){
				if(a[i]>=k){cout<<char(i+'a')<<"\n";break;}
				k-=a[i];
			}
		}
	}
	return 0;
}