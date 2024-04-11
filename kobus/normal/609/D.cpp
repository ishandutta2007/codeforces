#include <bits/stdc++.h>
 
using namespace std;
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define int long long
typedef long long ll;
typedef pair<int,int>pii;
#define MAXN 1123456
#define INF INT_MAX/2
#define MOD 1000000

int n,m,k,s;

int a[212345];
int b[212345];
int gt[212345];
int gp[212345];
pii he[2123456];

bool test(int num,bool print){
	int mindol=INF;
	int di,pi;
	int din=s;
	for(int i=0;i<num;i++){
		if(a[i]<mindol){
			mindol=a[i];
			di=i;
		}
	}
	int minpou=INF;
	for(int i=0;i<num;i++){
		if(b[i]<minpou){
			minpou=b[i];
			pi=i;
		}
	}
	for(int i=0;i<m;i++){
		if(gt[i]==1){
			he[i].f=mindol*gp[i];
		}
		else{
			he[i].f=minpou*gp[i];
		}
		he[i].s=i;
	}
	sort(he,he+m);
	for(int i=0;i<k;i++){
		din-=he[i].f;
		if(print && din>=0){
			cout<<1+he[i].s<<" ";
			if(gt[he[i].s]==1){
				cout<<di+1<<endl;
			}
			else cout<<pi+1<<endl;
		}
	}
	return din>=0;
}


int bsearch(){
	int com=0,fim=n,meio,best=-1;
	while(com<=fim){
		meio=(com+fim)/2;
		if(test(meio,0)){
			best=meio;
			fim=meio-1;
		}
		else com=meio+1;
	}
	return best;
}


int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin>>n>>m>>k>>s;
	for(int i=0;i<n;i++)cin>>a[i];
	for(int i=0;i<n;i++)cin>>b[i];
	for(int i=0;i<m;i++)cin>>gt[i]>>gp[i];

	int resp=bsearch();
	cout<<resp<<endl;
	if(resp!=-1)test(resp,1);

	return 0;
}