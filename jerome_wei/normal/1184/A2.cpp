#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
char s[200010];
int n;
int t[200010];
int tpe[200010];

int main()
{
	cin >> n;
	scanf("%s",s);
	for(int i=0;i<n;i++)t[i]=s[i]-'0';
	for(int d=1;d<=n;d++)if(n%d==0){
		bool flag=1;
		for(int k=0;k<d;k++){
			int sum=0;
			for(int pos=k;pos<n;pos+=d){
				sum^=t[pos];
			}
			if(sum)flag=0;
		}
		tpe[d]=flag;
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		int g=__gcd(i,n);
		if(tpe[g])ans++;
	}
	cout << ans << endl;
}