// Hydro submission #62137ec0980fd8119221323c@1645444801290
#include<bits/stdc++.h>
using namespace std;

int c,hr,hb,wr,wb;

int main(){
	scanf("%d%d%d%d%d",&c,&hr,&hb,&wr,&wb);
	if(wb>wr)swap(hr,hb),swap(wr,wb);
	long long ans=0;
	if((long long)wr*wr>=c){
		for(int i=0;i*wr<=c;i++)
			ans=max(ans,i*(long long)hr+
				(c-i*(long long)wr)/wb*hb);
		printf("%lld\n",ans);
	}
	else{
		if((long long)hr*wb>(long long)hb*wr)
			swap(hr,hb),swap(wr,wb);
		for(int i=0;i<=wb;i++)
			ans=max(ans,i*(long long)hr+
				(c-i*(long long)wr)/wb*hb);
		printf("%lld\n",ans);
	}
	return 0;
}