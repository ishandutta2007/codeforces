// Hydro submission #62da20e525d42d05161c6b0d@1658462437964
#include<bits/stdc++.h>
using namespace std;
struct node{
	int x,a;
}a1[101],a2[101];
int t1,t2,s;
bool cmp1(node x,node y)
{
	return x.a<y.a;
}
bool cmp2(node x,node y)
{
	return x.a>y.a;
}
int main()
{
	int n,b,mxt,i;
	cin>>n;
	for(i=1;i<=n;i++)
	{
	    cin>>b;
		if(b>0) cin>>a1[++t1].x,a1[t1].a=b;
		else cin>>a2[++t2].x,a2[t2].a=b;
	}
	sort(a1+1,a1+t1+1,cmp1);
	sort(a2+1,a2+t2+1,cmp2);
	mxt=min(t1,t2);
	for(i=1;i<=mxt;i++)
	s+=(a1[i].x+a2[i].x);
	if(t1>t2) s+=a1[mxt+1].x;
	if(t1<t2) s+=a2[mxt+1].x;
	printf("%d\n",s);
	return 0;
}