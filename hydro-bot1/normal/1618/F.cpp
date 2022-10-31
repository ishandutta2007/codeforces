// Hydro submission #6357d94a63ef0fee598a4bd4@1666701642941
#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll x,y;
string s1="",s2="",s3="",s4="",q;
bool ans=0;
string bin(ll x){
    ll k=x;
    string res="";
    while(k){
        if(k&1)res+="1";
        else res+="0";
        k>>=1;
    }
    reverse(res.begin(),res.end());
    return res;
}
void solve(string s){
    int len=s.size(),lenq=q.size();
    for(int i=0;i<lenq-len+1;i++){
        if(q.substr(i,len)!=s)continue;
        bool flag=1;
        for(int j=0;j<i;j++)
			if(q[j]=='0')flag=0;
		for(int j=lenq-1;j>i+len-1;j--)
			if(q[j]=='0')flag=0;
		ans|=flag;
	}
}
int main(){
    cin>>x>>y;
    if(x==y)ans=1;
    s1=bin(x)+"1";
    s2=s1;reverse(s2.begin(),s2.end());
    while(!(x&1))x>>=1;
    s3=bin(x);
    s4=s3;reverse(s4.begin(),s4.end());
    q=bin(y);
    solve(s1);solve(s2);solve(s3);solve(s4);
    if(ans)cout<<"YES";
    else cout<<"NO";
    return 0;
}