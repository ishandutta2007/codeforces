#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=3e5+5;
ll totlen=1;int m;
struct data{
	ll id,b,s;
	data(ll id=0):id(id),b(0),s(0){}
}t[N];
int top=1;

ll calcsum(int i){
	ll b=i==top?t[i].b:t[i].b+t[i+1].b;
	ll s=i==top?t[i].s:t[i].s+t[i+1].s;
	return b+(ll)(t[i].id-1ll)*s;
}

int main()
{
	cin>>totlen>>m;
	t[1]=data(1);
	while(m--){
		int opt=0;scanf("%d",&opt);
		if(opt==1){
			ll sum;
			scanf("%lld",&sum);
			totlen+=sum;
			t[top=1]=data(1);
		}else if(opt==2){
			ll sum;
			scanf("%lld",&sum);
			while(top>1){
				ll T1=calcsum(top);
				ll T2=calcsum(top-1);
				ll sub1=totlen+1ll-t[top].id;
				ll sub2=totlen+1ll-t[top-1].id;
				if((long double)T1*sub2 >= (long double)T2*sub1){
					t[top-1].b+=t[top].b;
					t[top-1].s+=t[top].s;
					--top;
				}else break;
			}
			t[++top]=data(totlen+1);

			totlen+=sum;
			// cout<<"!"<<endl;
			// cout<<calcsum(top)<<endl;
		}else{
			ll b,s;
			scanf("%lld%lld",&b,&s);
			t[top].b+=b;
			t[top].s+=s;
		}
		while(top>1){
			ll T=calcsum(top),T2=calcsum(top-1);
			if(T>=T2){
				t[top-1].b+=t[top].b;
				t[top-1].s+=t[top].s;
				--top;
			}else break;
		}
//		cout<<calcsum(top-1)<<endl;
//		for(int i=1;i<=top;i++)cout<<t[i].id<<" , ";puts("");
		printf("%lld %lld\n",t[top].id,calcsum(top));
	}
}