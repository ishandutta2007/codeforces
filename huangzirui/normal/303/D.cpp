#include<bits/stdc++.h>
#define ll long long
using namespace std;
typedef pair<int,int> pii;
int read(){
	int x=0,b=1;char c;do c=getchar();while((c>'9'||c<'0')&&c!='-');
	if(c=='-')b=0,c='0';do x=x*10+c-'0',c=getchar();while(c>='0'&&c<='9');return b?x:-x;
}

int i,j,k,n,m,T,is_prime;

ll ksm(ll sum,int num,int mod){
	ll ans=1;
	while(num){
		if(num&1)ans=ans*sum%mod;
		sum=sum*sum%mod;
		num>>=1;
	}return ans;
}

bool check(int x){
	for(int i=2;i<=sqrt(x);i++)
		if(x%i==0)return false;
	return true;
}

vector<int>P;
int gcd(int a,int b){
	return b?gcd(b,a%b):a;
}
int getphi(int x){
	int ans=0;
	for(i=2;i<x;i++)if(gcd(i,x)==1)ans++;
	return ans;
}
void init(int S){
	//cout<<"PHI="<<S<<endl;
	for(int i=2;i<=sqrt(S);i++){
		int num=0;
		while(S%i==0)S/=i,++num;
		if(num)P.push_back(i);
	}if(S!=1)P.push_back(S);
}

bool is(int x){
	if(x%(n+1)==0)return false;
	for(int i=0;i<P.size();i++){
		if(ksm(x%(n+1),n/P[i],n+1)==1)return false;
	}return true;
}

int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	cin>>n>>m;
	init(n);
	if(check(n+1)){
		for(i=m-1;i>=2;i--)
			if(is(i)){
				cout<<i<<endl;
				return 0;
			}
		cout<<-1<<endl;
	}else puts("-1");
}