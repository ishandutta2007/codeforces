#include<iostream>
#include<algorithm>
using namespace std;
long long i,n,r,avg,ans;
struct IPT{
	long long a,b;
} ipt[100005];
struct IPT_srt{
	bool operator() (IPT q, IPT w){
		if(q.b<w.b) {return true;}
		return false;
	}
};
int main(){
	cin>>n>>r>>avg;
	avg*=n;
	for(i=0;i<n;i++){
		cin>>ipt[i].a>>ipt[i].b;
		avg-=ipt[i].a;
		ipt[i].a=r-ipt[i].a;
	}
	sort(ipt,ipt+n,IPT_srt());
	for(i=0;i<n;i++){
		if(avg<=ipt[i].a){
			ans+=ipt[i].b*avg;
			avg=0;
			break;
		}
		else {
			ans+=ipt[i].b*ipt[i].a;
			avg-=ipt[i].a;
		}
	}
	if(ans<0){ans=0;}
	cout<<ans;
}