#include "bits/stdc++.h"
 
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
mt19937_64 rng(time(0));
 
const int mn = 1e5+10;
const ll mod = 1e9+7;

vector<int> p,f;
bool isp[mn];
int ex[mn];
const int SIZE=100;
int r[mn];

int main()
{
	cin.tie(0);
	cin.sync_with_stdio(0);
	int n;
	cin>>n;
	fill(isp+2,isp+mn,1);
	int tot=0;
	for(int i=2;i*i<=n;i++)for(int j=i*i;j<=n;j+=i)ex[i]+=isp[j],isp[j]=0;
	for(int i=2;i<=n;i++)if(isp[i])p.push_back(i),ex[i]++;
	bool done=false;
	for(int i=0;i<p.size();i++){
		cout<<"B "<<p[i]<<endl;
		int num;
		cin>>num;
		if(num!=ex[p[i]])f.push_back(p[i]);
		tot+=ex[p[i]];
		if((i%SIZE==SIZE-1||i==p.size()-1)&&!done){
			cout<<"A 1"<<endl;
			cin>>num;
			if(n-num==tot)continue;
			for(int j=i/SIZE*SIZE;j<=i;j++){
				cout<<"A "<<p[j]<<endl;
				cin>>num;
				if(num==1){
					done=true;
					f.push_back(p[j]);
					break;
				}
			}
		}
	}
	int ans=1;
	for(int x:f){
		ll cur=x;
		for(ll i=(ll)x*x;i<=n;i*=x){
			cout<<"A "<<i<<endl;
			int num;
			cin>>num;
			if(num==1)cur=i;
			else break;
		}
		ans*=cur;
	}
	cout<<"C "<<ans<<endl;
}