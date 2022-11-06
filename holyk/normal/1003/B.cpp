#include<bits/stdc++.h>
#define REP(i,a,b) for(int i=(a);i<=(b);++i)
#define DEC(i,a,b) for(int i=(a);i>=(b);--i)
#define dbg(...) fprintf(stderr,__VA_ARGS__)
using namespace std;
template<typename T,typename U> inline bool smax(T&x,const U&y){return y>x?(x=y,1):0;}
template<typename T,typename U> inline bool smin(T&x,const U&y){return y<x?(x=y,1):0;}
typedef long long ll;
typedef pair<int,int> pii;
#define pb push_back
#define X first
#define Y second
inline int read(){
    int w=0,p=0;char c;
    while(!isdigit(c=getchar()))if(c=='-')p=1;
    while(isdigit(c))w=(w<<1)+(w<<3)+(c^'0'),c=getchar();
    return p?-w:w;
}
string s;
int main(){
	int a,b,c;
	cin>>a>>b>>c;
	int now=b>a;
	REP(i,0,c)s+=(char)(now+'0'),(now?--b:--a),now^=1;
	if(s[0]=='0'){
		REP(i,1,a)s='0'+s;
		if(*s.rbegin()=='0'){
			if(b){
				*s.rbegin()='1';
				REP(i,2,b)s+='1';
				s+='0';
			}
		}
		else while(b--)s+='1';
	}
	else {
		REP(i,1,b)s='1'+s;
		if(*s.rbegin()=='1'){
			if(a){
				*s.rbegin()='0';
				REP(i,2,a)s+='0';
				s+='1';
			}
		}
		else while(a--)s+='0';
	}
	
	cout<<s;
	return 0;
}