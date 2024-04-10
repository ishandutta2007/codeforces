#include <bits/stdc++.h>
#define ll long long
#define Mid ((L+R)>>1)
using namespace std;
typedef pair<int,int> pii;
inline int read(){
	char c;int x=0;int b=1;do{c=getchar();if(c==45)b=-1;}while(c>57||c<48);
	do x=x*10+c-48,c=getchar();while(c<=57&&c>=48);x*=b;return x;
}
int i,j,k,n,m,Q[200010],top;
int main() {
	int T=read();
	while(T--){
		string S;cin>>S;top=0;
		for(i=0;i<S.size();i++){
			Q[++top]=S[i];
			if(top>=2 && Q[top]=='B' && Q[top-1]=='A')top-=2;
			if(top>=2 && Q[top]=='B' && Q[top-1]=='B')top-=2;
		}printf("%d\n",top);
	}
	//cerr << 1.0*clock()/CLOCKS_PER_SEC << endl;
	return 0;
}