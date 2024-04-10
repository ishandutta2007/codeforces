// Hydro submission #62fda38ae42c71bad9eeb9c9@1660789643238
#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
using namespace std;

const char ze='0';
inline int fr(){
	int res=0;char tp=getchar();
	while(!isdigit(tp))tp=getchar();
	while(isdigit(tp)){
		res=(res<<3)+(res<<1)+tp-ze;
		tp=getchar();
	}
	return res;
}

vector<int>prime;
bitset<100010>isp;
void pre(){
	//isp.resize((int)1e5+7);
	for(int i=2;i<=(int)1e5;i++){
		if(!isp[i])prime.push_back(i);
		for(int tmp:prime){
			if((ll)tmp*i>(ll)1e5)break;
			isp[tmp*i]=1;
			if(i%tmp==0)break;
		}
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	
	pre();
	
	ll p,q;
	
	int T;
	cin>>T;
	while(T--){
		cin>>p>>q;
		if(p%q)cout<<p<<endl;
		else{
			ll ans=0;
			for(int tmp:prime){
				if(q%tmp==0){
					ll ps=1;
					while(q%tmp==0){
						ps*=tmp;
						q/=tmp;
					}
					ll pt=p;
					while(pt%tmp==0)pt/=tmp;
					ans=max(ans,pt*ps/tmp);
				}
			}
			if(q!=1){
				ll pt=p;
				while(pt%q==0)pt/=q;
				ans=max(ans,pt);
			}
			cout<<ans<<endl;
		}
	}

	return 0;
}