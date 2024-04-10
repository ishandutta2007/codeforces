#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,t1,t2,a1,a2,b1,b2,sa,sb,t3,t4;
int r1,r2,r3,r4;
int main(){
	//srand(time(0));
	
	ios::sync_with_stdio(0);
	cin>>t;
	while(t--){
		cin>>n>>m;
		//n=10;m=16;
		//r1=rand()%n+1;r2=rand()%m+1;r3=rand()%n+1;r4=rand()%m+1;
		//if(r1>r3)swap(r1,r3);
		//if(r2>r4)swap(r2,r4);
		cout<<"SCAN 1 1"<<endl;
		//t1=abs(r1-1)+abs(r2-1)+abs(r3-1)+abs(r4-1);
		cin>>t1;
		
		cout<<"SCAN 1 "<<m<<endl;
		cin>>t2;
		//t2=abs(r1-1)+abs(r2-m)+abs(r3-1)+abs(r4-m);
		
		sa=(2-m-m+4+t1+t2)/2;
		sb=(4+t1+m+m-2-t2)/2;
		
		cout<<"SCAN 1 "<<sb/2<<endl;
		cin>>t3;
		//t3=abs(r1-1)+abs(r2-sb/2)+abs(r3-1)+abs(r4-sb/2);
		
		cout<<"SCAN "<<sa/2<<" 1"<<endl;
		cin>>t4;
		//t4=abs(r1-sa/2)+abs(r2-1)+abs(r3-sa/2)+abs(r4-1);
		
		a2=(t4-(sb-2)+sa)/2;
		a1=sa-a2;
		
		b2=(t3-(sa-2)+sb)/2;
		b1=sb-b2;
		
		//printf("a%d %d %d %d %d %d\n",a1,b1,a2,b2,sa,sb);
		//printf("b%d %d %d %d\n",r1,r2,r3,r4);
		
		cout<<"DIG "<<a1<<' '<<b1<<endl;
		cin>>k;
		if(k==1){
			cout<<"DIG "<<a2<<' '<<b2<<endl;cin>>k;
		}
		else{
			cout<<"DIG "<<a1<<' '<<b2<<endl;cin>>k;
			cout<<"DIG "<<a2<<' '<<b1<<endl;cin>>k;
		}
	}
}