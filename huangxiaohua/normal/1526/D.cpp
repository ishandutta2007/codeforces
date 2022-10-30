#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define get(sb) k=0;it=v[sb].size()-1;for(i=n;i>=1;i--){if(used[s[i]]){k++;}if(s[i]==sb){sum+=abs(v[sb][it]-(i+k));it--;}}used[sb]=1;
int i,j,k,n,m,t,res,a[5],it,mp[1050];
ll op[5],cur;
vector<int> v[10],sb;
char s[100500],ans[9]="XANTO";

void chk(int a1,int a2,int a3,int a4){
	int i,k,it=0,used[10]={0};
	ll sum=0;
	get(a1);get(a2);get(a3);get(a4);
	if(sum>cur){op[1]=a1;op[2]=a2;op[3]=a3;op[4]=a4;cur=sum;}
}

int main(){
	mp['A']=1;mp['N']=2;mp['T']=3;mp['O']=4;
	ios::sync_with_stdio(0);
	cin>>t;
	while(t--){
		sb.clear();
		for(i=1;i<=4;i++){
			a[i]=op[i]=0;
			v[i].clear();
			sb.push_back(i);
		}
		cur=-1;
		cin>>s+1;
		n=strlen(s+1);
		for(i=1;i<=n;i++){
			it=mp[s[i]];
			a[it]++;v[it].push_back(i);s[i]=it;
		}
		for(i=1;i<=24;i++){
			chk(sb[0],sb[1],sb[2],sb[3]);
			next_permutation(sb.begin(),sb.end());
		}
		for(i=1;i<=4;i++){
			for(j=1;j<=a[op[i]];j++){
				cout<<ans[op[i]];
			}
		}
		cout<<endl;
	}
}