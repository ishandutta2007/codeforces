#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,pos[500500],a[500500],p,l,r,b[500500],mx,md,cur[500500];
int st[500500][22],l2[500500];
vector<int> sr;
int chk(int l,int r){int k=l2[r-l+1];return max(st[l][k],st[r-(1<<k)+1][k]);}
ll res,sum;

int get(int l,int r){
	int x,y,cx=cur[l],cy=cur[r],res;
	auto it=lower_bound(sr.begin(),sr.end(),l),it2=lower_bound(sr.begin(),sr.end(),r);
	if(it==it2){return cur[r]-cur[l]+(cur[l]>0);}
	if(cx){
		cx=cur[*it]-cx+1;it++;
	}
	x=pos[*it];
	
	it2--;
	y=pos[*it2];
	res=max(cx,cy);
	
	if(x<=y&&x&&y){res=max(res,chk(x,y));}
	return res;
}

int main(){
	scanf("%d",&n);l2[0]=-1;
	sr.push_back(0);
	for(i=1;i<=n+1;i++){
		if(i<=n){scanf("%1d",&a[i]);}
		if(a[i]){
			if(!p){l=i;}p++;
		}
		else{
			if(!p){goto aaa;}
			sr.push_back(i-1);
			pos[l]=pos[i-1]=++m;
			b[m]=p;p=0;
		}
		aaa:mx=max(mx,p);
		res+=mx;
		cur[i]=p;
	}
	sr.push_back(500005);
	res-=mx;
	sum=res;
	for(i=1;i<=m;i++){
		st[i][0]=b[i];l2[i]=l2[i>>1]+1;
	}
	for(j=1;j<=19;j++){
		for(i=1;i+(1<<j)-1<=n;i++){
			st[i][j]=max(st[i][j-1],st[i+(1<<(j-1))][j-1]);
		}
	}
	for(i=2;i<=n;i++){
		sum-=a[i-1];
		l=i;r=n;mx=0;
		while(l<=r){
			md=(l+r)/2;
			if(get(i-1,md)==get(i,md)){r=md-1;}
			else{mx=max(mx,md);l=md+1;}
		}
		
		if(mx){sum-=mx-i+1;}
		res+=sum;
	}
	printf("%lld",res);
}