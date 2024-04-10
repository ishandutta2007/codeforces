#include<bits/stdc++.h>
#define ll long long
using namespace std;
typedef pair<int,int> pii;
int read(){
	int x=0,b=1;char c;do c=getchar();while((c>'9'||c<'0')&&c!='-');
	if(c=='-')b=0,c='0';do x=x*10+c-'0',c=getchar();while(c>='0'&&c<='9');return b?x:-x;
}
int i,j,k,n,m,T,aa,ab,ba,bb;
int main(){
	int x1,y1,x2,y2;
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	cout<<"? "<<1<<' '<<1<<endl;
	cin>>aa;
	cout<<"? "<<1<<' '<<1000000000<<endl;
	cin>>ab;
	cout<<"? "<<1000000000<<' '<<1<<endl;
	cin>>ba;
	cout<<"? "<<1000000000<<' '<<1000000000<<endl;
	cin>>bb;
	if(aa>ab){
		int to=aa-ab,Mid=(1+(1000000000+to))/2;
		cout<<"? "<<1<<' '<<Mid<<endl;
		int w;
		cin>>w;
		y1=1+(aa-w);
		y2=1000000000-(ab-w);
	}else{
		int to=ab-aa,Mid=(1+(1000000000-to))/2;
		cout<<"? "<<1<<' '<<Mid<<endl;
		int w;
		cin>>w;
		y1=1+(aa-w);
		y2=1000000000-(ab-w);
	}
	if(aa>ba){
		int to=aa-ba,Mid=(1+(1000000000+to))/2;
		cout<<"? "<<Mid<<' '<<1<<endl;
		int w;
		cin>>w;
		x1=1+(aa-w);
		x2=1000000000-(ba-w);
	}else{
		int to=ba-aa,Mid=(1+(1000000000-to))/2;
		cout<<"? "<<Mid<<' '<<1<<endl;
		int w;
		cin>>w;
		x1=1+(aa-w);
		x2=1000000000-(ba-w);
	}
	if(x1>x2)swap(x1,x2);
	if(y1>y2)swap(y1,y2);
	cout<<"! "<<x1<<' '<<y1<<' '<<x2<<' '<<y2<<endl;
}
/*
3
999999996
999999998
1999999991
1
2
*/