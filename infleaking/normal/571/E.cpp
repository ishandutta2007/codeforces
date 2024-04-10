#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pi;
map<int,int> p;
int n;
struct line{ll x,y,z;}a[105];
ll gcd(ll a,ll b){
	return b?gcd(b,a%b):a;
}
vector<pi> dv[105];
vector<pi> getdiv(int x){
	vector<pi> c;c.clear();
	for (int d=2;d*d<=x;d++){
		if (x%d==0){
			int cnt=0;
			while (x%d==0)cnt++,x/=d;
			c.push_back(make_pair(d,cnt));
		}
	}
	if (x>1)c.push_back(make_pair(x,1));
	return c;
}
void FAIL(){
	cout<<-1<<endl;
	exit(0);
}
ll power(ll a,ll b,ll mo=1e9+7){
	ll ans=1;
	while (b){
		if (b&1)ans=ans*a%mo;
		a=a*a%mo;
		b>>=1;
	}return ans;
}
void SUC(vector<pi> z){
	ll ans=1,mo=1e9+7;
	for (auto i:z)
		ans=ans*power(i.first,i.second)%mo;
	cout<<ans<<endl;
	exit(0);
}
int check(vector<pi> z,int i){
	ll x=a[i].x,y=a[i].y;
	vector<pi> x0=getdiv(a[i].x),y0=getdiv(a[i].y);
	for (auto i:z){
		while (x%i.first==0)x/=i.first;
		while (y%i.first==0)y/=i.first;
	}
	if (x>1)return 0;
	if (y>1){
		if (x0.size()==z.size()){
			for (int i=0;i<z.size();i++){
				if (x0[i]<z[i]||x0[i]>z[i])return 0;	
			}
			return 1;
		}
		return 0;
	}
	x=a[i].x,y=a[i].y;
	int las=-1;
	for (auto i:z){
		int cntx=0,cnty=0;
		while (x%i.first==0)x/=i.first,cntx++;
		while (y%i.first==0)y/=i.first,cnty++;
		if (cnty==0&&cntx!=i.second||cntx>i.second)return 0;
		if (cnty==0)continue;
		int k=(i.second-cntx)/cnty;
		if ((i.second-cntx)%cnty!=0)return 0;
		if (las!=-1&&k!=las)return 0;
		las=k;
	}
	return 1;
}
void merge(vector<pi> &a,vector<pi> b){
	vector<pi> c=a;
	for (auto i:b)c.push_back(i);
	sort(c.begin(),c.end());
	a.clear();
	if (c.size())a.push_back(make_pair(c[0].first,0));
	for (int i=1;i<c.size();i++)
		if (c[i].first!=c[i-1].first)a.push_back(make_pair(c[i].first,0));
}
vector<pi> check2(int i,int j){
	vector<pi> z0=getdiv(a[i].x);
	merge(z0,getdiv(a[i].y));
	merge(z0,getdiv(a[j].x));
	merge(z0,getdiv(a[j].y));
	vector<pi> A=z0,B=z0,C=z0,D=z0;
	int a0=a[i].x,b0=a[i].y,c0=a[j].x,d0=a[j].y;
	for (int i=0;i<z0.size();i++){
		while (a0%z0[i].first==0)A[i].second++,a0/=z0[i].first;
		while (b0%z0[i].first==0)B[i].second++,b0/=z0[i].first;
		while (c0%z0[i].first==0)C[i].second++,c0/=z0[i].first;
		while (d0%z0[i].first==0)D[i].second++,d0/=z0[i].first;
	}
	int k1=-1,k2=-1,suc=0;
	for (k1=0;k1<=100;k1++){
	for (k2=0;k2<=100;k2++){
		if (A[0].second+k1*B[0].second==C[0].second+k2*D[0].second&&A[1].second+k1*B[1].second==C[1].second+k2*D[1].second){
		  	suc=1;
			break;
		}
	}
	if (suc)break;
	}
	if (suc==0)FAIL();
	vector<pi> z1;
	for (int i=0;i<z0.size();i++){
		z0[i].second=A[i].second+B[i].second*k1;
		if (z0[i].second)z1.push_back(z0[i]);
	}
	return z1;
}
int main(){
	int tag1=0,tag2=0;
	cin>>n;
	for (int i=1;i<=n;i++){
		int x,y,k=0,y0;
		scanf("%d%d",&x,&y);
		a[i]=(line){x,y,0};
		for (int d=2;d*d<=y;d++){
			int cnt=0;
			while (y%d==0)cnt++,y/=d;
			k=gcd(k,cnt);
			if (cnt)dv[i].push_back(make_pair(d,cnt));
		}
		if (y>1)k=1,dv[i].push_back(make_pair(y,1));
		if (k)a[i].z=pow(a[i].y,1.0/k)+0.5;
		if (a[i].y==1)tag1=a[i].x;
		if (a[i].z!=a[1].z)tag2=i;
	}
	if (n==1){
		printf("%d\n",a[1].x);
		return 0;
	}
	if (tag1){
		// yi==1
		int x0=tag1;
		vector<pi> z=getdiv(tag1);
		for (int i=1;i<=n;i++){
			if (!check(z,i))FAIL();
		}
		SUC(z);
	}
	if (tag2){
		// have a cross
		vector<pi> z=check2(1,tag2);
		for (int i=1;i<=n;i++){
			if (!check(z,i))FAIL();
		}
		SUC(z);
	}
	int Z=a[1].z;
	for (int i=1;i<=n;i++){
		int x0=a[i].x,y0=a[i].y,z=a[i].z;
		a[i].x=a[i].y=0;
		while (y0%z==0)y0/=z,a[i].y++;
		while (x0%z==0)x0/=z,a[i].x++;
		a[i].z=x0;
		if (a[i].z!=a[1].z)FAIL();
	}
	ll A=a[1].y,B=a[1].x;
	for (int i=2;i<=n;i++){
		int suc=0;
		for (int j=0;j<a[i].y;j++,B+=A){
			if (B%a[i].y==a[i].x%a[i].y){
				suc=1;
				break;
			}
		}
		if (!suc)FAIL();
		else A=A*a[i].y/gcd(A,a[i].y);
	}
	for (int i=1;i<=n;i++)
		while (B<a[i].x)B+=A;
	cout<<power(Z,B)*a[1].z%(1000000007)<<endl;
	// in a line
}