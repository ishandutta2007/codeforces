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

int sq(int a){return a*a;}

int dis(tuple<int,int,int> &a,tuple<int,int,int> &b){
	return sq(get<0>(b)-get<0>(a))+sq(get<1>(b)-get<1>(a))+sq(get<2>(b)-get<2>(a));
}
    
vector<tuple<int,int,int>> lista(tuple<int,int,int> x){
	vector<tuple<int,int,int>> resp;
	resp.pb(tie(get<0>(x),get<1>(x),get<2>(x)));
	resp.pb(tie(get<0>(x),get<2>(x),get<1>(x)));
	resp.pb(tie(get<1>(x),get<0>(x),get<2>(x)));
	resp.pb(tie(get<1>(x),get<2>(x),get<0>(x)));
	resp.pb(tie(get<2>(x),get<0>(x),get<1>(x)));
	resp.pb(tie(get<2>(x),get<1>(x),get<0>(x)));
	return resp;
}

int di[100];

bool deu(vector<tuple<int,int,int>> &p){
	int mini=-1;
	int index=0;
	for(int i=0;i<8;i++){
		for(int j=i+1;j<8;j++){
			int x=dis(p[i],p[j]);
			di[index]=x;
			index++;
			if(mini==-1 || x<mini)mini=x;
		}
	}
	int a=0,b=0,c=0;
	for(int i=0;i<index;i++){
		if(di[i]==mini)a++;
		if(di[i]==2*mini)b++;
		if(di[i]==3*mini)c++;
	}
	return a==12&&b==12&&c==4;
}

int32_t main(){

	 vector<tuple<int,int,int>> inp;

	 for(int i=0;i<8;i++){
	 	int a,b,c;
	 	cin>>a>>b>>c;
	 	inp.pb(tie(a,b,c));
	 }

	auto x0 = inp[0]; 
	for(auto x1:lista(inp[1]))
 		for(auto x2:lista(inp[2]))
 			for(auto x3:lista(inp[3]))
 				for(auto x4:lista(inp[4]))
 					for(auto x5:lista(inp[5]))
 						for(auto x6:lista(inp[6]))
 							for(auto x7:lista(inp[7])){
 								vector<tuple<int,int,int>> par={x0,x1,x2,x3,x4,x5,x6,x7};
 								if(deu(par)){
 									cout<<"YES"<<endl;
 									for(auto x:par){
 										cout<<(get<0>(x))<<" "<<(get<1>(x))<<" "<<(get<2>(x))<<endl;
 									}
 									return 0;
 								}
 							}

	cout<<"NO"<<endl;

    return 0;
}