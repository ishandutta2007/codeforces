#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,x,y,t1,t2,t3,f[2005],num;

int ask(int x){
	int res=1,cur=x,i;
	for(i=1;i<=n;i++){
		if(f[i]>x)return 0;
		if(cur==x){
			cur-=f[i];
		}
		else{
			if(cur<f[i]+1){
				res++;cur=x-f[i];
			}
			else{
				cur-=f[i]+1;
			}
		}
	}
	return res;
}

int main(){
	ios::sync_with_stdio(0);
	t=1;
	while(t--){
		num=0;
		/*n=rand()%5+1;
		cout<<n<<endl;
		for(i=1;i<=n;i++){
			f[i]=rand()%100+1;
			cout<<f[i]<<' ';
		}
		cout<<endl;*/
		
		cin>>n;
		
		int res=1e9;
		
		/*for(i=1;i<=n*2000;i++){
			t3=ask(i);
			if(!t3)continue;
			res=min(res,t3*i);
		}*/
		
		int l=1,r=n*2001,md,ans=1e9;
		while(l<=r){
			md=(l+r)/2;
			cout<<"? "<<md<<endl;
			//k=ask(md);
			cin>>k;
			
			num++;if(num>n+30)exit(1);
			
			//cout<<k<<endl;
			if(k==1){
				ans=min(ans,md);
				r=md-1;
			}
			else{
				l=md+1;
			}
		}
		y=ans;
		x=ans-(n-1);
		
		for(i=2;i<=n;i++){
			k=(y-1)/i;
			if((k*i)<x)continue;
			
			cout<<"? "<<k<<endl;
			//t1=ask(k);cout<<t1<<endl;
			cin>>t1;
			num++;if(num>n+30)exit(1);
			
			if(!t1)break;
			if(t1>i)continue;
			
			y=i*k;
			while(1){
				k--;
				if((k*i)<x)break;
				cout<<"? "<<k<<endl;
				
				//t1=ask(k);cout<<t1<<endl;
				cin>>t1;
				num++;if(num>n+30)exit(1);
				
				if(!t1)goto aaa;
				if(t1>i)break;
				y=i*k;
			}
			
		}
		
		aaa:;
		cout<<"! "<<y<<endl;
		//cout<<"!! "<<res<<endl;
		//if(y!=res)return 1;
	}
}