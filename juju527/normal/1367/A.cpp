#include<bits/stdc++.h>
using namespace std;
int read(){
	int x=0,y=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')y=-1;ch=getchar();}
	while(ch>='0'&&ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	return x*y;
}
int main(){
	int t;
	t=read();
	while(t--){
		string a="",b;
		cin>>b;
		for(int i=0;i<b.size();i+=2)a+=b[i];
		a+=b[b.size()-1];
		cout<<a<<endl;
	}
	return 0;
}