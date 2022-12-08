#include<bits/stdc++.h>
using namespace std;
int n,h,a,b,q;
int ta,fa,tb,fb;
int main()
{
    scanf("%d%d%d%d%d",&n,&h,&a,&b,&q);
    for(int i=1;i<=q;i++){
	scanf("%d%d%d%d",&ta,&fa,&tb,&fb);
	if(ta==tb){
	    printf("%d\n",abs(fa-fb));
	    continue;
	}
	int ans=abs(ta-tb);
	if(fa>b){
	    ans+=fa-b;
	    fa=b;
	}
	else if(fa<a){
	    ans+=a-fa;
	    fa=a;
	}
	ans+=abs(fa-fb);
	printf("%d\n",ans);
    }
    return 0;
}