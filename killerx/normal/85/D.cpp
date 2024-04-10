#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1<<17;
struct SegT{
	ll sum[N<<1][5];
	int num[N<<1];
	SegT(){
		memset(sum,0,sizeof(sum));
		memset(num,0,sizeof(num));
	}
	void upd(int x,int v){
		x+=N;
		sum[x][0]+=v;
		num[x]+=v>0?1:-1;
		while(x>>=1){
			num[x]=num[x<<1]+num[x<<1|1];
			for(int i=0;i<5;++i){
				sum[x][i]=sum[x<<1][i]+sum[x<<1|1][(i-(num[x<<1]%5)+5)%5];
			}
		}
	}
	ll qry(){return sum[1][2];}
}segt;
vector<int>v;
vector<pair<int,int> >q;
int main(){
	int n;scanf("%d",&n);
	for(int i=0;i<n;++i){
		char c[5];scanf("%s",c);
		if(c[0]=='a'){
			int x;scanf("%d",&x);
			v.push_back(x);
			q.push_back(make_pair(0,x));
		}else if(c[0]=='d'){
			int x;scanf("%d",&x);
			q.push_back(make_pair(1,x));
		}else{
			q.push_back(make_pair(2,0));
		}
	}
	sort(v.begin(),v.end());
	v.erase(unique(v.begin(),v.end()),v.end());
	for(int i=0;i<n;++i){
		int tp=q[i].first;
		if(tp==0){
			segt.upd(lower_bound(v.begin(),v.end(),q[i].second)-v.begin(),q[i].second);
		}else if(tp==1){
			segt.upd(lower_bound(v.begin(),v.end(),q[i].second)-v.begin(),-q[i].second);
		}else{
			printf("%lld\n",segt.qry());
		}
	}
	return 0;
}