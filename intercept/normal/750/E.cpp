#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pii pair<int,int>
#define eb emplace_back
#define ll long long
using namespace std;
const int mod=1e9+7;
const int M=2e5+9;
int n,q;
char s[M];
struct P{
	int v2,v0,v1,v6,v20,v01,v201;
	int n2,n0,n1,n6,n20,n01,n201;
};
struct Segment_tree{
    P sum[M<<2],p;
    P merge(P x,P y){
    	P z;
    	z.n2=x.n2+y.n2;
    	z.n1=x.n1+y.n1;
    	z.n0=x.n0+y.n0;
    	z.n6=x.n6+y.n6;
    	z.n20=x.n20|y.n20|(x.n2>0&&y.n0>0);
    	z.n01=x.n01|y.n01|(x.n0>0&&y.n1>0);
    	z.n201=x.n201|y.n201|(x.n20&&y.n1>0)|(x.n2>0&&y.n01);
    	z.v2=z.v0=z.v1=z.v6=z.v20=z.v01=z.v201=1e9;
    	if(x.n2)z.v2=min(z.v2,x.v2+y.n0);
    	if(y.n2)z.v2=min(z.v2,y.v2+x.n2);
    	if(x.n0)z.v0=min(z.v0,x.v0+y.n1);
    	if(y.n0)z.v0=min(z.v0,y.v0+x.n0);
    	if(x.n1)z.v1=min(z.v1,x.v1+y.n6);
    	if(y.n1)z.v1=min(z.v1,y.v1+x.n1);
    	if(x.n20)z.v20=min(z.v20,x.v20+y.n1);
    	if(y.n20)z.v20=min(z.v20,y.v20+x.n2);
    	if(x.n2&&y.n0)z.v20=min(z.v20,x.v2+y.v0);

    	if(x.n01)z.v01=min(z.v01,x.v01+y.n6);
    	if(y.n01)z.v01=min(z.v01,y.v01+x.n0);
    	if(x.n0&&y.n1)z.v01=min(z.v01,x.v0+y.v1);

    	if(x.n201)z.v201=min(z.v201,x.v201+y.n6);
    	if(y.n201)z.v201=min(z.v201,y.v201+x.n2);
    	if(x.n20&&y.n1)z.v201=min(z.v201,x.v20+y.v1);
    	if(x.n2&&y.n01)z.v201=min(z.v201,x.v2+y.v01);
    	return z;
    }
    void pu(int now){
        sum[now]=merge(sum[now<<1],sum[now<<1|1]);
    }
    void query(int now,int l,int r,int x,int y){
        if(x<=l&&r<=y){
        	p=merge(p,sum[now]);
            return;
        }
        int mid=(l+r)>>1;
        if(x<=mid)query(now<<1,l,mid,x,y);
        if(y>mid)query(now<<1|1,mid+1,r,x,y);
    }
    int query(int l,int r){
    	p.n2=p.n1=p.n0=p.n6=p.n20=p.n01=p.n201=0;
    	query(1,1,n,l,r);
    	return p.v201;
    }
    void build(int now,int l,int r){
    	if(l==r){
    		if(s[l]-'0'==2)sum[now].n2=1;
    		if(s[l]-'0'==1)sum[now].n1=1;
    		if(s[l]-'0'==0)sum[now].n0=1;
    		if(s[l]-'0'==6)sum[now].n6=1;
    		return;
    	}
    	int mid=(l+r)>>1;
    	build(now<<1,l,mid);
    	build(now<<1|1,mid+1,r);
    	pu(now);
    }
}T;
int la[10],p[M][10],sum[M];
int main(){
	cin>>n>>q>>(s+1);
	for(int i=1;i<=n;++i){
		la[s[i]-'0']=i;
		for(int j=0;j<10;++j)p[i][j]=la[j];
		sum[i]=sum[i-1]+(s[i]=='6');
	}
	T.build(1,1,n);
	for(int i=1;i<=q;++i){
		int l,r;
		cin>>l>>r;
		if(p[p[p[p[r][7]][1]][0]][2]<l){
			cout<<"-1\n";
			continue;
		}
		int ans=sum[r]-sum[p[r][7]];
		r=p[r][7];
		cout<<ans+T.query(l,r)<<"\n";
	}
	return 0;
}
/*
50 1

77767912070178428778417181176820131402667011621621
5 16

7776 791 207017 8428778417181176820131402667011621621
*/