#include <bits/stdc++.h>
 
using namespace std;
#define pb push_back
#define mp make_pair
#define f first
#define s second
typedef long long ll;
typedef pair<int,int>pii;
 
#define MAXN 11234567890123
#define INF INT_MAX/2
#define MOD 1000000007

void ask(int a){
	cout<<"? "<<a<<endl;
	return;
}

void ans(int a){
	cout<<"! "<<a<<endl;
	exit(0);
}

int num,nxt;

int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(0);

	int n, start, x;
	cin>>n>>start>>x;

	int num,nxt;
	ask(start);
	cin>>num>>nxt;

	if(num>=x)ans(num);

	int mame=num;
	int stin=nxt;

	for(int i=0;i<1000;i++){
		long long chute=((78LL*rand()+rand())%n)+1;
		ask(chute);
		cin>>num>>nxt;
		if(num<x && num>mame){
			mame=num;
			stin=chute;
		}
	}

	if(stin==-1)ans(-1);

	for(int i=0;i<999;i++){
		ask(stin);
		cin>>num>>nxt;
		if(num>=x)ans(num);
		if(nxt==-1)ans(-1);
		stin=nxt;
	}

	return 0;
}