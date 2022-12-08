#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define INF INT_MAX/2
#define int long long
#define mp make_pair
#define f first
#define s second

int n;
string s;
int a,b;
pair<int,char> memo[40][40][40][80];

//a++, b--
pair<int,char> pd(int i,int m1,int m2,int sla){
	if(i==n){
		if(m1==0 && m2==0)return mp(0,'.');
		else return mp(INF,'.');
	}
	pair<int,char> &resp=memo[i][m1][m2][sla];
	if(resp.f==-INF){
		resp=pd(i+1,(10*m1+s[i]-'0')%a,m2,sla+1);
		resp.f++;resp.s='R';
		pair<int,char> v2=pd(i+1,m1,(10*m2+s[i]-'0')%b,sla-1);
		v2.f--;v2.s='B';
		if(abs(v2.f+sla-40)<abs(resp.f+sla-40))resp=v2;
	}
	return resp;

}


int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t;
	cin>>t;
	while(t--){
		cin>>n>>a>>b>>s;
		for(int i=0;i<n;i++){
			for(int j=0;j<a;j++){
				for(int k=0;k<b;k++){
					for(int kk=0;kk<80;kk++)
					memo[i][j][k][kk]=mp(-INF,'.');
				}
			}
		}
		pair<int,char> num=pd(0,0,0,40);
		//cout<<num.f<<endl;
		if(abs(num.f)>=n){
			cout<<-1<<endl;
		}
		else{
			string ans="";
			int m1=0,m2=0,sla=40;
			for(int i=0;i<n;i++){
				pair<int,char> aaa=pd(i,m1,m2,sla);
				ans.pb(aaa.s);
				if(aaa.s=='R'){
					m1=(10*m1+s[i]-'0')%a;
					sla++;
				}
				else{
					m2=(10*m2+s[i]-'0')%b;
					sla--;
				}
			}
			cout<<ans<<endl;
		}
	}
}