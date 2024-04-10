#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

unordered_map<string,bool> mp;
unordered_map<ll,bool> mp2;

int i,j,k,n,t,no;
string ans,sb,tmp;
ll cnm,cnm2;

void add(){
	ans[ans.size()-1]++;
	for(i=ans.size()-1;;i--){
		if(i==0&&ans[i]=='2'){no=1;return;}
		if(ans[i]!='2'){break;}
		else{
			ans[i]='0';ans[i-1]++;
		}
	}
}

void nmsl2(){
	cnm2=0;
	ll an=0;
	int z30=0,z=0;
	mp2.clear();
	for(i=0;i<k;i++){
		z+=-sb[i]+'1';
	}
	for(i=k-1;i>=(k-30);i--){
		cnm2<<=1;cnm2+=-sb[i]+'1';
		z30+=-sb[i]+'1';
	}
	if(z30==z){mp2[cnm2]=1;}
	for(i=k;i<n;i++){
		//cout<<z<<' '<<z30<<endl;
		cnm2<<=1;cnm2+=-sb[i]+'1';cnm2&=cnm;
		z-=-sb[i-k]+'1';
		z30-=-sb[i-30]+'1';
		if(z30==z){
			mp2[cnm2]=1;
		}
	}
	cout<<"YES"<<endl;
	while(mp2[an]){an++;}
	for(i=1;i<=k-30;i++){
		cout<<0;
	}
	for(i=29;i>=0;i--){
		cout<<((an&(1<<i))>0);
	}
	cout<<endl;
}

void nmsl(){
	tmp.clear();
		for(i=0;i<k;i++){
			tmp+='0'+('1'-sb[i]);
		}
		mp[tmp]=1;
		for(i=k;i<n;i++){
			tmp.erase(0,1);
			tmp+='0'+('1'-sb[i]);
			mp[tmp]=1;
		}
		while(!no){
			if(mp[ans]){
				add();
			}
			else{
				break;
			}
		} 
		if(no){cout<<"NO"<<endl;}
		else{
			cout<<"YES"<<endl;
			cout<<ans<<endl;
		}
}

int main(){
	cnm=(1ll<<30)-1;
	ios::sync_with_stdio(0);
	cin>>t;
	while(t--){
		mp.clear();
		cin>>n>>k;
		ans.clear();
		no=0;
		for(i=1;i<=k;i++){
			ans+="0";
		}
		cin>>sb;
		if(k<=30){
			nmsl();
		}
		else{
			nmsl2();
		}
	}
}