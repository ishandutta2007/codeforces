#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,a,b,x,y,NMSL;

int ask(int x,int y){
	NMSL++;
	if(NMSL>((n*2+2)/3)){
		exit(1);
	}
	cout<<"? "<<x<<' '<<y<<endl;
	cin>>x;return x;
}

int fuck(int l,int r){
	//printf("a%d %d\n",l,r);
	if(l==r)return r;
	int a,b,c,d,k=(r-l+1)/4,sb,sb2;
	a=fuck(l,l+k-1);
	b=fuck(l+k,l+k+k-1);
	c=fuck(l+k+k,l+k+k+k-1);
	d=fuck(l+k+k+k,l+k+k+k+k-1);
	sb=ask(a,c);
	if(sb==2){
		sb2=ask(b,c);
		if(sb2==1)return b;
		else if(sb2==0)return d;
		else return c;
	}
	else if(sb==1){
		sb2=ask(a,d);
		if(sb2==1)return a;
		else if(sb2==0)return b;
		else return d;
	}
	else{
		sb2=ask(b,d);
		if(sb2==1)return b;
		else if(sb2==2)return d;
		else exit(3);
	}
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>t;
	while(t--){
		NMSL=0;
		cin>>n;
		if(n&1){
			n=(1<<n);
			x=fuck(1,n/2);y=fuck(n/2+1,n);
			k=ask(x,y);
			cout<<"! "<<((k==1)?x:y)<<endl;
		}
		else{
			n=(1<<n);
			k=fuck(1,n);
			cout<<"! "<<k<<endl;
		}
	}
}