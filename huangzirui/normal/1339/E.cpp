#include<bits/stdc++.h>
#define ll long long
using namespace std;
inline int read(){
	char c=getchar();int x=0,f=1;
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
    return x*f;
}
int i,j,k,m,T;
ll n;
ll getans(ll x){
	ll s=1,T=0;
	while(s*4<=x)s*=4,T++;
	ll w=x-s+1,ans=0,to=w%s,id=x/3,t=(s-1)/3;
//	cout<<"x="<<x<<' '<<s<<endl;
	if(x%3==1){
		ans=s;
		return ans+id-t;
	}
	if(x%3==2){
		ans=2*s;
		ll D=id-t,tans=0;
//		cout<<"D="<<D<<endl;
		vector<int>V;
		while(T){
			T--;
			tans*=4;
			if(D/(s/4)==0)tans+=0,V.push_back(0),V.push_back(0);
			if(D/(s/4)==1)tans+=3,V.push_back(1),V.push_back(0);
			if(D/(s/4)==2)tans+=1,V.push_back(1),V.push_back(1);
			if(D/(s/4)==3)tans+=2,V.push_back(0),V.push_back(1);
			D%=(s/4);s/=4;
		}tans=0;
//		reverse(V.begin(),V.end());
		for(int i=0;i<V.size();i++)tans=tans*2+V[i];
		return ans+tans;
	}
	if(x%3==0){
		ans=3*s;
		ll D=id-t-1,tans=0;
//		cout<<"D="<<D<<' '<<ans<<endl;
		vector<int>V;
		while(T){
			T--;
			tans*=4;
			if(D/(s/4)==0)V.push_back(0),V.push_back(0);
			if(D/(s/4)==1)V.push_back(1),V.push_back(1);
			if(D/(s/4)==2)V.push_back(0),V.push_back(1);
			if(D/(s/4)==3)V.push_back(1),V.push_back(0);
			D%=(s/4);s/=4;
		}tans=0;
//		reverse(V.begin(),V.end());
		for(int i=0;i<V.size();i++)tans=tans*2+V[i];
		return ans+tans;
	}
}
int main(){
	cin>>T;
	while(T--){
		cin>>n;
		printf("%lld\n",getans(n));
	}
	return 0;
}