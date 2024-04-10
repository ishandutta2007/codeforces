#include<bits/stdc++.h>
#define pii pair<int,int>
#define ll long long
#define fi first
#define se second
#define eb emplace_back
using namespace std;
const int M=100009;
int n,q;
int la[M];
char s[M];
string t,pt;
vector<pair<int,string>>ans;
string get(){
	pt.clear();
	if(t.length()>10){
		for(int i=t.length()-1;i>=t.length()-5;--i)pt.push_back(t[i]);
		pt=pt+"...";
		pt.push_back(t[1]);
		pt.push_back(t[0]);
	}
	else {
		pt=t;
		reverse(pt.begin(),pt.end());
	}
	return pt;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>(s+1);
	n=strlen(s+1);
	t.push_back(s[n]);
	ans.eb(1,t);
	int b=1;
	for(int i=n-1;i>=1;--i){
		if(s[i]==t.back()&&b){
			if(la[i+1]>s[i]){
				la[i]=la[i+1];
				t.push_back(s[i]);
				ans.eb(t.length(),get());
				b=1;
			}
			else {
				t.pop_back();
				la[i]=la[i+2];
				ans.eb(t.length(),get());
				b=0;
			}
		}
		else {
			b=1;
			if(s[i]==t.back())la[i]=la[i+1];
			else la[i]=t.back();
			t.push_back(s[i]);
			ans.eb(t.length(),get());
		}
	}
	reverse(ans.begin(),ans.end());
	for(auto o:ans){
		cout<<o.fi<<" "<<o.se<<"\n";
	}
	return 0;
}