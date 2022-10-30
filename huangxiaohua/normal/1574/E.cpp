#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define M 998244353
#define inv2 499122177

ll ksm(ll a,ll p){ll res=1;while(p){if(p&1){res=res*a%M;}a=a*a%M;p>>=1;}return res;}
ll su(ll a,ll b){a+=b;return (a>=M)?a-M:a;}

int i,j,k,n,m,t,x,y,w;
ll p2[2005000],res1,tmp,ans,num0,num1,num2,res2,num00,num11,num22,no1,no0,no00,no11;
int b[1005000][2],b2[1005000],b3[1005000][2],b4[1005000];

int f10,f01,n0,n1,no,sb,s2,s3;
map<int,map<int,int> >mp;

void jia(int x,int y,int w){
	if(w==-1)w=0;
	//10101010
	sb=(w^(x&1));
	if(!b[y][sb]){
		if(b2[y]==2){num2--;num1++;}
		if(b2[y]==1){num1--;num0++;}
		b2[y]--;
	}
	b[y][sb]++;
	s2=(sb^(y&1));
	if(s2==0){no0++;}
	else{no1++;}
	//any
	sb=(w^(y&1));
	if(!b3[x][sb]){
		if(b4[x]==2){num22--;num11++;}
		if(b4[x]==1){num11--;num00++;}
		b4[x]--;
	}
	b3[x][sb]++;
	s2=(sb^(x&1));
	if(s2==0){no00++;}
	else{no11++;}
}

void jian(int x,int y,int w){
	if(w==-1)w=0;
	//10101010
	sb=(w^(x&1));
	if(1==b[y][sb]){
		if(b2[y]==1){num2++;num1--;}
		if(b2[y]==0){num1++;num0--;}
		b2[y]++;
	}
	b[y][sb]--;
	s2=(sb^(y&1));
	if(s2==0){no0--;}
	else{no1--;}
	//any
	sb=(w^(y&1));
	if(1==b3[x][sb]){
		if(b4[x]==1){num22++;num11--;}
		if(b4[x]==0){num11++;num00--;}
		b4[x]++;
	}
	b3[x][sb]--;
	s2=(sb^(x&1));
	if(s2==0){no00--;}
	else{no11--;}
}

int main(){
	p2[0]=1;
	for(i=1;i<=2000005;i++){p2[i]=su(p2[i-1],p2[i-1]);}
	scanf("%d%d%d",&n,&m,&t);
	num2=m;num22=n;k=max(n,m);
	for(i=1;i<=k;i++){b2[i]=2;}
	for(i=1;i<=k;i++){b4[i]=2;}
	while(t--){
		scanf("%d%d%d",&x,&y,&w);
		if(w==-1){
			if(mp[x][y]==1){jian(x,y,1);}
			if(mp[x][y]==-1){jian(x,y,-1);}
			mp[x][y]=0;
		}
		else{
			if(!w)w=-1;
			if(mp[x][y]==0){jia(x,y,w);}
			else{
				if(mp[x][y]!=w){
					jian(x,y,mp[x][y]);
					jia(x,y,w);
				}
			}
			mp[x][y]=w;
		}
		if(num0){res2=0;}else{res2=p2[num2];}
		if(num00){res1=0;}else{res1=p2[num22];}
		f10=(!no0)&(!no00);
		f01=(!no11)&(!no1);
		ans=su(res1,res2);
		ans=su(ans,M-f10-f01);
		ans=(ans%M+M)%M;
		printf("%lld\n",ans);
	}
}