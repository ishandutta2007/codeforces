// Hydro submission #614c881961f7a6b8eadfa21f@1632406298665
#include <bits/stdc++.h>
#define bug(); cout << 1 << endl;
using namespace std;
typedef pair<int,int> pii;
inline int read(){
	int x=0;bool f=false;char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-')	f=true;
		ch=getchar();
	}
	while(isdigit(ch)){
		x=(x<<3)+(x<<1)+(ch^48);
		ch=getchar();
	}
	return f?-x:x;
}
int t,n;
int main(){
	t=read();
	while(t--){
		n=read();
		printf("%d\n",n>2?n-2:0);
	}
	return 0;
}