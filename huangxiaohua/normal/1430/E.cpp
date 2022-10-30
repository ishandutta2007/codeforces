#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int i,j,k,n,m,t,f[200500],l,r;
priority_queue<int> q[666];
ll res;
char s[200500];
void add(int x){for(;x;x-=(-x&x)){f[x]++;}}
int get(int x,int y=0){for(;x<=n;x+=(-x&x)){y+=f[x];}return y;}
int main(){
	scanf("%d%s",&n,s+1);l=1;r=n;
	while(l<=r){swap(s[l],s[r]);l++;r--;}
	for(i=1;i<=n;i++){q[s[i]].push(-(n+1-i));}
	for(i=1;i<=n;i++){k=-q[s[i]].top();q[s[i]].pop();res+=get(k)+k-i;add(k);}
	printf("%lld",res);
}