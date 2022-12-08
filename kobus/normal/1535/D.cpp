#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MAXN = 1123;
#define mp make_pair
#define f first
#define s second

bool menor(int a,int b){
	if(a%2==0 && b%2==1)return 1;
	return 0;
}

int gcd(int a,int b){
	return b==0?a:gcd(b,a%b);
}

int32_t main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	int n;
	cin>>n;
	n=(1<<n)-1;
	//cout<<n<<endl;
	string s;
	cin>>s;
	reverse(s.begin(),s.end());
	vector<int> v(n);
	for(int i=n-1;i>=0;i--){
		if(i>=n/2){
			if(s[i]=='?')v[i]=2;
			else v[i]=1;
		}
		else{
			if(s[i]=='?')v[i]=v[2*i+1]+v[2*i+2];
			else if(s[i]=='0')v[i]=v[2*i+2];
			else v[i]=v[2*i+1];
		}
		//cout<<i<<" "<<v[i]<<endl;
	}
	//for(int i=0;i<n;i++)cout<<v[i]<<" ";
	//cout<<endl;
	int q;
	cin>>q;
	while(q--){
		int a;
		char c;
		cin>>a>>c;
		a--;
		a=(n-1)-a;
		s[a]=c;
		for(int i=a;i>=0;i=(i-1)/2){
			if(i>=n/2){
				if(s[i]=='?')v[i]=2;
				else v[i]=1;
			}
			else{
				if(s[i]=='?')v[i]=v[2*i+1]+v[2*i+2];
				else if(s[i]=='0')v[i]=v[2*i+2];
				else v[i]=v[2*i+1];
			}
			if(i==0)break;
		}
		cout<<v[0]<<endl;
	}
}