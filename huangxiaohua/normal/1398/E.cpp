#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
//
int i,j,k,n,m,t,it,l,r,md,res,k1,num;
ll f1[200500],f2[200500],id[200500],ans;
map<int,int> mp,mp2;
set<int> s;
multiset<int> sb;
vector<pair<int,int> >v;

void add(ll *f,int x,int y){for(;x<=n;x+=(-x&x)){f[x]+=y;}}
ll get(ll *f,int x,ll y=0){for(;x;x-=(-x&x)){y+=f[x];}return y;}

int main(){
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d%d",&j,&k);
		v.push_back({j,k});
		if(k>0){s.insert(-k);}
	}
	for(auto i:s){mp[-i]=++it;id[it]=-i;}
	for(auto [i,j]:v){
		if(j<0){
			j=-j;if(i){sb.erase(sb.find(j));num--;}
			add(f1,mp[j],-1);
			add(f2,mp[j],-j);mp2[j]--;
		}
		else{
			if(i){sb.insert(j);num++;}
			add(f1,mp[j],1);
			add(f2,mp[j],j);mp2[j]++;
		}
		l=1;r=n;res=n;ans=get(f2,n);
		if(sb.empty()){
			printf("%lld\n",ans);continue;
		}
		while(l<=r){
			md=(l+r)>>1;
			if(get(f1,md)>=num){res=min(res,md);r=md-1;}
			else{l=md+1;}
		}
		k=get(f1,res);k1=*sb.begin();
		if(k1>=id[res]){
			if(k>num){
				printf("%lld\n",ans+get(f2,res)-id[res]*(get(f1,res)-num-1)-k1);
			}
			else{
				l=1;r=n;res=1145141919;
				while(l<=r){
					md=(l+r)>>1;
					if(get(f1,md)>=num+1){res=min(res,md);r=md-1;}
					else{l=md+1;}
				}
				if(res==1145141919){printf("%lld\n",ans+ans-k1);continue;}
				printf("%lld\n",ans+get(f2,res)-id[res]*(get(f1,res)-num-1)-k1);
			}
		}
		else{
			printf("%lld\n",ans+get(f2,res)-id[res]*(get(f1,res)-num));
		}
	}
}