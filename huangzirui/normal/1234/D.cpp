#include<bits/stdc++.h>
#define Mid ((l+r)/2)
using namespace std;
int i,j,n,m,o;
int num[100010*4];
string s;
int make(int x){
    int ans=0;
    while(x){
        if(x&1)ans++;
        x/=2;
    }return ans;
}
int xds1(int root,int l,int r){
	if(l==r)
		num[root]=1<<(s[l-1]-'a');
	else{
		xds1(root*2,l,Mid);
		xds1(root*2+1,Mid+1,r);
		num[root]=num[root*2]|num[root*2+1];
	}
}
int xds2(int root,int l,int r,int L,int R){
	if(l==L&&r==R)
		return num[root];
	int s=-1;
	if(R<=Mid)
		return xds2(root*2,l,Mid,L,R);
	if(L>Mid)
		return xds2(root*2+1,Mid+1,r,L,R);
	int ans= xds2(root*2,l,Mid,L,Mid)|xds2(root*2+1,Mid+1,r,Mid+1,R);
    return ans;
}
void xds3(int root,int l,int r,int L,int R,int s){
	if(l==r)
        num[root]=s;
    else{
        if(R<=Mid)
            xds3(root*2,l,Mid,L,R,s);
        else
        if(L>Mid)
            xds3(root*2+1,Mid+1,r,L,R,s);
        else{
        	xds3(root*2,l,Mid,L,Mid,s);
        	xds3(root*2+1,Mid+1,r,Mid+1,R,s);
		}
		num[root]=num[root*2]|num[root*2+1];
    }
    return;
}
int main()
{
    cin>>s;
    n=s.size();
	cin>>m;
	int a,b;
    char c;
	xds1(1,1,n);
	for(i=1;i<=m;i++){
		scanf("%d",&o);
		if(o==2){
			scanf("%d%d",&a,&b);
			printf("%d\n",make(xds2(1,1,n,a,b)));
		}else{
			scanf("%d %c",&a,&c);
			xds3(1,1,n,a,a,1<<(c-'a'));
		}
	}
	return 0;
}