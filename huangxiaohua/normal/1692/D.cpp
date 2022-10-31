#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,f[6666];

int main(){
	ios::sync_with_stdio(0);
	for(i=0;i<1440;i++){
		int a,b,c,d;
		a=(i/60)/10;
		b=(i/60)%10;
		c=(i%60)/10;
		d=(i%60)%10;
		string s=to_string(a)+to_string(b)+":"+to_string(c)+to_string(d);
		string s2=s;
		reverse(s2.begin(),s2.end());
		f[i]=(s==s2);
	}
	cin>>t;
	while(t--){
		set<int> s;
		string sb;
		cin>>sb>>m;
		for(auto &i:sb)i-='0';
		n=(sb[0]*10+sb[1])*60+sb[3]*10+sb[4];
		for(i=0;i<=1441;i++){
			n+=m;n%=1440;
			if(f[n])s.insert(n);
		}
		cout<<s.size()<<endl;
	}
}