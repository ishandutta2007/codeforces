#include <bits/stdc++.h>
 
using namespace std;
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define int long long
typedef long long ll;
typedef pair<int,int>pii;
#define MAXN 1123456
#define INF LLONG_MAX/4
#define MOD 1000000007

bool rev(pii a,pii b){
	return a>b;
}

pii v[112345];

int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n,s;
	cin>>n>>s;

	int htot=0;
	int stot=0;
	for(int i=0;i<n;i++){
		int a,b,c;
		cin>>a>>b>>c;
		htot+=a*b;
		stot+=a;
		v[i].f=c-b;
		v[i].s=a;
	}
	int pnum=ceil(1.*stot/s);
	v[n].f=0;v[n].s=(pnum*s)-stot;
	n++;
	sort(v,v+n,rev);
	int mark=0;
	int fmark=0;

	for(int i=0;i<n;i++){
		if(v[i].s+mark<s){
			mark+=v[i].s;
			fmark+=v[i].s*v[i].f;
		}
		else if(v[i].s+mark==s){
			fmark+=v[i].s*v[i].f;
			if(fmark>0)htot+=fmark;
			fmark=0;
			mark=0;
		}
		else{
			fmark+=(s-mark)*v[i].f;
			if(fmark>0)htot+=fmark;
			v[i].s-=(s-mark);
			int num=v[i].s/s;
			if(v[i].f>0)htot+=(num*s*v[i].f);
			mark=v[i].s-(v[i].s/s)*s;
			fmark=mark*v[i].f;
		}
	}

	cout<<htot<<endl;


	return 0;
}