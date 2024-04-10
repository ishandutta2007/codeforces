// Hydro submission #616cb4a760f0aa1f3263e741@1634545340129
#include<iostream>
#include<map>
using namespace std;
int f[5000005];
int zys(int a){
//	cout<<"|	a="<<a<<endl;
	if(f[a]==a){
		return a;
	}
	f[a]=zys(f[a]);
	return f[a];
}
int prime[2000005],a[2000005],zyl[1000005];
bool mark[2000005];
map<int,bool> xyq[2000005];
//#define P for(int wba=0;wba<(n<<1);wba++){cout<<f0[wba]<<" ";}cout<<endl;
int main(){
	int n,q,i,j,k,A,B,sum=0,fa,fb,ykb,tot=0;
	cin>>n>>q;
	for(i=0;i<=2000000;i++){
		f[i]=i;
	}
	prime[0]=2;
	for(i=2;i<=1234567;i++){
		if(!mark[i]){
			prime[sum++]=i;
		}
		for(j=0;j<sum&&i*prime[j]<=1234567;j++){
			mark[i*prime[j]]=1;
			if(i%prime[j]==0){
				break;
			}
		}
	}
//	cout<<prime[3]<<endl;
	for(i=0;i<n;i++){
//		if(i%5000==0){
//			cout<<i<<endl;
//		}
		scanf("%d",a+i);
		ykb=a[i];
		for(j=0;prime[j]*prime[j]<=ykb;j++){
			if(!(a[i]%prime[j])){
//				cout<<"[0]"<<i<<""<<n+prime[j]<<endl;
				f[zys(i)]=f[zys(n+prime[j])];
				while(!(ykb%prime[j])){
					ykb/=prime[j];
				}
			}
		}
		if(ykb>1){
//			cout<<"[0]."<<i<<""<<n+ykb<<endl;
			f[zys(i)]=f[zys(n+ykb)];
		}
	}
//	cout<<"..."<<zys(1)<<" "<<zys(10)<<endl;
	for(i=0;i<n;i++){
		ykb=a[i]+1;
		tot=0;
//		cout<<"i="<<i<<endl;
		for(j=0;prime[j]*prime[j]<=ykb;j++){
			if(!((a[i]+1)%prime[j])){
//				cout<<"[1]"<<i<<""<<n+prime[j]<<endl;
				xyq[zys(i)][zys(n+prime[j])]=1;
				zyl[tot++]=zys(n+prime[j]);
				ykb/=prime[j];
				while(!(ykb%prime[j])){
					ykb/=prime[j];
				}
			}
		}
//		cout<<"ykb="<<ykb<<endl;
		if(ykb>1){
//			cout<<"[1]."<<i<<""<<n+ykb<<endl;
			xyq[zys(i)][zys(n+ykb)]=1;
			zyl[tot++]=zys(n+ykb);
		}
//		for(j=0;j<tot;j++){
//			cout<<zyl[j]<<" ";
//		}
//		cout<<endl;
		for(j=0;j<tot;j++){
			for(k=j+1;k<tot;k++){
				xyq[zyl[j]][zyl[k]]=1;
			}
		}
	}
	for(i=0;i<q;i++){
		scanf("%d %d",&A,&B);
		fa=zys(A-1);
		fb=zys(B-1);
//		cout<<""<<fa<<","<<fb<<endl; 
		if(a[A-1]==a[B-1]||fa==fb){
			cout<<0<<endl;
		}else if(xyq[fa][fb]||xyq[fb][fa]){
			cout<<1<<endl;
		}else{
			cout<<2<<endl;
		}
	}
	return 0;
}
/*
2 1
5 77
1 2
ans:2

3 3
7 11 13
1 2
1 3
2 3
ans:2 1 2

3 1
3 7 41
1 2
ans:1

#include<iostream>
using namespace std;
bool mark[2000005];
int prime[2000005];
int main(){
	freopen("0.in","w",stdout);
	int n,q,i,j,A,B,sum=0,fa,fb,ykb;
	n=1000;
	q=n*(n-1)>>1;
	prime[0]=2;
	for(i=2;i<=1234567;i++){
		if(!mark[i]){
			prime[sum++]=i;
		}
		for(j=0;j<sum&&i*prime[j]<=1234567;j++){
			mark[i*prime[j]]=1;
			if(i%prime[j]==0){
				break;
			}
		}
	}
//	cout<<prime[3];
	cout<<n<<" "<<q<<endl;
	for(i=0;i<n;i++){
		cout<<prime[i]<<" ";
	}
	cout<<endl;
	for(i=1;i<=n;i++){
		for(j=1;j<i;j++){
			cout<<j<<" "<<i<<endl;
		}
	}
	return 0;
}
*/