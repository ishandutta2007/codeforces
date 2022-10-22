#include<bits/stdc++.h>
using namespace std;
string s,t; int n,m,tot[10],pw[10];
string ans1;
string solve1(){
	if (t[0]=='0') return "x";
	string res=t;
	for (int i=0;i<=9;i++) res.resize(res.length()+tot[i],char(i+'0'));
	return res;
}
string solve2(){
	int pos=0;
	for (int i=1;i<=9;i++)
		if (tot[i]){ pos=i; break;}
	if (!pos) return "x";

	tot[pos]--;
	string res1; res1.clear(); res1+=char(pos+'0');
	for (int i=0;i<=9;i++){
		if (i==t[0]-'0') res1+=t;
		res1.resize(res1.length()+tot[i],char(i+'0'));
	}
	string res2; res2.clear(); res2+=char(pos+'0');
	for (int i=0;i<=9;i++){
		res2.resize(res2.length()+tot[i],char(i+'0'));
		if (i==t[0]-'0') res2+=t;
	}
	tot[pos]++;
	return min(res1,res2);
}
int main(){
	pw[0]=1; for (int i=1;i<=9;i++) pw[i]=pw[i-1]*10;
	cin>>s>>t; n=s.length(); m=t.length();
	for (int i=0;i<n;i++) tot[s[i]-'0']++;
	if (n==2&&tot[0]==1&&tot[1]==1){
		puts("0");
		return 0;
	}
	int tmp=0;
	for (int i=1;i<=9;i++)
		if (pw[i-1]+i<=n&&n<=pw[i]-1+i){
			tmp=i;
			break;
		}
	int len=n-tmp;
	for (int i=0;i<tmp;i++) tot[len/pw[i]%10]--;
	for (int i=0;i<m;i++) tot[t[i]-'0']--;
	cout<<min(solve1(),solve2())<<endl;
	return 0;
}