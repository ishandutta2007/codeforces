#include<bits/stdc++.h>
#define fi first
#define se second
#define pii pair<int,int>
#define ll __int128_t
#define eb emplace_back
using namespace std;
const int mod1=998244353;
const int mod2=1e9+7;
const int M=2e5+9;
struct Hash{
    int x1,x2;
    Hash(int t1=0,int t2=0):x1(t1),x2(t2){}
    bool operator != (const Hash&o)const{return x1!=o.x1||x2!=o.x2;}
    bool operator == (const Hash&o)const{return x1==o.x1&&x2==o.x2;}
    bool operator <  (const Hash&o)const{return x1==o.x1?x2<o.x2:x1<o.x1;}
    Hash operator +  (const Hash&o)const{return Hash((x1+o.x1)%mod1,(x2+o.x2)%mod2);}
    Hash operator -  (const Hash&o)const{return Hash((x1-o.x1+mod1)%mod1,(x2-o.x2+mod2)%mod2);}
    Hash operator +  (const int&o)const{return Hash((x1+o)%mod1,(x2+o)%mod2);}
    Hash operator -  (const int&o)const{return Hash((x1+mod1-o)%mod1,(x2+mod2-o)%mod2);}
    Hash operator *  (const int&o)const{return Hash(1ll*x1*o%mod1,1ll*x2*o%mod2);}
    Hash operator *  (const Hash&o)const{return Hash(1ll*x1*o.x1%mod1,1ll*x2*o.x2%mod2);}
}pw[M];
int main(){
	int n,k;
	cin>>n>>k;
	pw[0]=Hash(1,1);
	for(int i=1;i<=n;++i)pw[i]=pw[i-1]*k;
	Hash x=Hash(0,0);
	int num=0,pp=0;
	bool bol=0;
	for(int i=0;i<=n;++i){
		string s;
		cin>>s;
		if(s=="?"){
			if(i==0)bol=1;
			num++;
			continue;
		}
		int rex=0,f=1;
		if(s[0]=='-')f=-1;
		for(auto o:s){
			if(o=='-')f=-1;
			else rex=rex*10+o-'0';
		}
		rex=rex*f;
		x=x+pw[i]*rex;
		if(i==0)pp=rex;
	}
	if(num){
		if(k){
			if(n%2==1)puts("Yes");
			else puts("No");
		}
		else{
			if(bol){
				if((n+1-num)%2==0)puts("No");
				else puts("Yes");
			}
			else{
				if(pp)puts("No");
				else puts("Yes");
			}
		}
	}
	else{
		if(x==Hash(0,0))puts("Yes");
		else puts("No");
	}
	return 0;
}