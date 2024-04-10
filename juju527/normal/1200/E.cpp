#include <bits/stdc++.h>
using namespace std;
const int maxn=1e5+5,maxl=1e6+100;
string s,t;
int nxt[maxl];
int read(){
    int x=0,y=1;
    char ch=getchar();
    while(ch<48||ch>57){if(ch==45)y=-1;ch=getchar();}
    while(ch>=48&&ch<=57)x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
    return x*y;
}
void pre(string ss){
	int i=0,j=-1;
	nxt[i]=-1;
	while(i<ss.size()){
		if(j==-1||ss[i]==ss[j]){
			i++;
			j++;
			nxt[i]=j;
		}
		else
			j=nxt[j];
	}
	return ;
}
int main(){
//    freopen("CF1200ECompressWords.in","r",stdin);
//    freopen("CF1200ECompressWords.out","w",stdout);
   	int n;
	n=read();
	cin>>s;
	string qaq="HZRtql,suibiandiaodawo,yingyingying~~~";
	for(int i=2;i<=n;i++){
		cin>>t;
		string ss=t+qaq+s.substr(s.size()-min(s.size(),t.size()));
		pre(ss);
		for(int j=nxt[ss.size()];j<t.size();j++)s+=t[j];
	}
	cout<<s<<endl;
	return 0;
}