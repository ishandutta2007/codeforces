//Code by juju527.
#include<bits/stdc++.h>
typedef long long ll;
#define pii pair<int,int>
#define fi first
#define se second
#define mp make_pair
#define vec vector<int>
#define eb emplace_back
using namespace std;
const int maxn=2e5+5;
char s[maxn];
int read(){
    int x=0,y=1;
    char ch=getchar();
    while(ch<48||ch>57){if(ch==45)y=-1;ch=getchar();}
    while(ch>=48&&ch<=57)x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
    return x*y;
}
int cnt[10];
set<pii> t;
priority_queue<int> q;
int main(){
    int T;
	T=read();
	while(T--){
		int n;
		scanf("%s",s+1);n=strlen(s+1);
		for(int i=1;i<=n;i++)t.insert(pii(s[i]-'0',i));
		int p=0,num=n;
		while(num--){
			int v1=t.size()?(*t.begin()).fi:10,v2=(q.size())?-q.top():10;
			if(v1<=v2){
				int nxt=(*t.begin()).se;
				for(int j=p+1;j<nxt;j++)t.erase(pii(s[j]-'0',j)),q.push(max('0'-s[j]-1,-9));
				p=nxt;t.erase(pii(s[p]-'0',p));
				printf("%d",v1);
			}
			else{
				q.pop();
				printf("%d",v2);
			}
		}
		puts("");
	}
    return 0;
}