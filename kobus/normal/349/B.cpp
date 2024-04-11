#include <bits/stdc++.h>
 
using namespace std;
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define int long long
typedef long long ll;
typedef pair<int,int> pii;
typedef long double ld;
#define MAXN 512345
#define INF INT_MAX/2
#define MOD 1000000007

int v[10];



int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.precision(11);
  	cout.setf(ios::fixed);

  	int n;
  	cin>>n;

  	for(int i=1;i<10;i++)cin>>v[i];

  	string s;
  	int lenmax=0;
  	int num;

  	for(int i=1;i<10;i++){
  		if(n/v[i]>lenmax){
  			lenmax=n/v[i];
  			num=i;
  		}
  	}

  	if(lenmax==0){
  		cout<<-1<<endl;
  		return 0;
  	}

  	for(int i=0;i<lenmax;i++){
  		s+=(char)(num+'0');
  		n-=v[num];
  	}
  	int place=0;
  	bool stop=false;
  	bool changed=false;

  	while(!stop){
  		changed=false;
  		for(int i=9;i>num;i--){
  			if(n-v[i]+v[num]>=0){
  				s[place]=(char)(i+'0');
  				n+=v[num];
  				n-=v[i];
  				place++;
  				changed=true;
  				break;
  			}
  		}
  		if(!changed || place==lenmax)stop=true;
  	}

  	cout<<s<<endl;



}