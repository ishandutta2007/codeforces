#include <bits/stdc++.h>
 
using namespace std;
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define int long long
typedef long long ll;
typedef pair<int,int> pii;
typedef long double ld;
#define MAXN 512345
#define INF INT_MAX/2
#define MOD 1000000007

int n,l,r,ql,qr;
int w[112345];


int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.precision(11);
  	cout.setf(ios::fixed);

  	cin>>n>>l>>r>>ql>>qr;

  	int sum=0;
  	for(int i=0;i<n;i++){
  		cin>>w[i];
  		sum+=w[i];
  	}

  	int enmin=INF;
  	int cl=0;
  	for(int pl=0;pl<=n;pl++){
  		//cout<<cl<<" "<<sum-cl<<endl;
  		int custo=cl*l;
  		custo+=(sum-cl)*r;
  		if(pl>n-pl)custo+=(pl-(n-pl)-1)*ql;
  		if(pl<n-pl)custo+=((n-pl)-pl-1)*qr;
  		//cout<<custo<<endl;
  		enmin=min(enmin,custo);
  		cl+=w[pl];
  	}

  	cout<<enmin<<endl;

}