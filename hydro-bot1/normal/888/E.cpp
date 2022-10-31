// Hydro submission #62c6d491c3a9fda5622b1d6a@1657197714002
#include<bits/stdc++.h>
using namespace std;
int a[36];
vector<long long> use;
int A;
long long usemag=0;
int n,m;
int answer=0;

void mag(int step){
	if(step==A){
		use.push_back(usemag%m);
		use.push_back((usemag+a[step])%m);
	}else{
		usemag+=a[step];
		mag(step+1);
		usemag-=a[step];
		mag(step+1);
	}
	return;
}

void mag2(int step){
	if(step==n){
		if(lower_bound(use.begin(),use.end(),m-((usemag)%m))!=use.end()){
			if(answer<*(--lower_bound(use.begin(),use.end(),m-((usemag)%m)))+usemag%m){
				answer=*(--lower_bound(use.begin(),use.end(),m-((usemag)%m)))+usemag%m;
			}
		}else{
			if(answer<(use[use.size()-1]+usemag)%m){
				answer=(use[use.size()-1]+usemag)%m;
			}
		}
		if(lower_bound(use.begin(),use.end(),m-((usemag+a[step])%m))!=use.end()){
			if(answer<*(--lower_bound(use.begin(),use.end(),m-((usemag+a[step])%m)))+(usemag+a[step])%m){
				answer=*(--lower_bound(use.begin(),use.end(),m-((usemag+a[step])%m)))+(usemag+a[step])%m;
			}
		}else{
			if(answer<(use[use.size()-1]+usemag+a[step])%m){
				answer=(use[use.size()-1]+usemag+a[step])%m;
			}
		}
	}else{
		usemag+=a[step];
		mag2(step+1);
		usemag-=a[step];
		mag2(step+1);
	}
	return;
}


int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==1){
		cout<<a[1]%m;
		return 0;
	}
	A=n/2;
	mag(1);
	sort(use.begin(),use.end());
	usemag=0;
	
	mag2(A+1);
	cout<<answer;
	return 0;
}