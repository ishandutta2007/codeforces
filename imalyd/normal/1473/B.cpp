#include<bits/stdc++.h>
using namespace std;
#define ERR(...) fprintf(stderr,__VA_ARGS__);
#define rep(i,l,r) for(i=(l);i<=(r);++i)
#define per(i,l,r) for(i=(l);i>=(r);--i)
#define REP(i,l,r) for(i=(l);i< (r);++i)
#define PER(i,l,r) for(i=(l);i> (r);--i)
typedef long long ll;
//const int MAXN=;
inline string operator*(string a,int b){
	string c;
	while(b--)c+=a;
	return c;
}
inline bool ok(string a,string b){
	return a==b*(a.length()/b.length());
}
inline void ac(){
	string a,b;
	cin>>a>>b;
	if(a.length()>b.length())swap(a,b);
	int i;
	per(i,a.length(),1){
		string c=a.substr(0,i);
		if(ok(a,c)&&ok(b,c)){
			cout<<c*(a.length()/i)*(b.length()/i)<<"\n";
			return;
		}
	}
	cout<<"-1\n";
}
int main(){
	//freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
	int t;
	scanf("%d",&t);
	while(t--)ac();
	return 0;
}