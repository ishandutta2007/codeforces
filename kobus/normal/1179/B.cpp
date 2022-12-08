#include <bits/stdc++.h>
using namespace std;
#define INF 1'000'000'001
#define f first
#define s second
#define eps 1e-6
#define pb push_back
#define pii pair<int,int>
#define one 1
#define mp make_pair
#define ld long double
#define MAXN 2123456
#define mod 998244353 
#define int long long
#define ld long double
#define pi acos(-1)

int l,c;

int fw=1;
pii nxt(pii x){
	if(fw && x.s<c)return {x.f,x.s+1};
	else if(fw){
		fw=0;
		return {x.f+1,x.s};
	}
	if(x.s>1)return {x.f,x.s-1};
	else{
		fw=1;
		return {x.f+1,x.s};
	}
}

int bw=1;
pii prv(pii x){
	if(!bw && x.s<c)return {x.f,x.s+1};
	else if(!bw){
		bw=1;
		return {x.f-1,x.s};
	}
	if(x.s>1)return {x.f,x.s-1};
	else{
		bw=0;
		return {x.f-1,x.s};
	}
}

void pri(pii x){
	cout<<x.f<<" "<<x.s<<"\n";
}

int32_t main(){

	cin>>l>>c;
	pii ini={1,1};
	pii fim={l,c};

	bool at=1;
	for(int i=0;i<l*c;i++){
		if(at){
			pri(ini);
			ini=nxt(ini);
		}
		else{
			pri(fim);
			fim=prv(fim);
		}
		at=!at;
	}

    return 0;
}