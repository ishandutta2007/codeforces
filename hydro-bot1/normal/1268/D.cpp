// Hydro submission #62e4d1f1a2df73ab2e5e7165@1659163122166
#include<bits/stdc++.h>
using namespace std;
#define maxn 2009
const long long mod=998244353;
int n,rd[maxn],d[maxn];
bool dis[maxn][maxn];
int mis=100,cnt=0;
long long ans=0;
void rev(int i){
	for(int j=1;j<=n;j++){
		if(i!=j){
			if(dis[i][j])rd[j]--;
			dis[i][j]^=1;
			if(dis[i][j])rd[j]++;
			if(dis[j][i])rd[i]--;
			dis[j][i]^=1;
			if(dis[j][i])rd[i]++;
		}
	}
	return ;
}
bool check(){
	for(int j=1;j<=n;j++)d[j]=rd[j];
	sort(d+1,d+n+1);
	int sut=0;
	bool flag=true;
//	if(cnt==2)cout<<"QAQ"<<endl;
	for(int j=1;j<n;j++){
		sut+=d[j];
//		if(cnt==2)cout<<sut<<" "<<(j*(j-1)/2)<<endl;
		if(sut==j*(j-1)/2)flag=false;
	}
	return flag;
}
void work1(){
	int sum=0;
	if(check()){
		cout<<0<<" "<<1<<endl;
		return ;
	}
	for(int i=1;i<=n;i++){
		rev(i);
		sum+=check();
		rev(i);
	}
	if(sum==0){
		cout<<-1<<endl;
	}
	else{
		cout<<1<<" "<<sum<<endl;	
	}
	return ;
}
void dfs(int now){
	if(now==n+1){
		if(check()){
			if(mis>cnt)mis=cnt,ans=0;
			if(mis==cnt)ans++;
		}
		return ;
	}
	dfs(now+1);
	cnt++;
	rev(now);
	dfs(now+1);
	cnt--;
	rev(now);
	return ;
}
void work2(){
	dfs(1);
	if(!ans)cout<<-1<<endl;
	else{
		for(int i=1;i<=mis;i++)ans=ans*i%mod;
		cout<<mis<<" "<<ans<<endl;
	}
	return ;
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		char s[maxn];
		cin>>s+1;
		for(int j=1;j<=n;j++){
			dis[i][j]=s[j]-'0';
			if(dis[i][j])rd[j]++;
		}
	}
	if(n>=7){
		work1();
	}
	else{
		work2();
	}
	return 0;
}