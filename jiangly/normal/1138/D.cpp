#include<bits/stdc++.h>
using std::string;
using std::cin;
using std::cout;
const int N=500000;
int cnts[2],cntt[2],cntsuffix[2],next[N];
string s,t;
int main(){
	cin>>s>>t;
	for(int i=0;i<s.length();++i){
		++cnts[s[i]-'0'];
	}
	for(int i=0;i<t.length();++i){
		++cntt[t[i]-'0'];
	}
	next[0]=-1;
	for(int i=1,j=-1;i<t.length();++i){
		while(j!=-1&&t[i]!=t[j+1]){
			j=next[j];
		}
		if(t[i]==t[j+1]){
			++j;
		}
		next[i]=j;
	}
	for(int i=next[t.length()-1]+1;i<t.length();++i){
		++cntsuffix[t[i]-'0'];
	}
	if(cnts[0]>=cntt[0]&&cnts[1]>=cntt[1]){
		cout<<t;
		cnts[0]-=cntt[0];
		cnts[1]-=cntt[1];
		while(cnts[0]>=cntsuffix[0]&&cnts[1]>=cntsuffix[1]){
			for(int i=next[t.length()-1]+1;i<t.length();++i){
				putchar(t[i]);
			}
			cnts[0]-=cntsuffix[0];
			cnts[1]-=cntsuffix[1];
		}
	}
	for(int i=0;i<cnts[0];++i){
		putchar('0');
	}
	for(int i=0;i<cnts[1];++i){
		putchar('1');
	}
	return 0;
}