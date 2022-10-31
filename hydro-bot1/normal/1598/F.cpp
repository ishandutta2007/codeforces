#include<iostream>
#include<cstring>
using namespace std;
int f[1234567],ans[1234567],zuo[1000005],zyl[1000005],n,zxcv[25][1000005]; //zuo:zyl:zxcv:ij 
string s[1000005];
int fyr(int S){
	if(f[S]!=-1){
		return f[S];
	}
//	cout<<"s="<<S<<endl;
	int i,j,sum=0,Max=-999999999,ykb=0;
	for(i=0;i<n;i++){
		if(S&(1<<i)){
			sum+=zuo[i];
		}
	}
	for(i=0;i<n;i++){
		if(S&(1<<i)){
//			ykb=sum-zuo[i];
//			qwer=0;
//			for(j=0;s[i][j]&&ykb>=0;j++){
//				if(s[i][j]=='('){
//					ykb++;
//				}else{
//					ykb--;
//				}
////				cout<<"ykb="<<ykb<<endl;
//				if(ykb==0){
//					qwer++;
//				}
//			}
//			cout<<"S="<<S<<","<<i<<","<<sum-zuo[i]<<""<<endl; 
			if(sum-zuo[i]+zyl[i]>=0){
//				cout<<"max:"<<fyr(S-(1<<i))<<"+"<<zxcv[i][sum-zuo[i]]<<endl;
				Max=max(Max,fyr(S-(1<<i))+zxcv[i][sum-zuo[i]]);
			}
			ans[S]=max(ans[S],fyr(S-(1<<i))+zxcv[i][sum-zuo[i]]);
		}
	}
	f[S]=Max;
	return Max;
}
int main(){
	memset(f,-1,sizeof(f));
	int i,j,Max=0,Min=0;
	cin>>n;
	for(i=0;i<n;i++){
		cin>>s[i];
		Min=0;
//		cout<<i<<" . ";
		for(j=0;s[i][j];j++){
			if(s[i][j]=='('){
				zuo[i]++;
			}else{
				zuo[i]--;
			}
			Min=min(Min,zuo[i]);
//			cout<<"zuo="<<zuo[i]<<",min="<<Min<<endl;
			if(zuo[i]==Min){
				zxcv[i][-Min]++;
			}
//			cout<<zuo[i]<<" ";
//			mark[i][zuo[i]+500000]++;
			zyl[i]=min(zyl[i],zuo[i]);
		}
//		cout<<endl;
	}
//	for(i=-10;i<=10;i++){
//		cout<<"	"<<i;
//	}
//	cout<<endl;
//	for(i=0;i<n;i++){
//		cout<<i<<"|";
//		for(j=0;j<10;j++){
//			cout<<zxcv[i][j]<<"	";
//		}
//		cout<<endl;
//	}
//	for(i=0;i<n;i++){
//		cout<<zyl[i]<<" ";
//	}
//	cout<<endl;
	f[0]=0;
	for(i=0;i<(1<<n);i++){
		fyr(i);
//		cout<<i<<" "<<f[i]<<" "<<ans[i]<<endl;
		Max=max(Max,ans[i]);
	}
	cout<<Max;
	return 0;
}
/*
2
()
()
ans:2

2
))())))((()
()((((((()))))))(()
ans:3

2
)()
)((
ans:0
*/