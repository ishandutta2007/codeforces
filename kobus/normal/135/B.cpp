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

int sq(int a){return a*a;}

int dis(pii a,pii b){
	return sq(a.f-b.f)+sq(a.s-b.s);
}

//[]
bool ise(vector<int> &v,int a,int b){
	for(int i=a+1;i<=b;i++){
		if(v[i]!=v[i-1])return 0;
	}
	return 1;
}

bool isRec(vector<pii> &v){
	vector<int> di;
	for(int i=0;i<v.size();i++){
		for(int j=i+1;j<v.size();j++){
			di.pb(dis(v[i],v[j]));
		}
	}
	sort(di.begin(),di.end());

	int dis1=di[0];
	int dis2=di[2];
	int dis3=di[4];
	for(int i=0;i<v.size();i++){
		bool tem1=0,tem2=0,tem3=0;
		for(int j=0;j<v.size();j++){
			if(dis(v[i],v[j])==dis1)tem1=1;
			if(dis(v[i],v[j])==dis2)tem2=1;
			if(dis(v[i],v[j])==dis3)tem3=1;
		}
		if(!tem1||!tem2||!tem3)return 0;
	}
	return ise(di,0,1)&&ise(di,2,3)&&ise(di,4,5);
}

bool isSq(vector<pii> v){
	vector<int> di;
	for(int i=0;i<v.size();i++){
		for(int j=i+1;j<v.size();j++){
			di.pb(dis(v[i],v[j]));
		}
	}
	sort(di.begin(),di.end());

	//cout<<di.size()<<endl;
	return ise(di,0,3)&&ise(di,4,5);
}



int32_t main(){

	vector<pii> v(8);
	for(int i=0;i<8;i++)cin>>v[i].f>>v[i].s;
	for(int a0=0;a0<8;a0++){
		for(int a1=a0+1;a1<8;a1++){
			for(int a2=a1+1;a2<8;a2++){
				for(int a3=a2+1;a3<8;a3++){
					if(!isSq({v[a0],v[a1],v[a2],v[a3]}))continue;
					vector<pii> rest;
					for(int i=0;i<8;i++){
						if(i!=a0&&i!=a1&&i!=a2&&i!=a3)
							rest.pb(v[i]);
					}
					if(isRec(rest)){
						cout<<"YES"<<endl;
						cout<<a0+1<<" "<<a1+1<<" "<<a2+1<<" "<<a3+1<<endl;
						for(int i=0;i<8;i++){
							if(i!=a0&&i!=a1&&i!=a2&&i!=a3)
								cout<<i+1<<" ";
						}
						cout<<endl;
						return 0;
					}
				}
			}
		}
	}
	cout<<"NO"<<endl;

    return 0;
}