#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define INF INT_MAX/2
#define int long long
#define mp make_pair
#define f first
#define s second
#define pii pair<int,int>
#define C 1000000000

pii trans(int i){
	if(i<=C)return mp(0,C-i);
	i-=C;
	return mp(i,0);
}

string pt(int i){
	cout<<trans(i).f<<" "<<trans(i).s<<endl;
	string s;
	cin>>s;
	return s;
}


int32_t main(){
	//ios::sync_with_stdio(false);
	//cin.tie(NULL);
	
	int n;
	cin>>n;

	int mini=0;
	int maxi=2000000000;

	string fst=pt(0);
	mini++;

	int maxf=0;
	int minl=2000000000;


	for(int i=1;i<n;i++){
		int mid=(mini+maxi)>>1;
		string at=pt(mid);
		if(at==fst){
			mini=mid+1;
			maxf=mid;
		}
		else{
			maxi=mid-1;
			minl=mid;
		}
	}

	cout<<trans(maxf+1).f<<" "<<trans(maxf+1).s<<" ";
	cout<<C<<" "<<C<<endl;


}