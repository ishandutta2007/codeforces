#include <set>
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
void read(int &a){
	a=0;
	char c=getchar();
	while(c<'0'||c>'9'){
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		a=(a<<1)+(a<<3)+(c^48);
		c=getchar();
	}
}
int mn(int a,int b){
	return a<b?a:b;
}
const int Maxn=200000;
typedef long long ll;
struct Node{
	int a,t;
	friend bool operator <(Node p,Node q){
		if(p.a==q.a){
			return p.t>q.t;
		}
		return p.a<q.a;
	}
}a[Maxn+5];
int n;
multiset<int> val;
int main(){
	read(n);
	for(int i=1;i<=n;i++){
		read(a[i].a);
	}
	for(int i=1;i<=n;i++){
		read(a[i].t);
	}
	sort(a+1,a+1+n);
	int num=0;
	ll ans=0;
	ll sum=0;
	multiset<int>::iterator it,del_it;
	for(int i=1,j;i<=n;i=j+1){
		j=i;
		while(j<=n&&a[j].a==a[i].a){
			j++;
		}
		j--;
		if(num>0){
			it=val.end();
			it--;
			for(int k=1;k<=mn(num,a[i].a-a[i-1].a-1);k++,it--,val.erase(del_it)){
				ans+=1ll*k*(*it);
				sum-=(*it);
				del_it=it;
			}
		}
		num-=mn(num,a[i].a-a[i-1].a-1);
		ans+=1ll*(a[i].a-a[i-1].a)*sum;
		for(int k=i;k<=j;k++){
			val.insert(a[k].t);
			sum+=a[k].t;
			num++;
		}
		it=val.end();
		it--;
		num--;
		sum-=(*it);
		val.erase(it);
	}
	if(num>0){
		it=val.end();
		it--;
		for(int k=1;k<=num;k++,it--,val.erase(del_it)){
			ans+=1ll*k*(*it);
			sum-=(*it);
			del_it=it;
		}
	}
	cout<<ans<<endl;
	return 0;
}