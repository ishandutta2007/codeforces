#include<bits/stdc++.h>
#define rep(i,a,n) for(int i=(a);i<=(n);i++)
#define per(i,a,n) for(int i=(n);i>=(a);i--)

#define pb push_back
#define mp make_pair
#define xx first
#define yy second
#define INF 0x3f3f3f3f

using namespace std;
typedef long long ll;
typedef double db;
typedef pair<int,int> PII;
typedef vector<int> VI;

const int maxn=200000;
//head

char s[maxn+5];
int cnt[maxn+5][26];

int main()
{
	scanf("%s",s+1);
	int n=strlen(s+1);
	rep(i,1,n) rep(j,0,25) cnt[i][j]=cnt[i-1][j]+(s[i]=='a'+j);
	int Q; scanf("%d",&Q);
	while(Q--)
	{
		int l,r; scanf("%d%d",&l,&r);
		if(l==r || s[l]!=s[r]) puts("Yes");
		else
		{
			int CC=0;
			rep(j,0,25) CC+=(cnt[r][j]-cnt[l-1][j]>0);
			puts(CC>=3?"Yes":"No");
		}
		
	}
    return 0;
}