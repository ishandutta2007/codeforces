#include <algorithm> 
#include <cstdio>
#include <map>

std::map<long long,int>map;
struct point{
	long long p,t;
}num[400001];
long long a,b,t,ans;
int top,n;
bool cmp(point a,point b){return a.p<b.p||(a.p==b.p&&a.t>b.t);}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%lld%lld%lld",&a,&b,&t),num[++top]=(point){a,t},num[++top]=(point){b-t,-t};
	std::sort(num+1,num+top+1,cmp);
	long long st=0;
	for(int i=1;i<=top;i++){
		if(num[i].t>0)++map[num[i].t];
		else if(!--map[-num[i].t])map.erase(-num[i].t);
		if(!map.empty()){//&&num[i].p!=num[i+1].p){
			long long t=map.begin()->first;
			if(num[i].t>0)st=std::min(st,num[i].p+t);
			st=std::max(st,num[i].p);
			if(num[i+1].p>=st){
				long long x=((num[i+1].p-st)/t)+1;
				ans+=x;
				st+=x*t;
			}
		}
	}
	printf("%lld\n",ans);
}