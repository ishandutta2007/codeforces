#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define b(x) (1<<((x)-1))
int i,j,k,n,m,t;
vector<int> v1={1,6,8,15},v2={0,1,2,4,5,8,9,10};

int ask(vector<int> v){
	string s;
	cout<<"? "<<v.size()<<" ";
	for(auto i:v){
		cout<<i<<' ';
	}
	cout<<endl;
	cin>>s;
	if(s=="YES")return 1;
	return 0;
}

void fuck(vector<int> vt,vector<int> vf){
	vector<int> v0,v[4],q1,q2,q;
	int i,j,k;
	v0=vt;
	v0.insert(v0.end(),vf.begin(),vf.end());
	
	k=0;
	if(v0.size()==2){
		int l=v0[0],r=v0[1];
		cout<<"! "<<l<<endl;
		string s;
		cin>>s;
		if(s==":)")return;
		cout<<"! "<<r<<endl;
		return;
	}
	
	if(vf.empty()){
		for(auto i:v0){
			v[k].push_back(i);
			k=(k+1)%4;
		}
		
		k=0;
		for(i=1;i<=4;i++){
			q.clear();
			for(j=0;j<=3;j++){
				if(v1[j]&b(i)){
					q.insert(q.end(),v[j].begin(),v[j].end());
				}
			}
			if(ask(q))k|=b(i);
		}
		
		q.clear();
		for(i=0;i<4;i++){
			for(auto j:v2){
				if((v1[i]^j)==k){
					//printf("NMSL%d %d %d %d\n",i,j,k,v[i][0]);
					for(auto l:v[i]){
						if(j&8)q2.push_back(l);
						else q1.push_back(l);
					}
				}
			}
		}
		
		fuck(q1,q2);
	}
	else{
		k=0;
		for(auto i:vf){
			v[k].push_back(i);
			k^=3;
		}
		k=1;
		for(auto i:vt){
			v[k].push_back(i);
			k=k%2+1;
		}
		
		k=0;
		for(i=1;i<=4;i++){
			q.clear();
			for(j=0;j<=3;j++){
				if(v1[j]&b(i)){
					q.insert(q.end(),v[j].begin(),v[j].end());
				}
			}
			if(ask(q))k|=b(i);
			else if(i==1){
				fuck(vt,vector<int>(0,0));
				exit(1);
				return;
			}
		}
		
		q.clear();
		for(i=0;i<4;i++){
			for(auto j:v2){
				if((v1[i]^j)==k){
					//printf("NMSL%d %d %d %d\n",i,j,k,v[i][0]);
					for(auto l:v[i]){
						if(j&8)q2.push_back(l);
						else q1.push_back(l);
					}
				}
			}
		}
		
		fuck(q1,q2);
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin>>n;
	if(n==1){
		cout<<"! 1"<<endl;return 0;
	}
	vector<int> vt,vf;
	for(i=1;i<=n;i++)vt.push_back(i);
	fuck(vt,vf);
}