#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,it0,cur,it,cur0,res;
string s0,ss;

struct sb{
	int mp[11],fail,f,g,no;
}ac0[20050],ac[20050];

queue<int> q;

void get0(int x){
	int tmp;
	if(!x){
		ac0[cur].no=1;
		return;
	}
	for(int i=1;i<=9;i++){
		if(i>x)return;
		tmp=cur;
		if(!ac0[cur].mp[i]){
			ac0[cur].mp[i]=++it0;
		}
		cur=ac0[cur].mp[i];
		ss+=(char)(i+'0');
		get0(x-i);
		ss.pop_back();
		cur=tmp;
	}
}

void get1(int x){
	int tmp,tmp0;
	if(ac0[cur0].no||ac[cur].no){
		return;
	}
	if(!x){
		ac[cur].no=1;
		return;
	}
	for(int i=2;i<=9;i++){
		if(i>x)return;
		tmp0=cur0;tmp=cur;
		if(!ac[cur].mp[i]){
			ac[cur].mp[i]=++it;
		}
		cur=ac[cur].mp[i];
		cur0=ac0[cur0].mp[i];
		ss+=(char)(i+'0');
		get1(x-i);
		ss.pop_back();
		cur=tmp;cur0=tmp0;
	}
}

int main() {
	cin>>s0>>n;
	if(n==1){
		for(auto i:s0)k+=(i=='1');
		cout<<k;return 0;
	}
	m=s0.size();
	for(i=1;i<n;i++){
		if(!(n%i)){
			get0(i);
		}
	}
	for(i=1;i<=9;i++){
		if(ac0[0].mp[i])q.push(ac0[0].mp[i]);
	}
	while(!q.empty()){
		k=q.front();q.pop();
		for(i=1;i<=9;i++){
			if(ac0[k].mp[i]){
				q.push(ac0[k].mp[i]);
				ac0[ac0[k].mp[i]].fail=ac0[ac0[k].fail].mp[i];
				if(ac0[ac0[ac0[k].fail].mp[i]].no){
					ac0[ac0[k].mp[i]].no=1;
				}
			}
			else{
				ac0[k].mp[i]=ac0[ac0[k].fail].mp[i];
			}
		}
	}
	cur=cur0=0;it=0;
	get1(n);
	for(i=1;i<=9;i++){
		if(ac[0].mp[i])q.push(ac[0].mp[i]);
	}
	while(!q.empty()){
		k=q.front();q.pop();
		for(i=1;i<=9;i++){
			if(ac[k].mp[i]){
				q.push(ac[k].mp[i]);
				ac[ac[k].mp[i]].fail=ac[ac[k].fail].mp[i];
				if(ac[ac[ac[k].fail].mp[i]].no){
					ac[ac[k].mp[i]].no=1;
				}
			}
			else{
				ac[k].mp[i]=ac[ac[k].fail].mp[i];
			}
		}
	}
	for(i=1;i<=it;i++){
		ac[i].f=ac[i].g=-114514;
	}
	for(auto i:s0){
		i-='0';
		for(j=0;j<=it;j++){
			if(ac[j].no)continue;
			k=ac[j].mp[i];
			if(ac[k].no)continue;
			ac[j].g=max(ac[j].g,ac[j].f);
			ac[k].g=max(ac[k].g,ac[j].f+1);
		}
		for(j=0;j<=it;j++){
			ac[j].f=max(ac[j].g,ac[j].f);
			res=max(res,ac[j].f);
		}
	}
	cout<<m-res;
}