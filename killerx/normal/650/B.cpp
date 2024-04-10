#include<algorithm>
#include<bitset>
#include<cctype>
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<deque>
#include<iomanip>
#include<iostream>
#include<map>
#include<queue>
#include<set>
#include<string>
#include<vector>
#define ll long long
#define MP make_pair
#define PB push_back
using namespace std;
int read(){
	int x=0,f=1,c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')f=-f;
	for(; isdigit(c);c=getchar())x=x*10+c-48;
	return x*f;
}
const int N=1<<19;
int n,a,b,T;
char s[N+N];
int ans;
ll pre[N+N];
void solve(int st){
    pre[st]=0;
    for(int i=st+1;i<n+n;++i){
        pre[i]=pre[i-1]+1+(s[i]=='w')*b;
    }
    ll cur=0;
    for(int l=st;l>st-n;--l){
        cur+=1+(s[l]=='w')*b;
        if(l!=st)cur+=a+a;
        if(cur>T)break;
        int lb=st,rb=l+n-1;
        while(lb<rb){
            int md=(lb+rb+1)>>1;
            ll nw=cur+1LL*a*(md-st)+pre[md];
            if(nw<=T)lb=md;
            else rb=md-1;
        }
        ans=max(ans,lb-l+1);
    }
}
int main(){
    n=read(),a=read(),b=read(),T=read();
    scanf("%s",s);
    for(int i=n;i<n+n;++i)s[i]=s[i-n];
    solve(n);
    for(int i=0;i<n;++i)swap(s[i],s[n+n-1-i]);
    solve(n-1);
    printf("%d\n",ans);
	return 0;
}